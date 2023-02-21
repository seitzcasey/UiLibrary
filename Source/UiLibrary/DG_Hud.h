#pragma once
#include "GameFramework/HUD.h"
#include "DG_Hud.generated.h"

class UDG_Widget;

UCLASS()
class ADG_Hud : public AHUD
{
    GENERATED_BODY()

public:
    ADG_Hud();

    template<typename T = UDG_Widget>
    T* GetNamedWidget(const FName WidgetName) const;

    template<typename T = UDG_Widget>
    T& GetNamedWidgetChecked(const FName WidgetName) const;

    void PushWidget(const FName WidgetName);

    void PopWidget(const FName WidgetName);

protected:
    // Begin Actor Interface
    virtual void BeginPlay() override;
    // End Actor Interface

protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<TSoftClassPtr<UDG_Widget>> WidgetClasses;

    TMap<FName, UDG_Widget*> SingletonWidgets;
};

template<typename T>
T* ADG_Hud::GetNamedWidget(const FName WidgetName) const
{
    if (auto const* Widget = SingletonWidgets.Find(WidgetName))
    {
        return Cast<T>(*Widget);
    }
    return nullptr;
}

template<typename T>
T& ADG_Hud::GetNamedWidgetChecked(const FName WidgetName) const
{
    T* Widget = GetNamedWidget<T>(WidgetName);
    check(Widget);
    return *Widget;
}
