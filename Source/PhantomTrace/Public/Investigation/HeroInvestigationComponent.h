// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "W_InvestigationBase.h"
#include "HeroInvestigationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHANTOMTRACE_API UHeroInvestigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHeroInvestigationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	UPROPERTY(BlueprintReadOnly, Category="Investigation")
	UW_InvestigationBase* InvestigationWidget = nullptr;

	
	UFUNCTION(BlueprintCallable, Category="Investigation")
	void InitializeInvestigationWidget(UW_InvestigationBase* Widget);

	void StartInvestigation(bool bShowInvestigationPanel);
	
private:
	FTimerHandle InvestigationTraceTimerHandle;
	
	void PerformInvestigationTrace();

	AActor* LastHitActor = nullptr;

	void HandleLostInvestigationTarget();

	
};
