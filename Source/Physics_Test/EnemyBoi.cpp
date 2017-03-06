// Fill out your copyright notice in the Description page of Project Settings.

#include "Physics_Test.h"
#include "EnemyBoi.h"


// Sets default values
AEnemyBoi::AEnemyBoi()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBoi::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyBoi::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector Movement = GetActorForwardVector();

	AddMovementInput(Movement, MovementValue);

}

// Called to bind functionality to input
void AEnemyBoi::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

