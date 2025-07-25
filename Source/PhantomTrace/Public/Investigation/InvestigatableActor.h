// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Investigation/InvestigateInterface.h"
#include "InvestigatableActor.generated.h"

UCLASS()
class PHANTOMTRACE_API AInvestigatableActor : public AActor, public IInvestigateInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInvestigatableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
};
