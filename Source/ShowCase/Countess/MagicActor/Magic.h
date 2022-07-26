// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "ShowCase/Countess/Enums/BlackMagicTypes.h"
#include "Magic.generated.h"

/**
 * 
 */
UCLASS()
class SHOWCASE_API AMagic : public ASkill
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	float Damage = 0;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	bool bCanDamage = false;
	
public:
	AMagic();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	
};
