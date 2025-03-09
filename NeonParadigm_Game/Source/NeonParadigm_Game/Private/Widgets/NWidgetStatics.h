// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NWidgetStatics.generated.h"

/**
 * 
 */
UCLASS()
class UNWidgetStatics : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Widget")
	static TArray<class UWidget*> GetAllChildrenInTree(class UPanelWidget* Parent);
};
