// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ManaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOWCASE_API UManaComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// Sets default values for this component's properties
	UManaComponent();
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Properties, meta = (AllowPrivateAccess = "true"))
	int32 MaxMana;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Properties, meta = (AllowPrivateAccess = "true"))
	int32 CurrentMana;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Owner, meta = (AllowPrivateAccess = "true"))
	AActor* Owner;
public:
	FORCEINLINE int32 GetMaxMana() {return MaxMana;}
	FORCEINLINE int32 GetCurrentMana() {return CurrentMana;}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Testing Only
	void UseMana();
		
};


