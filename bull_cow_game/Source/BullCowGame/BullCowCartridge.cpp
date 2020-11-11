// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("tawb");
    LivesRemaining = 4;
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hiya Tawb"));
    PrintLine(TEXT("Input words, then press ENTER"));
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Debug Lines
    PrintLine(FString::Printf(TEXT("Lives Left: %s"), *HiddenWord));
    PrintLine(FString::Printf(TEXT("Lives Left: %i"), LivesRemaining));

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

/*
Player gets told the length of the word

While (guessesRemain) {
    guess word
    gets feedback on B/C
}
*/