// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

#pragma once

#include "CoreMinimal.h"
#include "GameSystems/GAS/Shared/DataAsset/EOR_AbilitySet.h"
#include "GameplayTagContainer.h"
#include "GameplayAbilitySpec.h" 
#include "EOR_PlayerAbilitySet.generated.h"

/**
 * 
 */
class UEOR_AbilitySystemComponent;
class UEOR_BasePlayerGameplayAbility;

/**
 * Player-specific ability set entry
 * Maps input tags to abilities and stores granted handles for input system
 */
USTRUCT(BlueprintType)
struct FEOR_PlayerAbilityEntry
{
    GENERATED_BODY()

public:
    // Which input will trigger this ability (e.g., "Input.Player.LightAttack")
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Input"))
    FGameplayTag InputTag;

    // The ability to grant
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UEOR_BasePlayerGameplayAbility> PlayerGameplayAbility;


    // Runtime: Granted handle (filled during GiveToAbilitySystem)
    /*
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FGameplayAbilitySpecHandle GrantedAbilityHandle;*/

    bool IsValid() const;

};


UCLASS()
class ECHOESOFRONAHI_API UEOR_PlayerAbilitySet : public UEOR_AbilitySet
{
	GENERATED_BODY()


public:
    virtual void GiveToAbilitySystem(UEOR_AbilitySystemComponent* ASC, int32 AbilityLevel = 1) override;

    // Input system calls this to get all input-mapped abilities
    const TArray<FEOR_PlayerAbilityEntry>& GetPlayerInputAbilityies() const;

private:
    // Player-specific abilities with input mapping
    UPROPERTY(EditDefaultsOnly, Category = "Player Abilities", meta = (TitleProperty = "InputTag"))
    TArray<FEOR_PlayerAbilityEntry> PlayerInputAbilityies;
	
};
