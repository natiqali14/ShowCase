// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackMagic.h"

ABlackMagic::ABlackMagic()
{
}

void ABlackMagic::BeginPlay()
{
	Super::BeginPlay();
	InitiateProperties();
}

void ABlackMagic::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABlackMagic::InitiateProperties()
{
	const FString MagicDTPath = TEXT("DataTable'/Game/CodeRed/DataTables/DT_BlackMAgic.DT_BlackMAgic'");
	UDataTable* MagicDT = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(),
		nullptr,*MagicDTPath));

	if(MagicDT)
	{
		const FBlackMagicInfo* Row = nullptr;
		if(BlackMagicType == EBlackMagic::EBM_FireBall)
		{
			Row = MagicDT->FindRow<FBlackMagicInfo>(FName("FireBall"),nullptr);
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
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
				
			}
			
		}
		else if(BlackMagicType == EBlackMagic::EBM_ElectroSpark)
		{
			Row = MagicDT->FindRow<FBlackMagicInfo>(FName("ElectroSpark"),nullptr);
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
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
				
			}
			
		}
		else if(BlackMagicType == EBlackMagic::EBM_BloodLust)
		{
			Row = MagicDT->FindRow<FBlackMagicInfo>(FName("BloodLust"),nullptr);
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
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
				
			}
			
		}
		else if(BlackMagicType == EBlackMagic::EBM_ArtciBlast)
		{
			Row = MagicDT->FindRow<FBlackMagicInfo>(FName("ArticBlast"),nullptr);
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
				bCanDamage = Row->bCanDamage;
				ManaCost  = Row->ManaCost;
				
			}
			
		}
	}

}
