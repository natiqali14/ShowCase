// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOWCASE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Properties, meta = (AllowPrivateAccess = "true"))
	int32 MaxHealth;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Properties, meta = (AllowPrivateAccess = "true"))
	int32 CurrentHealth;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Owner, meta = (AllowPrivateAccess = "true"))
	AActor* Owner;
	
public:	
	// Sets default values for this component's properties
	UHealthComponent();
	void TakeAnyDmg( AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController*
		InstigatedBy, AActor* DamageCauser);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FORCEINLINE int32 GetMaxHealth() {return MaxHealth;}
	FORCEINLINE int32 GetCurrentHealth() {return CurrentHealth;}

	// Testing Only
	void DecreaseHealth();
		
};
