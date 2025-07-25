// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_QuestScenarioBase.generated.h"

/**
 * 
 */
UCLASS()
class PHANTOMTRACE_API UDA_QuestScenarioBase : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText QuestName;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText QuestDescription;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool bMainQuest = true;
	
};
