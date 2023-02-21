#pragma once
#include "../DG_Widget.h"
#include "../Interfaces/DG_SingletonWidgetInterface.h"
#include "DG_HudWidget.generated.h"

UCLASS()
class UILIBRARY_API UDG_HudWidget
    : public UDG_Widget
    , public IDG_SingletonWidgetInterface
{
    GENERATED_BODY()

public:
    UDG_HudWidget(const FObjectInitializer& ObjectInitializer);

    // Begin SingletonWidget Interface
    virtual FName GetWidgetName() const { return FName(TEXT("Hud")); }
    virtual TMap<FName, UDG_Widget*> GetChildSingletonWidgets() const { return TMap<FName, UDG_Widget*>(); }
    // End SingletonWidget Interface
};
