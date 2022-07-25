// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeRed.h"

#include "GameplayTask.h"
#include "Kismet/GameplayStatics.h"


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
	XAxisSens = 2.f;
	YAxisSens = 2.f;

	// Charater Mode
	CharacterMode = ECharacterMode::ECM_Travel;

	// Health
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	ManaComponent = CreateDefaultSubobject<UManaComponent>(TEXT("Mana Componet"));
	

}

void ACodeRed::PlayTurnInPlaceMontage(FName SectionName)
{
	
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if(AnimInstance && TurnInPlaceMontage)
	{
		AnimInstance->Montage_Play(TurnInPlaceMontage);
		AnimInstance->Montage_JumpToSection(SectionName,TurnInPlaceMontage);
	}
}

// Called when the game starts or when spawned
void ACodeRed::BeginPlay()
{
	Super::BeginPlay();
	EquipBlackMagic();
	EquipWhiteMagic();
	
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
	PlayerInputComponent->BindAxis("LookAt",this, &ACodeRed::LookAt);
	PlayerInputComponent->BindAxis("Turn",this, &ACodeRed::Turn);

	// testingonly
	PlayerInputComponent->BindAction("Health",IE_Pressed,this, &ACodeRed::DHealth);
	PlayerInputComponent->BindAction("Mana",IE_Pressed,this, &ACodeRed::DMana);
	PlayerInputComponent->BindAction("Q",IE_Pressed,this,&ACodeRed::UseWhiteMagic);

}

void ACodeRed::EquipBlackMagic()
{
	ABlackMagic* BlackMagic = Cast<ABlackMagic>(GetWorld()->SpawnActor(BlackMagictoEquipped));
	EquippedBlackMagic = BlackMagic;
}

void ACodeRed::EquipWhiteMagic()
{
	AWhiteMagic* WhiteMagic = Cast<AWhiteMagic>(GetWorld()->SpawnActor(WhiteMagicToEquipped));
	EquippedWhiteMagic = WhiteMagic;
}

void ACodeRed::UseWhiteMagic()
{
	EquippedWhiteMagic->UseMagic();
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

void ACodeRed::LookAt(float Value)
{
	AddControllerPitchInput(Value * YAxisSens);
}

void ACodeRed::Turn(float Value)
{
	AddControllerYawInput(Value * XAxisSens);
}
