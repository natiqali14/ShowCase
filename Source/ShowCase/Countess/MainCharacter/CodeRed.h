// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
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
public:
	FORCEINLINE USpringArmComponent* GetSpringArm(){ return SpringArmComponent;}
	FORCEINLINE UCameraComponent* GetCamera(){ return Camera;}
	FORCEINLINE ECharacterMode GetCharacterMode(){ return CharacterMode;}
	
};
