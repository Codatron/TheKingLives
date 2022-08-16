// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemCollectable.generated.h"

UCLASS()
class THEKINGLIVES_API AItemCollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemCollectable();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
		class ATheKingLivesGameMode* GameModeRef;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void Rotate(float DeltaTime);

	UPROPERTY(EditAnywhere)
		float YawRotationSpeed;
};
