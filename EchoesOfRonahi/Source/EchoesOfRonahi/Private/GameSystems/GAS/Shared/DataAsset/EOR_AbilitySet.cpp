// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.


#include "GameSystems/GAS/Shared/DataAsset/EOR_AbilitySet.h"


#include "GameSystems/GAS/Shared/Components/EOR_AbilitySystemComponent.h"
#include "GameSystems/GAS/Shared/GameplayAbility/EOR_BaseGameplayAbility.h"


void UEOR_AbilitySet::GiveToAbilitySystem(
    UEOR_AbilitySystemComponent* ASC,
    int32 AbilityLevel)
{
    // Base implementation: grant all 4 types
    GrantAbilities(ActivatedAbilities, ASC, AbilityLevel, false);
    GrantAbilities(AutoActivatedAbilities, ASC, AbilityLevel, true);

    for (const TSubclassOf<UEOR_BaseGameplayAbility>& AbilityClass : PassiveAbilities)
    {
        if (!AbilityClass) continue;

        FGameplayAbilitySpec AbilitySpec(AbilityClass, AbilityLevel, -1);
        FGameplayAbilitySpecHandle SpecHandle = ASC->GiveAbility(AbilitySpec);
        ASC->TryActivateAbility(SpecHandle);
    }

    GrantAbilities(ConditionalAbilities, ASC, AbilityLevel, false);
}

void UEOR_AbilitySet::GrantAbilities(
    const TArray<TSubclassOf<UEOR_BaseGameplayAbility>>& AbilitiesToGrant,
    UEOR_AbilitySystemComponent* ASC,
    int32 AbilityLevel,
    bool bAutoActivate)
{
    for (const TSubclassOf<UEOR_BaseGameplayAbility>& AbilityClass : AbilitiesToGrant)
    {
        if (!AbilityClass) continue;

        FGameplayAbilitySpec AbilitySpec(AbilityClass, AbilityLevel, -1);
        FGameplayAbilitySpecHandle SpecHandle = ASC->GiveAbility(AbilitySpec);

        if (bAutoActivate)
        {
            ASC->TryActivateAbility(SpecHandle);
        }
    }
}