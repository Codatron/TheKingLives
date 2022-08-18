// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "PlatformVerticalMotion.generated.h"

/**
 * 
 */
UCLASS()
class THEKINGLIVES_API APlatformVerticalMotion : public APlatformBase
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		float Speed;
	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		float MaxHeight;
	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		float MinHeight;

	// Functions
	virtual void MovePlatform(float DeltaTime);

	// Variables
	float CurrentZLocation;
	uint8 bIsMovingUp : 1;
};
