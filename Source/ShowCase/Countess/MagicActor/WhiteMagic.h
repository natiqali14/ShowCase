// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Magic.h"
#include "Binding/ColorBinding.h"
#include "Engine/DataTable.h"
#include "WhiteMagic.generated.h"
USTRUCT(BlueprintType)
struct FBWhiteMagicInfo : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FName Title;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FName Description;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* InputButton;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* SkillIcon;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* SkillImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* SkillBorderColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FLinearColor SkillFontColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	bool bMagicSkill;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	float Damage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	int32 ManaCost;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	bool bCanDamage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* MagicImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	float WaitTime;
	
	
	
	
};

UENUM(BlueprintType)
enum class EWhiteMagicState: uint8
{
	EWS_Ready,
	EWS_Recharging,
};
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
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	float WaitTime;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	bool bReady;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	float TimeToFull;
	FTimerHandle MagicReadyHandle;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	EWhiteMagicState MagicState;
	

public:
	AWhiteMagic();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void InitiateProperties();
	void MagicPrepareTime(float DeltaTime);
	void SetTimeToFull();
	void UseMagic();
	
};

