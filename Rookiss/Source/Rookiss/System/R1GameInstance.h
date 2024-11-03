// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "R1GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROOKISS_API UR1GameInstance : public UGameInstance
{
	GENERATED_BODY()

	//게임이 실행될 때 하나만 생성
	//매니저처럼 사용하거나 처음 변수를 초기화하는 작업에 사용

};
