// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "ShowCase/Countess/MainCharacter/CodeRed.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxHealth = 100;
	CurrentHealth = 100;
	

	// ...
}




// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	Owner = GetOwner();
	Owner->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::TakeAnyDmg);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DecreaseHealth()
{
	CurrentHealth = FMath::Clamp(CurrentHealth - 2,0, MaxHealth);
	UE_LOG(LogTemp,Warning,TEXT("%d"),CurrentHealth)
}

void UHealthComponent::TakeAnyDmg(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                  AController* InstigatedBy, AActor* DamageCauser)
{
	if(Owner == nullptr) return;
	if(DamagedActor == Owner)
	{
		// For CodeRed
		ACodeRed* CodeRedRef = Cast<ACodeRed>(DamagedActor);
		if(CodeRedRef)
		{
			CurrentHealth = FMath::Clamp(CurrentHealth - Damage,0, MaxHealth);
			if(CurrentHealth <= 0)
			{
				//TODO: Death
			}
		}
	}
}
