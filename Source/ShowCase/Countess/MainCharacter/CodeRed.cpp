// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeRed.h"

// Sets default values
ACodeRed::ACodeRed()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

