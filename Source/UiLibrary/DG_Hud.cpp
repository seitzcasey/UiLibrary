#include "DG_Hud.h"
#include <UMG/Public/Blueprint/WidgetBlueprintLibrary.h>
#include "Widgets/Interfaces/DG_SingletonWidgetInterface.h"
#include "Widgets/DG_Widget.h"

ADG_Hud::ADG_Hud()
    : Super()
{

}

void ADG_Hud::PushWidget(const FName WidgetName)
{
    GetNamedWidgetChecked(WidgetName).SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void ADG_Hud::PopWidget(const FName WidgetName)
{
    GetNamedWidgetChecked(WidgetName).SetVisibility(ESlateVisibility::Collapsed);
}

void ADG_Hud::BeginPlay()
{
    Super::BeginPlay();

    for (auto WidgetClass : WidgetClasses)
    {
        if (auto Widget = CreateWidget<UDG_Widget>(GetOwningPlayerController(), WidgetClass.Get()))
        {
            Widget->AddToViewport();

            if (auto SingletonWidget = Cast<IDG_SingletonWidgetInterface>(Widget))
            {
                SingletonWidgets.Add(SingletonWidget->GetWidgetName(), Widget);
                SingletonWidgets.Append(SingletonWidget->GetChildSingletonWidgets());
            }
        }
    }
}

