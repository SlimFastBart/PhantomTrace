// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Investigation/DA_InvestigationDataBase.h"
#include "InvestigationDataTypes.h"
#include "DA_ObjectInvestigationData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PHANTOMTRACE_API UDA_ObjectInvestigationData : public UDA_InvestigationDataBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Investigation")
	EItemRarity Rarity = EItemRarity::Rare;
};
