// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.


#include "GameSystems/GAS/Player/DataAsset/EOR_PlayerAbilitySet.h"

#include "GameSystems/GAS/Shared/Components/EOR_AbilitySystemComponent.h"
#include "GameSystems/GAS/Player/GameplayAbility/EOR_BasePlayerGameplayAbility.h"



void UEOR_PlayerAbilitySet::GiveToAbilitySystem(UEOR_AbilitySystemComponent* ASC, int32 AbilityLevel)
{
    // [1] Grant base abilities (passive, conditional, etc.)
    // This calls parent's implementation which handles all 4 categories
    Super::GiveToAbilitySystem(ASC, AbilityLevel);

    // [2] Grant player-specific input-mapped abilities
    for (FEOR_PlayerAbilityEntry& Entry : PlayerInputAbilityies)
    {
        if (!Entry.IsValid()) continue;


        FGameplayAbilitySpec AbilitySpec(Entry.PlayerGameplayAbility, AbilityLevel, -1);
        AbilitySpec.GetDynamicSpecSourceTags().AddTag(Entry.InputTag);
        AbilitySpec.SourceObject = ASC->GetAvatarActor();
        FGameplayAbilitySpecHandle SpecHandle = ASC->GiveAbility(AbilitySpec);
        // Entry.GrantedAbilityHandle = SpecHandle;

    }

}

const TArray<FEOR_PlayerAbilityEntry>& UEOR_PlayerAbilitySet::GetPlayerInputAbilityies() const
{
    return PlayerInputAbilityies;
}

bool FEOR_PlayerAbilityEntry::IsValid() const
{
    return InputTag.IsValid() && PlayerGameplayAbility != nullptr;;
}
