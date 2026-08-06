// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Base/Anim/EOR_CharacterAnimInstance.h"
#include "Characters/Base/EOR_BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

void UEOR_CharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AEOR_BaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningCharacterMovementComp = OwningCharacter->GetCharacterMovement();
	}
}

void UEOR_CharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter && !OwningCharacterMovementComp) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningCharacterMovementComp->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}
