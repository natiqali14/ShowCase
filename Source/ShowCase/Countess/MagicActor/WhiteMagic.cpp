// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteMagic.h"

AWhiteMagic::AWhiteMagic()
{
	bReady = false;
	TimeToFull = WaitTime;
	MagicState = EWhiteMagicState::EWS_Recharging;
}

void AWhiteMagic::BeginPlay()
{
	Super::BeginPlay();
	InitiateProperties();
	TimeToFull = WaitTime;
	MagicState = EWhiteMagicState::EWS_Recharging;
}

void AWhiteMagic::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MagicPrepareTime(DeltaSeconds);
}
void AWhiteMagic::InitiateProperties()
{
	
	const FString WhitMagicDTPath = TEXT("DataTable'/Game/CodeRed/DataTables/DT_WhiteMagic.DT_WhiteMagic'");
	UDataTable* WhiteMagicDT = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(),
		nullptr,*WhitMagicDTPath));

	if(WhiteMagicDT)
	{
		const FBWhiteMagicInfo* Row = nullptr;
		if(WhiteMagicType == EWhiteMagic::EWM_LensOfTruth)
		{
			Row = WhiteMagicDT->FindRow<FBWhiteMagicInfo>(FName("LensOfTruth"),nullptr);
			if(Row)
			{
				Title = Row->Title;
				Description = Row->Description;
				InputButton = Row->InputButton;
				SkillIcon = Row->SkillIcon;
				SkillImage = Row->SkillImage;
				SkillBorderColor = Row->SkillBorderColor;
				SkillFontColor = Row->SkillFontColor;
				bMagicSkill = Row->bMagicSkill;
				Damage = Row->Damage;
				DamageType = Row->DamageType;
				MagicImage = Row->MagicImage;
				WaitTime = Row->WaitTime;
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
			}
			
		}
		else if(WhiteMagicType == EWhiteMagic::EWM_Mist)
		{
			Row = WhiteMagicDT->FindRow<FBWhiteMagicInfo>(FName("Mist"),nullptr);
			if(Row)
			{
				Title = Row->Title;
				Description = Row->Description;
				InputButton = Row->InputButton;
				SkillIcon = Row->SkillIcon;
				SkillImage = Row->SkillImage;
				SkillBorderColor = Row->SkillBorderColor;
				SkillFontColor = Row->SkillFontColor;
				bMagicSkill = Row->bMagicSkill;
				Damage = Row->Damage;
				DamageType = Row->DamageType;
				MagicImage = Row->MagicImage;
				WaitTime = Row->WaitTime;
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
			}
			
		}
		else if(WhiteMagicType == EWhiteMagic::EWM_Shield)
		{
			Row = WhiteMagicDT->FindRow<FBWhiteMagicInfo>(FName("Shield"),nullptr);
			if(Row)
			{
				Title = Row->Title;
				Description = Row->Description;
				InputButton = Row->InputButton;
				SkillIcon = Row->SkillIcon;
				SkillImage = Row->SkillImage;
				SkillBorderColor = Row->SkillBorderColor;
				SkillFontColor = Row->SkillFontColor;
				bMagicSkill = Row->bMagicSkill;
				Damage = Row->Damage;
				DamageType = Row->DamageType;
				MagicImage = Row->MagicImage;
				WaitTime = Row->WaitTime;
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
			}
			
		}
		else if(WhiteMagicType == EWhiteMagic::EWM_TimeSlow)
		{
			Row = WhiteMagicDT->FindRow<FBWhiteMagicInfo>(FName("Time_Slow"),nullptr);
			if(Row)
			{
				Title = Row->Title;
				Description = Row->Description;
				InputButton = Row->InputButton;
				SkillIcon = Row->SkillIcon;
				SkillImage = Row->SkillImage;
				SkillBorderColor = Row->SkillBorderColor;
				SkillFontColor = Row->SkillFontColor;
				bMagicSkill = Row->bMagicSkill;
				Damage = Row->Damage;
				DamageType = Row->DamageType;
				MagicImage = Row->MagicImage;
				WaitTime = Row->WaitTime;
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
			}
			
		}
	}
}

void AWhiteMagic::MagicPrepareTime(float DeltaTime)
{
	if(TimeToFull <= 0.01)
	{
		bReady = true;
		MagicState = EWhiteMagicState::EWS_Ready;
	}
	if(!bReady)
	{
		TimeToFull -= DeltaTime;
	}
}


void AWhiteMagic::UseMagic()
{
	if(bReady)
	{
		TimeToFull = WaitTime;
		bReady = false;
		MagicState = EWhiteMagicState::EWS_Recharging;
	}
	
}
