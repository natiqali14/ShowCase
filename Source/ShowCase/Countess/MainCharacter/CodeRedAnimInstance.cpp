// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeRedAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UCodeRedAnimInstance::UCodeRedAnimInstance()
{
	Speed = 0.f;
	bIsInAir = false;
	bInTravelMode = true;
	MovementYaw = 0.f;
	IsAccelerating = false;
}

void UCodeRedAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	APawn* Owner = TryGetPawnOwner();
	if(Owner)
	{
		CodeRedRef = Cast<ACodeRed>(Owner);
	}
	
}

void UCodeRedAnimInstance::UpdateProperties(float DeltaTime)
{
	if(CodeRedRef == nullptr)
	{
		APawn* Owner = TryGetPawnOwner();
		if(Owner)
		{
			CodeRedRef = Cast<ACodeRed>(Owner);
		}
	}
	
	if(CodeRedRef)
	{
		
		FVector Velocity = CodeRedRef->GetVelocity();
		Velocity.Z = 0.f;
		Speed = Velocity.Size();
		FRotator Aim = CodeRedRef->GetBaseAimRotation();
		FRotator CurrentRot = UKismetMathLibrary::MakeRotFromX(Velocity);
		FRotator Delta = UKismetMathLibrary::NormalizedDeltaRotator(CurrentRot,Aim);
		MovementYaw = Delta.Yaw;
		
		
		bIsInAir = CodeRedRef->GetCharacterMovement()->IsFalling();
		if(bIsInAir)
		{
			
		}
		if(CodeRedRef->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0)
		{
			IsAccelerating = true;
		}
		else
		{
			IsAccelerating = false;
		}
		if(CodeRedRef->GetCharacterMode() == ECharacterMode::ECM_Travel)
		{
			bInTravelMode = true;
		}
		else
		{
			bInTravelMode = false;
		}
		
		if(CodeRedRef->GetVelocity().Size() > 0)
		{
			CodeRedRef->bUseControllerRotationYaw = true;
			CodeRedYaw = 0.f;
			CodeRedPitch = 0.f;
		}
		else{
			CodeRedRef->bUseControllerRotationYaw = false;
			FVector Forward = CodeRedRef->GetActorForwardVector();
			FRotator Rot  = UKismetMathLibrary::MakeRotFromX(Forward);
			CodeRedYaw = CodeRedRef->GetBaseAimRotation().Yaw;
			CodeRedPitch = FMath::Clamp(CodeRedRef->GetBaseAimRotation().Pitch,-85,80);
		}
		UE_LOG(LogTemp,Warning,TEXT("%s"),*CodeRedRef->GetActorRotation().ToString());
		UE_LOG(LogTemp,Warning,TEXT("%s"),*CodeRedRef->GetBaseAimRotation().ToString());
	}
	
}
