// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CodeRedPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOWCASE_API ACodeRedPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = NotifyBlock)
	TSubclassOf<UUserWidget> NotifyBlockAsset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = NotifyBlock)
	UUserWidget* NotifyBlock;

	
	ACodeRedPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION(BlueprintCallable)
	void SetNotifyBlockVisible(bool Visibility);
	
};

