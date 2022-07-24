// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Magic.h"
#include "WhiteMagic.generated.h"

/**
 * 
 */
UCLASS()
class SHOWCASE_API AWhiteMagic : public AMagic
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	EWhiteMagic WhiteMagicType;

public:
	AWhiteMagic();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
};
