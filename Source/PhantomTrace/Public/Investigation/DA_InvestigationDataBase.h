// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "W_InvestigationScannedObjectBase.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DA_InvestigationDataBase.generated.h"


/**
 * 
 */
UCLASS()
class PHANTOMTRACE_API UDA_InvestigationDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Investigation")
	FGameplayTag WidgetTag_Recognition;
};
