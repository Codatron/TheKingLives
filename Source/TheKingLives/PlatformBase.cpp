// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformBase.h"

// Sets default values
APlatformBase::APlatformBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = SceneRoot;
	Mesh->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void APlatformBase::BeginPlay()
{
	Super::BeginPlay();
}

void APlatformBase::MovePlatform(float DeltaTime)
{
}

void APlatformBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
