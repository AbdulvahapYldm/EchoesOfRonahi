// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "EOR_AttributeSet.generated.h"

/**
 * 
 */

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ECHOESOFRONAHI_API UEOR_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:



	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UEOR_AttributeSet, CurrentHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UEOR_AttributeSet, MaxHealth);


	// Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CurrentMana;
	ATTRIBUTE_ACCESSORS(UEOR_AttributeSet, CurrentMana);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UEOR_AttributeSet, MaxMana);

	// Stamina
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CurrentStamina;
	ATTRIBUTE_ACCESSORS(UEOR_AttributeSet, CurrentStamina);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UEOR_AttributeSet, MaxStamina);


};
