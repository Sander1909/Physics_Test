// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PHYSICS_TEST_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move_Y_Axis(float Value);
	void Move_X_Axis(float Value);
	
	void SetPlayerRotation();
	void Shoot();

private:

	UPROPERTY()
		UWorld * World;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class APlayerBullet> PlayerBullet_BP;

	float SpawnDistance = 30.0f;

	
	
};
