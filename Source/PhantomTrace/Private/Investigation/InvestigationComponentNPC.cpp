// Fill out your copyright notice in the Description page of Project Settings.


#include "Investigation/InvestigationComponentNPC.h"

// Sets default values for this component's properties
UInvestigationComponentNPC::UInvestigationComponentNPC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInvestigationComponentNPC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInvestigationComponentNPC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

