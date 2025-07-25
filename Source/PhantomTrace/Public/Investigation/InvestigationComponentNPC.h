// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DA_InvestigationDataBase.h"
#include "InvestigationDataTypes.h"
#include "Components/ActorComponent.h"
#include "InvestigationComponentNPC.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHANTOMTRACE_API UInvestigationComponentNPC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInvestigationComponentNPC();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	UDA_InvestigationDataBase* InvestigationDataAsset;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation|Person")
	FInvestigationNPCData InvestigationData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation|Object")
	FInvestigationItemData InvestigationItemData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Investigation")
	bool bObjectInvestigated = false;
};
