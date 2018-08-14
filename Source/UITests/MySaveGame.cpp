// Fill out your copyright notice in the Description page of Project Settings.

#include "MySaveGame.h"


UMySaveGame::UMySaveGame() {
	name = TEXT("SampleName");
	height = 1.80f;
	weight = 79.5f;
}

FHttpModule * UMySaveGame::GetHttp()
{
	if (Http == nullptr) {
		Http = &FHttpModule::Get();
	}
	return Http;
}


void UMySaveGame::SyncGame()
{
	TSharedRef<IHttpRequest> Request = GetHttp()->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UMySaveGame::OnResponseReceived);
	//This is the url on which to process the request
	//FString url = "http://jsonplaceholder.typicode.com/comments?postId=" + FString::FromInt(rand() % 100);
	FString url = "https://reqres.in/api/users?page=2";
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
}

void UMySaveGame::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

	UE_LOG(LogTemp, Warning, TEXT("Received Response"));
	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonResponse;

	//Create a reader pointer to read the json data
	FString content = Response->GetContentAsString();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);

	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonResponse))
	{
		
		//Get the value of the json object by field name

		TArray<TSharedPtr<FJsonValue>> JsonArray = JsonResponse->GetArrayField("data");

		for (auto JValue : JsonArray) {
			TSharedPtr<FJsonObject> JObj = JValue->AsObject();
			int32 score = JObj->GetIntegerField("id");
			FString name = JObj->GetStringField("first_name");
			FFPlayerScore p1;
			p1.score = score;
			p1.name = name;
			scores.Add(p1);
			//UE_LOG(LogTemp, Warning,TEXT("Olá"));
		}

		OnScoresUpdate.Broadcast();
		//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
	}
}
