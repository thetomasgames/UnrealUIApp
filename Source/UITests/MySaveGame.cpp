// Fill out your copyright notice in the Description page of Project Settings.

#include "MySaveGame.h"


UMySaveGame::UMySaveGame() {
	name = TEXT("SampleName");
	height = 1.80f;
	weight = 79.5f;
	scores = TEXT("");
}

void UMySaveGame::SyncGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Sync game"));
	MyHttpCall();
}

FHttpModule * UMySaveGame::GetHttp()
{
	if (Http == nullptr) {
		Http = &FHttpModule::Get();
	}
	return Http;
}


/*Http call*/
void UMySaveGame::MyHttpCall()
{
	TSharedRef<IHttpRequest> Request = GetHttp()->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UMySaveGame::OnResponseReceived);
	//This is the url on which to process the request
	Request->SetURL("http://jsonplaceholder.typicode.com/posts/1");
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
}

void UMySaveGame::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("OnResponseReceived"));
	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	FString content = Response->GetContentAsString();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);

	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		//Get the value of the json object by field name
		UE_LOG(LogTemp, Warning,TEXT("%S"), *content);
		//int32 recievedInt = JsonObject->GetIntegerField("userId");

		scores = TEXT("changed");
		//Output it to the engine
		//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
	}
}