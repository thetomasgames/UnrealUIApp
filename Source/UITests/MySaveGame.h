// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UITESTS_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 other;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString scores;

	UMySaveGame();
	
	UFUNCTION(BlueprintCallable)
	void SyncGame();

private:

	FHttpModule * Http;
	FHttpModule * GetHttp();

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void MyHttpCall();
};
