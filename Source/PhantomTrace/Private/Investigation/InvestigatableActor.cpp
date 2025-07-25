// Fill out your copyright notice in the Description page of Project Settings.


#include "Investigation/InvestigatableActor.h"

// Sets default values
AInvestigatableActor::AInvestigatableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInvestigatableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInvestigatableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



