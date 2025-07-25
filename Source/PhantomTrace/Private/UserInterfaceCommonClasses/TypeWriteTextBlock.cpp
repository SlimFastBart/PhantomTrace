// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaceCommonClasses/TypeWriteTextBlock.h"

void UTypeWriteTextBlock::Typewrite()
{
	FullTextString = TextToWrite.ToString();
	CurrentCharIndex = 0;
	SetText(FText::FromString(TEXT("")));

	
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			TypewriteTimer,
			this,
			&UTypeWriteTextBlock::BeginTypewrite,
			InitialDelay,
			false 
		);
	}
}

void UTypeWriteTextBlock::BeginTypewrite()
{
	
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			TypewriteTimer,
			this,
			&UTypeWriteTextBlock::ShowNextCharacter,
			TimePerSign,
			true 
		);
	}
}

void UTypeWriteTextBlock::ShowNextCharacter()
{
	if (CurrentCharIndex > FullTextString.Len())
	{
		if (GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(TypewriteTimer);
		}
		return;
	}

	FString CurrentText = FullTextString.Left(CurrentCharIndex);
	SetText(FText::FromString(CurrentText));
	++CurrentCharIndex;
}
