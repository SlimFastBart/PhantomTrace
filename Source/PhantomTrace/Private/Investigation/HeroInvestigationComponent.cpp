// Fill out your copyright notice in the Description page of Project Settings.


#include "Investigation/HeroInvestigationComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h" 
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Investigation/InvestigateInterface.h"
#include "Investigation/InvestigationComponentNPC.h"
#include "Investigation/DA_InvestigationDataBase.h"


// Sets default values for this component's properties
UHeroInvestigationComponent::UHeroInvestigationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHeroInvestigationComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
}


// Called every frame
void UHeroInvestigationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHeroInvestigationComponent::InitializeInvestigationWidget(UW_InvestigationBase* Widget)
{
	InvestigationWidget = Widget;
}

void UHeroInvestigationComponent::StartInvestigation(bool bShowInvestigationPanel)
{
	if (!IsValid(InvestigationWidget))
	{
		return;
	}
	
	InvestigationWidget->ChangeInvestigationVisibility(bShowInvestigationPanel);

	if (bShowInvestigationPanel)
	{
		GetWorld()->GetTimerManager().SetTimer(InvestigationTraceTimerHandle, this, &UHeroInvestigationComponent::PerformInvestigationTrace, 0.1f, true);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(InvestigationTraceTimerHandle);
	}
}

void UHeroInvestigationComponent::PerformInvestigationTrace()
{

	float TraceDistance = 1000.0f;
	
	if (!IsValid(InvestigationWidget))
	{
		return;
	}
	
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor)
	{
		return;
	}
	
	UCameraComponent* CameraComponent = OwnerActor->FindComponentByClass<UCameraComponent>();
	if (!CameraComponent)
	{
		return;
	}

	FVector Start = CameraComponent->GetComponentLocation();
	FVector ForwardVector = CameraComponent->GetForwardVector();
	FVector End = Start + (ForwardVector * TraceDistance);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerActor);

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_GameTraceChannel2,
		Params
	);

	// Debug line
	// DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1.0f);

	AActor* HitActor = nullptr;
	if (bHit)
	{
		HitActor = HitResult.GetActor();
	}
	
	if (!IsValid(HitActor) && IsValid(LastHitActor))
	{
		InvestigationWidget->HideInvestigationDataPanel();
		HandleLostInvestigationTarget();
		LastHitActor = nullptr;
		return;
	}

	if (IsValid(HitActor) && HitActor != LastHitActor)
	{
		if (HitActor->GetClass()->ImplementsInterface(UInvestigateInterface::StaticClass()))
		{
			UInvestigationComponentNPC* InvestigationComponent = HitActor->FindComponentByClass<UInvestigationComponentNPC>();
			if (InvestigationComponent)
			{
				InvestigationWidget->OnSetInvestigationData(InvestigationComponent);
			}
		}
		LastHitActor = HitActor;
	}
}

void UHeroInvestigationComponent::HandleLostInvestigationTarget()
{
	if (IsValid(LastHitActor))
	{
		InvestigationWidget->HideInvestigationDataPanel();
		LastHitActor = nullptr;
	}
	else
	{
		InvestigationWidget->HideInvestigationDataPanel();
	}
}

