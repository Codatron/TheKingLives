// Fill out your copyright notice in the Description page of Project Settings.


#include "TheKingCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ATheKingCharacter::ATheKingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetMesh());
	Camera->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->TargetArmLength = 550.0f;
	SpringArm->bEnableCameraLag = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	TempLocation = GetActorLocation();
}

// Called when the game starts or when spawned
void ATheKingCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	bToggleSpringArmLength = !bToggleSpringArmLength;
}

// Called every frame
void ATheKingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckDeath();
}

// Called to bind functionality to input
void ATheKingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRightLeft", this, &ATheKingCharacter::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("ChangeSpringArmLength", IE_Pressed, this, &ATheKingCharacter::ChangeSpringArmLength);
}

void ATheKingCharacter::MoveRight(float Value)
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
}

void ATheKingCharacter::CheckDeath()
{
	FVector Location = GetActorLocation();
	float CurrentZ = Location.Z;

	if (CurrentZ < DeathThreshold)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("You dead!")));
		Destroy();
	}
}

void ATheKingCharacter::ChangeSpringArmLength()
{
	/*FVector PreviousSpringArmLocation;
	FVector StartSpringArmLocation = PreviousSpringArmLocation - SpringArm->GetRelativeLocation();
	
	if (!bToggleSpringArmLength)
	{
		SpringArm->TargetArmLength = 550.0f;
		SpringArm->SetRelativeLocation(StartSpringArmLocation);
	}
	else
	{
		SpringArm->TargetArmLength = 800.0f;
		FVector NewSpringArmLocation = SpringArm->GetRelativeLocation();
		NewSpringArmLocation.Z = 375.0f;
		SpringArm->SetRelativeLocation(NewSpringArmLocation);
		PreviousSpringArmLocation = NewSpringArmLocation;
	}

	bToggleSpringArmLength = !bToggleSpringArmLength;*/
}