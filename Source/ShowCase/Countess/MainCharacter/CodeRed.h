// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/HealthComponent.h"
#include "Components/ManaComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "ShowCase/Countess/MagicActor/BlackMagic.h"
#include "ShowCase/Countess/MagicActor/WhiteMagic.h"
#include "CodeRed.generated.h"
UENUM()
enum class ECharacterMode: uint8
{
	ECM_Travel,
	ECM_WithSwords
};
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

private:
	/** Movement */
	void StraightMovement(float Value);
	void SideMovement(float Value);
	void LookAt(float Value);
	void Turn(float Value);

	
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
	
public:
	FORCEINLINE USpringArmComponent* GetSpringArm(){ return SpringArmComponent;}
	FORCEINLINE UCameraComponent* GetCamera(){ return Camera;}
	FORCEINLINE ECharacterMode GetCharacterMode(){ return CharacterMode;}
	FORCEINLINE ABlackMagic* GetEquippedBlackMagic() {return EquippedBlackMagic;}
	FORCEINLINE AWhiteMagic* GetEquippedWhiteMagic() {return EquippedWhiteMagic;}
	//testing
	FORCEINLINE void DHealth(){ HealthComponent->DecreaseHealth();}
	FORCEINLINE void DMana(){ ManaComponent->UseMana();}
	void UseWhiteMagic();
};
