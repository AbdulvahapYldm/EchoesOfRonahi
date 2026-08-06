// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "EOR_PlayerState.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;
class UEOR_PlayerAbilitySet;

UCLASS()
class ECHOESOFRONAHI_API AEOR_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()


public:
	AEOR_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; };
	UEOR_PlayerAbilitySet* GetPlayerAbilitySet() const { return PlayerAbilitySet; };

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS|AbilitySystemComponent")
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS|AttributeSet")
	TObjectPtr<UAttributeSet>AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|AbilitySet")
	TObjectPtr<UEOR_PlayerAbilitySet> PlayerAbilitySet;
	
};
