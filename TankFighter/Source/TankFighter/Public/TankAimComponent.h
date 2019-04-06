// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

class UTankBarrelStaticMeshComponent;
class UTankTurretStaticMeshComponent;

UENUM()
enum class EPointerStatus : uint8
{
	Reloading,
	Locked,
	Aiming
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		EPointerStatus PointerStatus = EPointerStatus::Reloading;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Player and AI's aimping point
	void AimAt(FVector&, float);
	void SetTankBarrel(UTankBarrelStaticMeshComponent*);
	void SetTankTurret(UTankTurretStaticMeshComponent*);
	void MoveBarrel(FVector&);
	void RotateTurret(FVector&);

	UTankBarrelStaticMeshComponent* GetTankBarrel() const;

private:
	UTankBarrelStaticMeshComponent* TankBarrel = nullptr;
	UTankTurretStaticMeshComponent* TankTurret = nullptr;
};
