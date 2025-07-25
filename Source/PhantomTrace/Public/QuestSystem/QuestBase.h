// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestSystemTypes.h"
#include "GameFramework/Actor.h"
#include "QuestBase.generated.h"


// Forward declarations
class UDA_QuestScenarioBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestObjectiveSignature, AQuestBase*, Quest, FDataTableRowHandle, ObjectiveRow);

UCLASS(Abstract, HideCategories=("ActorTick", "Actor Tick", "Replication", "Rendering", "Collision", "WorldPartition", "World Partition", "Input", "HLOD", "Physics"))
class PHANTOMTRACE_API AQuestBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest", meta = (RequiredAssetDataTags="RowStructure=/Script/PhantomTrace.QuestObjective", RowType="/Script/PhantomTrace.QuestObjective"), AssetRegistrySearchable)
	TObjectPtr<UDataTable> ObjectivesDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	TObjectPtr<UDA_QuestScenarioBase> QuestScenario = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quest")
	TMap<FName, FQuestObjectiveData> Objectives;

	UPROPERTY(BlueprintAssignable, Category = "Quest")
	FQuestObjectiveSignature OnObjectiveAdded;

	// Functions
public:

	UFUNCTION(BlueprintCallable, Category = "Quest", meta=(DataTable="ObjectivesTable", DataTablePin="DataTable", RowType="/Script/PhantomTrace.QuestObjective",RequiredAssetDataTags="RowStructure=/Script/PhantomTrace.QuestObjective"))
	bool AddObjective(UPARAM(meta=(RowType="/Script/PhantomTrace.QuestObjective", RequiredAssetDataTags="RowStructure=/Script/PhantomTrace.QuestObjective")) UDataTable* DataTable, FName RowName);
};
