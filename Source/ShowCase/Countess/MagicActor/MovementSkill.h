// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "Engine/DataTable.h"
#include "ShowCase/Countess/Enums/BlackMagicTypes.h"
#include "MovementSkill.generated.h"

USTRUCT(BlueprintType)
struct FMovementInfo : public FTableRowBase
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
	int32 ManaCost;
	
	
	
};

/**
 * 
 */
UCLASS()
class SHOWCASE_API AMovementSkill : public ASkill
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	EMovementSkill MovementSkill;

public:
	AMovementSkill();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void InitiateProperties();
};
