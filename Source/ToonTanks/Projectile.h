// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UProjectileMovementComponent *ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UParticleSystemComponent *TrailParticles;

	UPROPERTY(EditAnywhere, Category = "Properties")
	float Damage = 50.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Properties")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = "Properties")
	class USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Properties")
	class USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Properties")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
