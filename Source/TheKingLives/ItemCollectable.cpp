// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemCollectable.h"
#include "TheKingLivesGameMode.h"
#include "TheKingCharacter.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Turquoise, String);

// Sets default values
AItemCollectable::AItemCollectable()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = SceneRoot;
	StaticMesh->SetupAttachment(SceneRoot);
	StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AItemCollectable::BeginPlay()
{
	Super::BeginPlay();
	
	GameModeRef = GetWorld()->GetAuthGameMode<ATheKingLivesGameMode>();
}

// Called every frame
void AItemCollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate(DeltaTime);

}

void AItemCollectable::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (Cast<ATheKingCharacter>(OtherActor) != nullptr)
	{
		GameModeRef->ItemCollected();
		Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Turquoise, FString::Printf(TEXT("%d"), GameModeRef->GetItemsCollected()));
	}
}

void AItemCollectable::Rotate(float DeltaTime)
{
	FRotator NewRotation = FRotator(0.0f, YawRotationSpeed, 0.0f);
	FQuat QuatRotation = FQuat(NewRotation);
	AddActorLocalRotation(QuatRotation * DeltaTime, false, 0, ETeleportType::None);
}

