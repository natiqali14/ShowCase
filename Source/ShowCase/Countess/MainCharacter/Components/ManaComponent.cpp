// Fill out your copyright notice in the Description page of Project Settings.


#include "ManaComponent.h"

// Sets default values for this component's properties
UManaComponent::UManaComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxMana = 100;
	CurrentMana = 100;
	

}


// Called when the game starts
void UManaComponent::BeginPlay()
{
	Super::BeginPlay();
	

	
}


// Called every frame
void UManaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UManaComponent::UseMana()
{
	CurrentMana = FMath::Clamp(CurrentMana - 2,0,MaxMana);
}