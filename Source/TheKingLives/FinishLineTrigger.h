// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "FinishLineTrigger.generated.h"

/**
 * 
 */
UCLASS()
class THEKINGLIVES_API AFinishLineTrigger : public ATriggerVolume
{
	GENERATED_BODY()
public:
	AFinishLineTrigger();

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		class AActor* TheKingRef;

	//virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	virtual void BeginPlay() override;
};
