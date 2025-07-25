// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_InvestigationScannedObjectBase.generated.h"


class UInvestigationComponentNPC;
/**
 * 
 */
UCLASS()
class PHANTOMTRACE_API UW_InvestigationScannedObjectBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Investigation")
	void SetInvestigationData(UInvestigationComponentNPC* InvestigationComponent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Investigation")
	void FadeOutInvestigationData();
};
