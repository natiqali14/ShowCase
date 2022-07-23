// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CodeRed.h"
#include "Animation/AnimInstance.h"
#include "CodeRedAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOWCASE_API UCodeRedAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	ACodeRed* CodeRedRef;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	float Speed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	float MovementYaw;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	bool bInTravelMode;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	bool IsAccelerating;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	float CodeRedPitch;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = AnimationProperties , meta = (AllowPrivateAccess = "true"))
	float CodeRedYaw;
public:
	UCodeRedAnimInstance();
	virtual void NativeInitializeAnimation() override;
	UFUNCTION(BlueprintCallable)
	void UpdateProperties(float DeltaTime);
	
};
