// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/Anim/EOR_PlayerAnimInstance.h"
#include "Characters/Player/EOR_PlayerCharacter.h"
#include "Characters/Player/Components/EOR_PlayerCharacterMovementComp.h"

void UEOR_PlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		PlayerCharacter = Cast<AEOR_PlayerCharacter>(OwningCharacter);
		PlayerMovementComponent = Cast<UEOR_PlayerCharacterMovementComp>(PlayerCharacter->GetCharacterMovement());

	}
}

void UEOR_PlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (!PlayerMovementComponent) return;

	IsFalling = PlayerMovementComponent->IsFalling();
	Velocity = PlayerMovementComponent->Velocity.Z;
	IsCrounching = PlayerMovementComponent->IsCrouching();

	if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);

	}
}
