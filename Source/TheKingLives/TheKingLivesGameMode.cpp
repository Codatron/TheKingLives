// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheKingLivesGameMode.h"
#include "TheKingLivesCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "ItemCollectable.h"

#define PrintScreen(String) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::White, String);

ATheKingLivesGameMode::ATheKingLivesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_TheKingCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATheKingLivesGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItemCollectable::StaticClass(), ItemsInWorld);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("%d"), GetItemsInWorld()));
}

int32 ATheKingLivesGameMode::GetItemsCollected()
{
	return ItemsCollected;
}

int32 ATheKingLivesGameMode::GetItemsInWorld()
{
	return ItemsInWorld.Num();
}

void ATheKingLivesGameMode::ItemCollected()
{
	ItemsCollected++;
}
