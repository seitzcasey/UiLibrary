// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DG_SingletonWidgetInterface.generated.h"

class UDG_Widget;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDG_SingletonWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UILIBRARY_API IDG_SingletonWidgetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FName GetWidgetName() const PURE_VIRTUAL(IDG_SingletonWidgetInterface::GetWidgetName, return NAME_None;);

	virtual TMap<FName, UDG_Widget*> GetChildSingletonWidgets() const PURE_VIRTUAL(IDG_SingletonWidgetInterface::GetChildSingletonWidgets, return TMap<FName, UDG_Widget*>();)
};
