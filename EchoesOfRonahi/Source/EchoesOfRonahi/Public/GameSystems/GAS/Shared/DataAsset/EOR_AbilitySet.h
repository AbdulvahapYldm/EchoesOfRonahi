// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EOR_AbilitySet.generated.h"

/**
 * 
 */
class UEOR_AbilitySystemComponent;
class UEOR_BaseGameplayAbility;

UCLASS()
class ECHOESOFRONAHI_API UEOR_AbilitySet : public UDataAsset
{
	GENERATED_BODY()
	
public:
    virtual void GiveToAbilitySystem(UEOR_AbilitySystemComponent* ASC, int32 AbilityLevel = 1);

protected:
    // [Category 1] Player/system triggered
    UPROPERTY(EditDefaultsOnly, Category = "Abilities|Activated")
    TArray<TSubclassOf<UEOR_BaseGameplayAbility>> ActivatedAbilities;

    // [Category 2] Auto-start on grant
    UPROPERTY(EditDefaultsOnly, Category = "Abilities|Auto")
    TArray<TSubclassOf<UEOR_BaseGameplayAbility>> AutoActivatedAbilities;

    // [Category 3] Always running
    UPROPERTY(EditDefaultsOnly, Category = "Abilities|Passive")
    TArray<TSubclassOf<UEOR_BaseGameplayAbility>> PassiveAbilities;

    // [Category 4] Conditional (tag-gated)
    UPROPERTY(EditDefaultsOnly, Category = "Abilities|Conditional")
    TArray<TSubclassOf<UEOR_BaseGameplayAbility>> ConditionalAbilities;

    // Helper: Grant array of abilities
    void GrantAbilities(const TArray<TSubclassOf<UEOR_BaseGameplayAbility>>& AbilitiesToGrant,
        UEOR_AbilitySystemComponent* ASC,
        int32 AbilityLevel,
        bool bAutoActivate = false);
};
