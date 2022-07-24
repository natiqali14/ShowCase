// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Magic.h"
#include "BlackMagic.generated.h"

/**
 * 
 */
UCLASS()
class SHOWCASE_API ABlackMagic : public AMagic
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Magic, meta = (AllowPrivateAccess = "true"))
	EBlackMagic BlackMagicType;
	
	
public:
	ABlackMagic();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	
};
