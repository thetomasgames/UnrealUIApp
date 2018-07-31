// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UITESTS_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	float height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	float weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	int32 other;

	UMySaveGame();
	
};
