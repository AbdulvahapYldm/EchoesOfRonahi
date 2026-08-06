// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "EOR_AbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class ECHOESOFRONAHI_API UEOR_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

};
