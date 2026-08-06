// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/Anim/EOR_BaseAnimInstance.h"
#include "EOR_CharacterAnimInstance.generated.h"

/**
 * 
 */
class AEOR_BaseCharacter;
class UCharacterMovementComponent;
UCLASS()
class ECHOESOFRONAHI_API UEOR_CharacterAnimInstance : public UEOR_BaseAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY()
	TObjectPtr<AEOR_BaseCharacter>OwningCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent>OwningCharacterMovementComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float LocomotionDirection;
	
};
