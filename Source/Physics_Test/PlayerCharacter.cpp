// Fill out your copyright notice in the Description page of Project Settings.

#include "Physics_Test.h"
#include "PlayerCharacter.h"
#include "PlayerBullet.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	MyController->bShowMouseCursor = true;

	
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	SetPlayerRotation();

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveY", this, &APlayerCharacter::Move_Y_Axis);
	PlayerInputComponent->BindAxis("MoveX", this, &APlayerCharacter::Move_X_Axis);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &APlayerCharacter::Shoot);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);


}

void APlayerCharacter::Move_Y_Axis(float Value)
{

	FVector MoveY = FVector(0.0f, 1.0f, 0.0f);
	AddMovementInput(MoveY, Value);

}

void APlayerCharacter::Move_X_Axis(float Value)
{

	FVector MoveX = FVector(1.0f, 0.0f, 0.0f);

	AddMovementInput(MoveX, Value);

}

void APlayerCharacter::SetPlayerRotation()
{

	FHitResult Hit;
	bool HitResult = false;

	HitResult = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_WorldStatic), true, Hit);

	if (HitResult)
	{
		FVector CursorLocation = Hit.Location;

		//		UE_LOG(LogTemp, Warning, TEXT("Cursor location %s!"), *CursorLocation.ToString());

		FVector TempLocation = FVector(CursorLocation.X, CursorLocation.Y, 30.f);

		FVector NewDirection = TempLocation - GetActorLocation();
		NewDirection.Z = 0.0f;
		NewDirection.Normalize();
		SetActorRotation(NewDirection.Rotation());
	}


}

void APlayerCharacter::Shoot()
{

	World = GetWorld();

	FVector Location = GetActorLocation() + GetActorForwardVector() * SpawnDistance;


	if (World)
	{
		World->SpawnActor<APlayerBullet>(PlayerBullet_BP, Location, FRotator::ZeroRotator);
	}
}

void APlayerCharacter::FellOutOfWorld(const class UDamageType & dmgType)
{
	UE_LOG(LogTemp, Warning, TEXT("Character fell out of world"));

	Destroy();
}