// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBase.h"

// Sets default values
AQuestBase::AQuestBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuestBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AQuestBase::AddObjective(UDataTable* DataTable, FName RowName)
{
	if (Objectives.Contains(RowName))
	{
		return false;
	}

	if (DataTable->FindRow<FQuestObjective>(RowName, ""))
	{
		FQuestObjectiveData SavedData;
		SavedData.RowName = RowName;
		SavedData.bActive = true;

		Objectives.Add(RowName, SavedData);

		FDataTableRowHandle ObjectiveRowHandle;
		ObjectiveRowHandle.DataTable = ObjectivesDataTable;
		ObjectiveRowHandle.RowName = RowName;

		OnObjectiveAdded.Broadcast(this, ObjectiveRowHandle);
		return true;
	}
	return false;
}

