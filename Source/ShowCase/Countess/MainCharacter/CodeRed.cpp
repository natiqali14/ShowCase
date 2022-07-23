// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeRed.h"


// Sets default values
ACodeRed::ACodeRed()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComponent,USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void ACodeRed::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACodeRed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACodeRed::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ACharacter::Jump);
	PlayerInputComponent->BindAxis("StraightMovement",this,&ACodeRed::StraightMovement);
	PlayerInputComponent->BindAxis("SideMovement",this,&ACodeRed::SideMovement);

}
/**
 * Movement for Main Character
 */
void ACodeRed::StraightMovement(float Value)
{
	if(GetController())
	{
		const FRotator PlayerRotation = GetController()->GetControlRotation();
		const FRotator OnlyYawRotation = FRotator{0.f, PlayerRotation.Yaw, 0.f};
		const FVector DirectionX = FRotationMatrix{OnlyYawRotation}.GetUnitAxis(EAxis::X);
		AddMovementInput(DirectionX,Value);
	}
}

void ACodeRed::SideMovement(float Value)
{
	if(GetController())
	{
		const FRotator PlayerRotation = GetController()->GetControlRotation();
		const FRotator OnlyYawRotation = FRotator{0.f, PlayerRotation.Yaw, 0.f};
		const FVector DirectionY = FRotationMatrix{OnlyYawRotation}.GetUnitAxis(EAxis::Y);
		AddMovementInput(DirectionY,Value);
	}
	
}
