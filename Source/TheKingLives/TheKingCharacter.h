// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TheKingCharacter.generated.h"

UCLASS()
class THEKINGLIVES_API ATheKingCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATheKingCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Game Mode")
		class ATheKingLivesGameMode* GameMode;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* SpringArm;

	void MoveRight(float Value);
	void ChangeSpringArmLength();
	void CheckDeath();

	UPROPERTY(EditAnywhere)
		float DeathThreshold;
	FVector TempLocation;
	float CameraOffset;
	uint8 bToggleSpringArmLength : 1;
	uint8 bIsFalling : 1;
	uint8 bIsDead : 1;
};
