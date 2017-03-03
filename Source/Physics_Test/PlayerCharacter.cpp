// Fill out your copyright notice in the Description page of Project Settings.

#include "Physics_Test.h"
#include "PlayerCharacter.h"


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
	
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveY", this, &APlayerCharacter::Move_Y_Axis);
	PlayerInputComponent->BindAxis("MoveX", this, &APlayerCharacter::Move_X_Axis);


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


//Test post pls ignore