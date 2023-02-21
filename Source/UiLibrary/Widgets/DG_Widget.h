#pragma once
#include "UMG/Public/Blueprint/UserWidget.h"
#include "DG_Widget.generated.h"

UCLASS(Abstract)
class UILIBRARY_API UDG_Widget : public UUserWidget
{
    GENERATED_BODY()

public:
    UDG_Widget(const FObjectInitializer& ObjectInitializer);
};