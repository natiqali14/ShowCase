// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillHolder.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASkillHolder::ASkillHolder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh 1"));
	RootComponent = Mesh1;
	Mesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh 2"));
	Mesh2->SetupAttachment(GetRootComponent());
	EntryTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("trigger Box"));
	EntryTrigger->SetupAttachment(GetRootComponent());
	SkillParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VFX"));
	SkillParticle->SetupAttachment(Mesh2);

}

// Called when the game starts or when spawned
void ASkillHolder::BeginPlay()
{
	Super::BeginPlay();
	EntryTrigger->OnComponentBeginOverlap.AddDynamic(this,&ASkillHolder::EntryTriggerBeginOverlap);
	EntryTrigger->OnComponentEndOverlap.AddDynamic(this,&ASkillHolder::EntryTriggerEndOverlap);
	Mesh2Location = Mesh2->GetComponentLocation();
}

// Called every frame
void ASkillHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkillHolder::EntryTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	StartAnimation();
}

void ASkillHolder::EntryTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	StopAnimation();
	Mesh2->SetWorldLocation(Mesh2Location);
}


void ASkillHolder::UpdateMesh2ZValue(float ZVal)
{
	FVector Location = Mesh2->GetComponentLocation();
	Location.Z += ZVal;
	Mesh2->SetWorldLocation(Location);
	
	
}

