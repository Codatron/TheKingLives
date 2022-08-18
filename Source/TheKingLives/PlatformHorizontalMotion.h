// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "PlatformHorizontalMotion.generated.h"

/**
 * 
 */
UCLASS()
class THEKINGLIVES_API APlatformHorizontalMotion : public APlatformBase
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		float Speed;
	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		float MaxDistanceRight;
	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		float MaxDistanceLeft;

	virtual void MovePlatform(float DeltaTime) override;

	uint8 bIsMovingRight : 1;
	float CurrentYLocation;
};
