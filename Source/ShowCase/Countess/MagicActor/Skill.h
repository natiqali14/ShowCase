// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Skill.generated.h"

UCLASS()
class SHOWCASE_API ASkill : public AActor
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FName Title;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	FName Description;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	UTexture2D* InputButton;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	UTexture2D* SkillIcon;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	UTexture2D* SkillImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	UTexture2D* SkillBorderColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	UTexture2D* SkillFontColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Data, meta = (AllowPrivateAccess = "true"))
	bool bMagicSkill;
	
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
