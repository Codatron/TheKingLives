// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformBase.generated.h"

UCLASS()
class THEKINGLIVES_API APlatformBase : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformBase();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* Mesh;

	// Functions
	virtual void MovePlatform(float DeltaTime);

	// Variables
	UPROPERTY(EditAnywhere, Category = "Platform Properties")
		uint8 bCanMove:1;
};