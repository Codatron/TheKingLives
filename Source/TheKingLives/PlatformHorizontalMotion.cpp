// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformHorizontalMotion.h"

void APlatformHorizontalMotion::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = GetActorLocation();
	CurrentYLocation = Location.Y;

	MaxDistanceRight = GetActorLocation().Y + MaxDistanceRight;
	MaxDistanceLeft = GetActorLocation().Y + MaxDistanceLeft;

	int32 RandomBool = FMath::RandRange(0, 1);
	bIsMovingRight = RandomBool;
}

void APlatformHorizontalMotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

void APlatformHorizontalMotion::MovePlatform(float DeltaTime)
{
	if (!bCanMove) return;

	const float LocalSpeed = DeltaTime * Speed;
	FVector NewLocation = GetActorLocation();

	if (bIsMovingRight)
		CurrentYLocation += LocalSpeed;
	else
		CurrentYLocation -= LocalSpeed;

	NewLocation.Y = CurrentYLocation;
	SetActorLocation(NewLocation);

	if (CurrentYLocation > MaxDistanceRight)
		bIsMovingRight = false;
	else if (CurrentYLocation < MaxDistanceLeft)
		bIsMovingRight = true;
}
