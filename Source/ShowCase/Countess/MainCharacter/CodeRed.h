// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CodeRedPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/HealthComponent.h"
#include "Components/ManaComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "ShowCase/Countess/Actors/SkillHolder.h"
#include "ShowCase/Countess/MagicActor/BlackMagic.h"
#include "ShowCase/Countess/MagicActor/MovementSkill.h"
#include "ShowCase/Countess/MagicActor/WhiteMagic.h"
#include "CodeRed.generated.h"
enum class ESkillType : uint8;
UENUM()
enum class ECharacterMode: uint8
{
	ECM_Travel,
	ECM_WithSwords
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSkillLearned,bool, Learned);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCancelUIDelegate,bool, Cancel);
UCLASS()
class SHOWCASE_API ACodeRed : public ACharacter
{
	GENERATED_BODY()
private:
	/** Spring arm for the Main Character */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComponent;
	/** Camera for the Main Character */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	float XAxisSens;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	float YAxisSens;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	ECharacterMode CharacterMode;
	/** Turn in Place Montage */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Montages ,meta = (AllowPrivateAccess = "true") )
	UAnimMontage* TurnInPlaceMontage;
	// Health Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	// Mana Component
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = SpringArm,meta = (AllowPrivateAccess = "true"))
	UManaComponent* ManaComponent;

	// WhiteMagic Slot
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = WhiteMagic,meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWhiteMagic> WhiteMagicToEquipped;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = WhiteMagic,meta = (AllowPrivateAccess = "true"))
	AWhiteMagic* EquippedWhiteMagic;

	// Black MAgic
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = BlackMagic,meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABlackMagic> BlackMagictoEquipped;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = BlackMagic,meta = (AllowPrivateAccess = "true"))
	ABlackMagic* EquippedBlackMagic;

	// Skill Inventory
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = MovementSkill,meta = (AllowPrivateAccess = "true"))
	TArray<AMovementSkill*> MovementSkillInventory;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = MovementSkill,meta = (AllowPrivateAccess = "true"))
	AMovementSkill* CurrentMovementSkill;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = BlackMagic,meta = (AllowPrivateAccess = "true"))
	TArray<ABlackMagic*> BlackMagicInventory;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = WhiteMagic,meta = (AllowPrivateAccess = "true"))
	TArray<AWhiteMagic*> WhiteMagicInventory;

	// Skill Learning
	
private:
	/** Movement */
	void StraightMovement(float Value);
	void SideMovement(float Value);
	void LookAt(float Value);
	void Turn(float Value);

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SkillLearning,meta = (AllowPrivateAccess = "true"))
	bool bSkillLearnedButtonPress;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SkillLearning)
	bool bInsideSkillHolder;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SkillLearning)
	ASkillHolder* SkillHolder;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SkillLearning,meta = (AllowPrivateAccess = "true"))
	ASkill* LastLearnedSkill;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = SkillLearning,meta = (AllowPrivateAccess = "true"))
	ESkillType LastLearnedSkillType;
	UPROPERTY(BlueprintAssignable,Category = SkillLeaning)
	FSkillLearned SkillLearned;
	UPROPERTY(BlueprintAssignable,Category = SkillLeaning)
	FCancelUIDelegate CancelUIDelegate;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = PlayerController,meta = (AllowPrivateAccess = "true"))
	ACodeRedPlayerController* CodeRedPlayerController;
	

	
public:
	// Sets default values for this character's properties
	ACodeRed();
	void PlayTurnInPlaceMontage(FName SectionName);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void EquipBlackMagic();
	void EquipWhiteMagic();
	void LearnSkillButtonPressed();
	void  LearnSkillButtonReleased();
	void CanelUIButtonPressed();

	// Skill Learning
	void LearnSkill();
	void SetSkillHolder(ASkillHolder* Holder);
	
public:
	FORCEINLINE USpringArmComponent* GetSpringArm(){ return SpringArmComponent;}
	FORCEINLINE UCameraComponent* GetCamera(){ return Camera;}
	FORCEINLINE ECharacterMode GetCharacterMode(){ return CharacterMode;}
	FORCEINLINE ABlackMagic* GetEquippedBlackMagic() {return EquippedBlackMagic;}
	FORCEINLINE AWhiteMagic* GetEquippedWhiteMagic() {return EquippedWhiteMagic;}
	FORCEINLINE bool GetSkillLearnedButtonPress() {return bSkillLearnedButtonPress;}



	//testing
	FORCEINLINE void DHealth(){ HealthComponent->DecreaseHealth();}
	FORCEINLINE void DMana(){ ManaComponent->UseMana();}
	void UseWhiteMagic();
};
