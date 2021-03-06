// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankNavMovementComponent.generated.h"

class UTankTrackStaticMeshComponent;

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTracks(UTankTrackStaticMeshComponent* LTrack, UTankTrackStaticMeshComponent* RTrack);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnRight(float Throw);

	virtual void RequestDirectMove(const FVector&, bool) override;
	
private:
	// L = Left
	UTankTrackStaticMeshComponent* LTrack = nullptr;
	// R = Right
	UTankTrackStaticMeshComponent* RTrack = nullptr;
};
