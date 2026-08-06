// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.


#include "Core/States/EOR_PlayerState.h"
#include "GameSystems/GAS/Shared/Components/EOR_AbilitySystemComponent.h"
#include "GameSystems/GAS/Shared/Attribute/EOR_AttributeSet.h"

AEOR_PlayerState::AEOR_PlayerState()
{

	AbilitySystemComponent = CreateDefaultSubobject<UEOR_AbilitySystemComponent>(TEXT("EOR_AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(false);

	AttributeSet = CreateDefaultSubobject<UEOR_AttributeSet>(TEXT("RV_CharacterAttributeSet"));

}



UAbilitySystemComponent* AEOR_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
