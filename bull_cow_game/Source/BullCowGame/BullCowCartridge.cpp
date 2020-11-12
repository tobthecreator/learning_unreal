// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("tawb");
    LivesRemaining = HiddenWord.Len();
    bFirstGuess = true;
    bGameOver = false;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress ENTER to play again."));
}

void UBullCowCartridge::PrintIntroduction() 
{
    PrintLine(TEXT("Hello weary traveller!"));
    PrintLine(TEXT("To cross this fence, answer my puzzles!"));
    PrintLine(TEXT("You'll be given blank letters, and you must guess what they are. Letters do not repeat."));
    PrintLine(TEXT("A Bull = Correct Guess;  A Cow = Incorrect Guess"));
    PrintLine(TEXT("You'll get as many guesses as blank letters."));
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintIntroduction();
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (bGameOver) {
        InitGame();
    }   

    PrintLine(FString::Printf(TEXT("The word is %i letters long"), HiddenWord.Len()));
    PrintLine(FString::Printf(TEXT("You have %i attempts left"), LivesRemaining));

    // Debug Lines
    // PrintLine(FString::Printf(TEXT("Hidden Word: %s"), *HiddenWord));
    // PrintLine(FString::Printf(TEXT("Lives Left: %i"), LivesRemaining));
    // PrintLine(FString::Printf(TEXT("First Guess: %d"), bFirstGuess));

    // If we meet a failure state, let them know why and how many attempts they have left
    if (InputMeetsFailureStateCriteria(Input)) {
        LivesRemaining--;
        return;
    }

    // If out of attempts after decrement, end the game
    if (LivesRemaining < 1) {
        ClearScreen();
        PrintLine(TEXT("Aw shucks, you're out of tries!"));
        EndGame();
        return;
    }
    
    // If the Input matches, quit
    if (Input == HiddenWord) {
        PrintLine(TEXT("You won!"));
        EndGame();
        return;
    } else { // Else, show the hits and misses, then decrement a a life
        EvaluateInput(Input);
        LivesRemaining--;
    }

    return;
}

bool UBullCowCartridge::IsIsogram(const FString& Input) 
{
    // O(n^2)
    for (int32 i=0; i < Input.Len() - 1; i++) {
        for (int32 j= i + 1; j < Input.Len(); j++) {
            if (Input[i] == Input[j]) {
                return false;
            }
        }
    }

    return true;
}

bool UBullCowCartridge::InputMeetsFailureStateCriteria(const FString& Input)
{
    bool bFailStateMet = false;

    // Ignore test if this is our first guess, or we just hit Enter to start playing
    // TODO: Hacky, should clear up these conditionals
    if (bFirstGuess) {
        bFirstGuess = false;
        return false;
    }

    // Fail state 1: Words are not of the same length
    if (Input.Len() != HiddenWord.Len()) {
        if (Input.Len() < HiddenWord.Len()) {
            PrintLine(TEXT("Your guess is too short!"));
        } else {
            PrintLine(TEXT("Your guess is too long!"));
        }
        
        bFailStateMet = true;
    }

    // Fail state 2: Input is not an isogram
    if (!IsIsogram(Input)) {
        PrintLine(TEXT("Not an isogram :("));

        bFailStateMet = true;
    }

    return bFailStateMet;
}

void UBullCowCartridge::EvaluateInput(const FString& Input)
{
    FBullCowCount Output;

    for (int32 i = 0; i < Input.Len(); i++) {
        if (Input[i] == HiddenWord[i]) {
            Output.Bulls++;
        } else {
            Output.Cows++;
        }
    }

    if (!bFirstGuess) {
        PrintLine(TEXT("You have %i Bulls and %i Cows"), Output.Bulls, Output.Cows);
    }
    
    return;
}

