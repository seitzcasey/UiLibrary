#pragma once
#include "../DG_Widget.h"
#include "../Interfaces/DG_SingletonWidgetInterface.h"
#include "DG_MainMenuWidget.generated.h"

UCLASS()
class UILIBRARY_API UDG_MainMenuWidget
    : public UDG_Widget
    , public IDG_SingletonWidgetInterface
{
    GENERATED_BODY()

public:
    UDG_MainMenuWidget(const FObjectInitializer& ObjectInitializer);

    // Begin SingletonWidget Interface
    virtual FName GetWidgetName() const { return FName(TEXT("MainMenu")); }
    virtual TMap<FName, UDG_Widget*> GetChildSingletonWidgets() const { return TMap<FName, UDG_Widget*>(); }
    // End SingletonWidget Interface
};
