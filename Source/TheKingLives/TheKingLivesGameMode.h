// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheKingLivesGameMode.generated.h"

UCLASS(minimalapi)
class ATheKingLivesGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATheKingLivesGameMode();

	int32 GetItemsCollected();
	int32 GetItemsInWorld();
	int32 GetLives();

	void SetLives(int32 LivesLost);

	void ItemCollected();

protected:
	virtual void BeginPlay() override;

private:
	TArray<AActor*> ItemsInWorld;
	int32 ItemsCollected;
	int32 Lives;
};