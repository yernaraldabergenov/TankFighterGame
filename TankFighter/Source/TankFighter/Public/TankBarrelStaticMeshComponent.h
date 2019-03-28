// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankBarrelStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float);

private:
	//DPS = degrees per second
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxTankBarrelDPS = 20.f;
	//D = degrees
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxTankBarrelElevationsD = 45.f; 
	//D = degrees
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinTankBarrelElevationsD = 0.f;
};
