// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementSkill.h"

AMovementSkill::AMovementSkill()
{
}

void AMovementSkill::BeginPlay()
{
	Super::BeginPlay();
	InitiateProperties();
}

void AMovementSkill::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMovementSkill::InitiateProperties()
{
	const FString MovementSkillDT = TEXT("DataTable'/Game/CodeRed/DataTables/DT_MovementSkill.DT_MovementSkill'");
	UDataTable* MagicDT = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(),
		nullptr,*MovementSkillDT));

	if(MagicDT)
	{
		const FMovementInfo* Row = nullptr;
		if(MovementSkill == EMovementSkill::EMS_BackDash)
		{
			Row = MagicDT->FindRow<FMovementInfo>(FName("BackDash"),nullptr);
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
				
				
				
				ManaCost  = Row->ManaCost;
				
			}
			
		}
		else if(MovementSkill == EMovementSkill::EMS_DoubleJump)
		{
			Row = MagicDT->FindRow<FMovementInfo>(FName("DoubleJump"),nullptr);
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
				
				
				
				ManaCost  = Row->ManaCost;
				
			}
			
		}
	}
}
