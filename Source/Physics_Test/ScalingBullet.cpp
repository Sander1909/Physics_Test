// Fill out your copyright notice in the Description page of Project Settings.

#include "Physics_Test.h"
#include "ScalingBullet.h"


// Sets default values
AScalingBullet::AScalingBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScalingBullet::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox = this->FindComponentByClass<USphereComponent>();

	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AScalingBullet::OnOverlap);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No collision box"));

	}
	
}

// Called every frame
void AScalingBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	SetBulletLocation(DeltaTime);

	ScaleBullet();
}


void AScalingBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
}

void AScalingBullet::ScaleBullet()
{
	FVector NewScale = GetActorScale() + FVector(1.0f,1.0f,1.0f) * ScaleRestriction;

	SetActorScale3D(NewScale);
}

void AScalingBullet::SetBulletLocation(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(NewLocation);
}