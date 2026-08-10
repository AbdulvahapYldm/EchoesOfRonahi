// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.


#include "GameSystems/GAS/Shared/DataAsset/EOR_CharacterStartupData.h"


#include "GameSystems/GAS/Shared/Components/EOR_AbilitySystemComponent.h"
#include "GameSystems/GAS/Shared/GameplayAbility/EOR_BaseGameplayAbility.h"


void UEOR_CharacterStartupData::GiveToAbilitySystem(UEOR_AbilitySystemComponent* ASC,int32 ApplyLevel)
{
    // Base implementation: grant all 4 types
    GrantAbilities(ActivatedAbilities, ASC, ApplyLevel, false);
    GrantAbilities(AutoActivatedAbilities, ASC, ApplyLevel, true);

    for (const TSubclassOf<UEOR_BaseGameplayAbility>& AbilityClass : PassiveAbilities)
    {
        if (!AbilityClass) continue;

        FGameplayAbilitySpec AbilitySpec(AbilityClass, ApplyLevel, -1);
        FGameplayAbilitySpecHandle SpecHandle = ASC->GiveAbility(AbilitySpec);
        ASC->TryActivateAbility(SpecHandle);
    }

    GrantAbilities(ConditionalAbilities, ASC, ApplyLevel, false);

    if (!StartupGameplayEffects.IsEmpty())
    {
        for (const TSubclassOf < UGameplayEffect >& EffectClass : StartupGameplayEffects)
        {
            if (!EffectClass)
            {
                continue;
            }

            const UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();

            ASC->ApplyGameplayEffectToSelf(EffectCDO,ApplyLevel,ASC->MakeEffectContext());
        }
    }
}

void UEOR_CharacterStartupData::GrantAbilities(const TArray<TSubclassOf<UEOR_BaseGameplayAbility>>& AbilitiesToGrant,
    UEOR_AbilitySystemComponent* ASC,int32 AbilityLevel,bool bAutoActivate)
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