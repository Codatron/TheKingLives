// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLineTrigger.h"
#include "TheKingCharacter.h"
#include "DrawDebugHelpers.h"
#include "UObject/ConstructorHelpers.h"
#include "TheKingLivesGameMode.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Turquoise, String);

AFinishLineTrigger::AFinishLineTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AFinishLineTrigger::OnOverlapBegin);
}

void AFinishLineTrigger::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), Brush->Bounds.BoxExtent, FColor::Orange, true, -1, 0, 5);
}

void AFinishLineTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (ATheKingCharacter* TheKing = Cast<ATheKingCharacter>(OtherActor))
	{
		PrintString("Overlap Begin");
		ATheKingLivesGameMode* GameModeRef = GetWorld()->GetAuthGameMode<ATheKingLivesGameMode>();

		if (GameModeRef->GetItemsCollected() == GameModeRef->GetItemsInWorld())
		{
			PrintString("You Win!");
		}
		else
		{
			PrintString("You don't have enough items.");
		}
	}
}