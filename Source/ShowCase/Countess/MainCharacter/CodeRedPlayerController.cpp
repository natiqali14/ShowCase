// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeRedPlayerController.h"

#include "Blueprint/UserWidget.h"

ACodeRedPlayerController::ACodeRedPlayerController()
{
}

void ACodeRedPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// if(NotifyBlockAsset)
	// {
	// 	NotifyBlock = CreateWidget<UUserWidget>(this,NotifyBlockAsset);
	// 	NotifyBlock->AddToViewport();
	// 	NotifyBlock->SetVisibility(ESlateVisibility::Hidden);
	// 	
	// }
	
}

void ACodeRedPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
void ACodeRedPlayerController::SetNotifyBlockVisible(bool Visibility)
{
	if(!NotifyBlock) return;
	if(Visibility)
	{
		NotifyBlock->SetVisibility(ESlateVisibility::Visible);
		
	}
	else
	{
		NotifyBlock->SetVisibility(ESlateVisibility::Hidden);
	}
	
}
