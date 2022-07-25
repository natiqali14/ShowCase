// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ShowCase/Countess/MagicActor/BlackMagic.h"
#include "ShowCase/Countess/MagicActor/MovementSkill.h"
#include "ShowCase/Countess/MagicActor/WhiteMagic.h"
#include "SkillHolder.generated.h"
UENUM(BlueprintType)
enum class ESkillType : uint8
{
	EST_WhiteMagic,
	EST_BlackMagic,
	EST_MovementSKill
};
class ASkill;
UCLASS()
class SHOWCASE_API ASkillHolder : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Skill)
	ESkillType SkillType;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Skill)
	TSubclassOf<AWhiteMagic> WhiteMagic;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Skill)
	TSubclassOf<ABlackMagic> BlackMagic;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Skill)
	TSubclassOf<AMovementSkill> MovementSkill;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = StylizedMesh)
	UStaticMeshComponent* Mesh1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = StylizedMesh)
	UStaticMeshComponent* Mesh2;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = StylizedMesh)
	UBoxComponent* EntryTrigger;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = VFX)
	UParticleSystemComponent* SkillParticle;
	FVector Mesh2Location;
	
	
public:	
	// Sets default values for this actor's properties
	ASkillHolder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void EntryTriggerBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void EntryTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION(BlueprintImplementableEvent)
	void StartAnimation();
	UFUNCTION(BlueprintImplementableEvent)
	void StopAnimation();
	
	UFUNCTION(BlueprintCallable)
	void UpdateMesh2ZValue(float ZVal);
};
