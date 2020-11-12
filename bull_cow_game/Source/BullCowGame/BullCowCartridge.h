// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void InitGame();
	void EndGame();
	void PrintIntroduction();
	bool IsIsogram(const FString& Input);
	bool InputMeetsFailureStateCriteria(const FString& Input);
	void EvaluateInput(const FString& Input);

	private:
	FString HiddenWord;
	int32 LivesRemaining;
	bool bFirstGuess = true;
	bool bGameOver = false;
};
