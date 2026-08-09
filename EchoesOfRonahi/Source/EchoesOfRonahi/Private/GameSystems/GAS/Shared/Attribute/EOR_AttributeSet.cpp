// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.


#include "GameSystems/GAS/Shared/Attribute/EOR_AttributeSet.h"
#include "GameplayEffectExtension.h"

void UEOR_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	const FGameplayAttribute ModifiedAttribute = Data.EvaluatedData.Attribute;


	if (ModifiedAttribute == GetCurrentHealthAttribute())
	{
		//Health
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

	}
	else if (ModifiedAttribute == GetCurrentManaAttribute())
	{
		//Mana
		const float NewCurrentMana = FMath::Clamp(GetCurrentMana(), 0.f, GetMaxMana());
		SetCurrentMana(NewCurrentMana);
	}
	else if (ModifiedAttribute == GetCurrentStaminaAttribute())
	{
		//Stamina
		const float NewCurrentStamina = FMath::Clamp(GetCurrentStamina(), 0.f, GetMaxStamina());
		SetCurrentStamina(NewCurrentStamina);

	}
}
