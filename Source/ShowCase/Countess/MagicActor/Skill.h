// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Slate/SlateBrushAsset.h"
#include "Skill.generated.h"

UCLASS()
class SHOWCASE_API ASkill : public AActor
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FName Title= "";
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FName Description = "";
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* InputButton = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* SkillIcon= nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* SkillImage= nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* SkillBorderColor= nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FLinearColor SkillFontColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	bool bMagicSkill;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	USlateBrushAsset* MagicImage= nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	int32 ManaCost = 0;
	
public:	
	// Sets default values for this actor's properties
	ASkill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
