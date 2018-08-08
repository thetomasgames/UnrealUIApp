// Fill out your copyright notice in the Description page of Project Settings.

#include "RemotePlayerScore.h"

URemotePlayerScore::URemotePlayerScore()
{
	name = "Sample Name";
	score = 100;

}

URemotePlayerScore::URemotePlayerScore(FString name_val, int32 score_val)
{
	name = name_val;
	score = score_val;

}


URemotePlayerScore::~URemotePlayerScore()
{
}
