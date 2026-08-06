// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "EOR_PlayerCharacterTypes.generated.h"

/**
 *
 */
 // Movement intensity order
 // Crouch < Walk < Run < Sprint

UENUM(BlueprintType)
enum class EGaitState : uint8
{
    Crouch,
    Walk,
    Run,//Deafult character movement
    Sprint
};

USTRUCT(BlueprintType)
struct FGaitConfig
{
    GENERATED_BODY()

public:

    // Final movement speed applied to CharacterMovement
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait|Speed")
    float MaxWalkSpeed = 0.f;

    // How fast character accelerates to target speed
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait|Response")
    float MaxAcceleration = 0.f;

    // How fast character slows down when input stops
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait|Response")
    float BrakingDecelerationWalking = 0.f;

    // Controls how slippery braking feels
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait|Response")
    float BrakingFriction = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait|Response")
    float BrakingFrictionFactor = 0.f;

    // Whether to use custom braking friction or engine default
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait|Response")
    bool bUseSeparateBrakingFriction = false;
};