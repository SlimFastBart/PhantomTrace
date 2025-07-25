// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InvestigationDataTypes.h"
#include "Investigation/DA_InvestigationDataBase.h"
#include "DA_PersonInvestigationData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PHANTOMTRACE_API UDA_PersonInvestigationData : public UDA_InvestigationDataBase
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Investigation")
	FInvestigationStruct InvestigationData;
	
};
