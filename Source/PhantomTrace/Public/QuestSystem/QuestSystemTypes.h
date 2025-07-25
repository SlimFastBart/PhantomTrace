// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestSystemTypes.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FQuestObjective : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ObjectiveText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMainObjective;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine = "true"))
	FText Info;
};

USTRUCT(BlueprintType)
struct FQuestObjectiveData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FName RowName = NAME_None;

	UPROPERTY(BlueprintReadOnly)
	bool bActive = false;

	UPROPERTY(BlueprintReadOnly)
	bool bTracked = false;

	UPROPERTY(BlueprintReadOnly)
	bool bCompleted	= false;

	UPROPERTY(BlueprintReadOnly)
	bool bSuccess = false;
	
};
UCLASS()
class PHANTOMTRACE_API UQuestSystemTypes : public UObject
{
	GENERATED_BODY()
};
