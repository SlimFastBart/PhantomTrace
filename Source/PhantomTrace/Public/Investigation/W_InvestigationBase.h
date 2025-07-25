// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InvestigationComponentNPC.h"
#include "W_InvestigationBase.generated.h"

class UBorder;
class UDA_InvestigationDataBase;
/**
 * 
 */
UCLASS()
class PHANTOMTRACE_API UW_InvestigationBase : public UUserWidget
{
	GENERATED_BODY()


	public:
	//UPROPERTY(meta = (BindWidget))
	//UBorder* MyContentWidget;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Investigation")
	void OnSetInvestigationData(UInvestigationComponentNPC* InvestigationComponent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Investigation")
	void HideInvestigationDataPanel();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Investigation")
	bool ChangeInvestigationVisibility(bool bVisible);
};
