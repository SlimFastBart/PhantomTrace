// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Internationalization/Text.h"     
#include "UObject/ObjectMacros.h"          

#include "InvestigationDataTypes.generated.h" 
/**
 * 
 */
USTRUCT(BlueprintType)
struct PHANTOMTRACE_API FInvestigationStruct
{
	GENERATED_BODY()

public:
	// Indicates if there is an association
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	bool bHasAssociation = false;

	// Name of the association
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	FText Association;

	// Indicates if there is a bounty
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	bool bHasBounty = false;

	// Amount of the bounty (only editable if bHasBounty is true)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation", meta=(EditCondition="bHasBounty", EditConditionHides, ClampMin="0"))
	int32 Bounty = 0;

	// Name of the leader
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	FText LeaderName;

	// Main activities description
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	TArray<FText> MainActivities;

	// Territory information
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	FText Territory;

	// Number of members
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	int32 MemberCount = 0;

	// Threat level (0-5)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation", meta=(ClampMin="0", ClampMax="5"))
	int32 ThreatLevel = 0;

	// Detailed description
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation", meta=(MultiLine=true))
	FText Description;
};

USTRUCT(BlueprintType)
struct FInvestigationNPCData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	FText Name;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	int32 Age = 30;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	float ScanTime = 2.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	FText Occupation;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	bool bIsSuspect = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation", 
	meta=(EditCondition="bIsSuspect", EditConditionHides, ClampMin="0", ClampMax="10"))
	int32 SuspicionLevel = 0;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation", meta=(MultiLine=true))
	FText Description;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	int32 UniqueID = -1;
};

USTRUCT(BlueprintType)
struct FInvestigationItemData
{
	GENERATED_BODY()

public:
	// Item display name
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item")
	FText Name;

	// Item description
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item", meta=(MultiLine=true))
	FText Description;
	
	// Type/category of the item (e.g., Explosive, Medkit)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item")
	FText Type;

	// Flexible stats (e.g., Radius, Duration, Damage)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item")
	TMap<FString, FString> Stats;
	
	// Unique identifier
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item")
	int32 UniqueID = -1;
};



UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	Common      UMETA(DisplayName = "Common"),
	Rare        UMETA(DisplayName = "Rare"),
	Epic        UMETA(DisplayName = "Epic"),
	Legendary   UMETA(DisplayName = "Legendary"),
};

class PHANTOMTRACE_API InvestigationDataTypes
{
public:
	InvestigationDataTypes();
	~InvestigationDataTypes();
};
