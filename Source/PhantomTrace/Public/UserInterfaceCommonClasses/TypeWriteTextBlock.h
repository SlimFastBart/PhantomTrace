// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "TypeWriteTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class PHANTOMTRACE_API UTypeWriteTextBlock : public UTextBlock
{
	GENERATED_BODY()

public:
	
	// Editable time (in seconds) per character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Typewriter")
	float TimePerSign = 0.05f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Typewriter")
	float InitialDelay = 0.1f;

	// Editable text to type out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Typewriter")
	FText TextToWrite;
	
	UFUNCTION(BlueprintCallable, Category="Typewriter")
	void Typewrite();

protected:
	int32 CurrentCharIndex = 0;
	FString FullTextString;
	FTimerHandle TypewriteTimer;

	void BeginTypewrite();
	
	void ShowNextCharacter();
};
