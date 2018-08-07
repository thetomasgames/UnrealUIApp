// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RemotePlayerScore.generated.h"


/**
 * 
 */
UCLASS(ClassGroup = (Custom), BlueprintType)
class UITESTS_API URemotePlayerScore : public UObject
{
public:
	GENERATED_BODY()

	URemotePlayerScore();
	~URemotePlayerScore();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 score;
};
