// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/Anim/EOR_CharacterAnimInstance.h"
#include "EOR_PlayerAnimInstance.generated.h"

/**
 * 
 */
class AEOR_PlayerCharacter;
class UEOR_PlayerCharacterMovementComp;

UCLASS()
class ECHOESOFRONAHI_API UEOR_PlayerAnimInstance : public UEOR_CharacterAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:


	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	TObjectPtr<AEOR_PlayerCharacter>PlayerCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	TObjectPtr<UEOR_PlayerCharacterMovementComp>PlayerMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool IsFalling;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool IsCrounching;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float Velocity;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bShouldEnterRelaxState = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float EnterRelaxStateThreshold = 10.f;

	float IdleElpasedTime;
};
