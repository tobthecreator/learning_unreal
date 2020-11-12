// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("tawb");
    LivesRemaining = 4;
}

void UBullCowCartridge::PrintIntroduction() {
    PrintLine(TEXT("Hello weary traveller!"));
    PrintLine(TEXT("To cross this fence, answer my puzzles!"));
    PrintLine(TEXT("You'll be given blank letters, and you must guess what they are. Letters do not repeat."));
    PrintLine(TEXT("A Bull = Correct Guess;  A Cow = Incorrect Guess"));
    PrintLine(TEXT("You'll get as many guesses as blank letters."));
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
    PrintIntroduction();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Debug Lines
    PrintLine(FString::Printf(TEXT("Hidden Word: %s"), *HiddenWord));
    PrintLine(FString::Printf(TEXT("Lives Left: %i"), LivesRemaining));

    // Fail state 1: Words are not of the same length
    if (Input.Len() != HiddenWord.Len()) {
        LivesRemaining--;
    }

    // Fail state 2: Input is not an isogram
    if (!IsIsogram(Input)) {

    }


    // if (Input.Len() == HiddenWord.Len()) {
    //     PrintLine(TEXT("Matches"));
    // }

    // if (LivesRemaining > 0) {
        
    //     //PrintLine(FText::FromString(FString::Append("Lives left: "), FString::FromInt(LivesRemaining)));
    // }

    // Gather user input

    /*
        Verification
            + Check that input is an isogram
            + Check that input matches the length of HiddenWord
            + Check that we still have lives remaining
    */

   /*
        Success
            + Congrats!
            + Generate new word
        
        Failure
            + Subtract life
   */
    PrintLine((Input == HiddenWord) ? TEXT("True") : TEXT("False"));

}

bool UBullCowCartridge::IsIsogram(const FString& Input)
{
    // n^2
    for (int32 i=0; i < Input.Len(); i++) {
        
        PrintLine(FString::Printf(TEXT("i: %i"), i));
        for (int32 j=0; j < Input.Len(); j++) {
            PrintLine(FString::Printf(TEXT("j: %i"), j));
        }
    }

    return true;
}


