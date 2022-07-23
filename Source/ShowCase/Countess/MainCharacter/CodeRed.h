// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "CodeRed.generated.h"

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
public:
	// Sets default values for this character's properties
	ACodeRed();

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
	
};
