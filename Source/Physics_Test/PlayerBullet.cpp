// Fill out your copyright notice in the Description page of Project Settings.

#include "Physics_Test.h"
#include "PlayerBullet.h"
#include "EnemyBoi.h"


// Sets default values
APlayerBullet::APlayerBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBullet::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox = this->FindComponentByClass<USphereComponent>();

	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APlayerBullet::OnOverlap);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Bullet no collision box"));

	}
}

// Called every frame
void APlayerBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * DeltaTime * Speed;
	SetActorLocation(NewLocation);

}

void APlayerBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Enemy Overlap %s"), *OtherActor->GetName())

	if (OtherActor->IsA(AEnemyBoi::StaticClass()))
	{

		OtherActor->Destroy();
		Destroy();
	}
	if (OtherActor->IsRootComponentStatic())
	{
		//Static object -> generate overlap events -> (computing ++) Use CCD (continous collision detection)
		Destroy();
	}
}