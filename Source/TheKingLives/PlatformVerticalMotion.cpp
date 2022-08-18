// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformVerticalMotion.h"

void APlatformVerticalMotion::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = GetActorLocation();
	CurrentZLocation = Location.Z;

	MinHeight = GetActorLocation().Z + MinHeight;
	MaxHeight = GetActorLocation().Z + MaxHeight;

	// Randomizes the direction the platform travels at the start of the game
	int32 RandomBool = FMath::RandRange(0, 1);
	bIsMovingUp = RandomBool;
}

void APlatformVerticalMotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

void APlatformVerticalMotion::MovePlatform(float DeltaTime)
{
	if (!bCanMove) return;

	const float LocalSpeed = DeltaTime * Speed;
	FVector NewLocation = GetActorLocation();

	if (bIsMovingUp)
		CurrentZLocation += LocalSpeed;
	else
		CurrentZLocation -= LocalSpeed;

	NewLocation.Z = CurrentZLocation;
	SetActorLocation(NewLocation);

	if (CurrentZLocation > MaxHeight)
		bIsMovingUp = false;
	else if (CurrentZLocation < MinHeight)
		bIsMovingUp = true;
}