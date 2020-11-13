// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	// UE_LOG Usage Examples
	// UE_LOG(LogTemp, Error, TEXT("Test error log"));
	// UE_LOG(LogTemp, Warning, TEXT("Test warning log"));
	// UE_LOG(LogTemp, Display, TEXT("Test display log"));
	
	// Pointer References
	// FString
	// FString exString = TEXT("exString");
	// FString* exStringPtr = &exString;
	// UE_LOG(LogTemp, Display, TEXT("%s"), **exStringPtr);

	// Int32
	// int32 exInt = 25;
	// int32* exIntPtr = &exInt;
	// UE_LOG(LogTemp, Display, TEXT("%i"), *exIntPtr);

	// Log Owner Name
	// UE_LOG(LogTemp, Display, TEXT("Owner name: %s"), *GetOwner()->GetName());

	FString ActorTransform = GetOwner()->GetActorTransform().ToString();
	UE_LOG(LogTemp, Display, TEXT("AActor Transfrom: %s"), *ActorTransform);

	FVector ActorPosition = GetOwner()->GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("FVector: %s"), *ActorPosition.ToString());
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

