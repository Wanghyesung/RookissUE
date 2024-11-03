// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Actor.generated.h"
//generated는 항상 마지막에

UCLASS()
class ROOKISS_API AR1Actor : public AActor
{
	GENERATED_BODY()

	/*
	* GENERATED_BODY 리플랙션을 구현하기 위해 ?
	* 만약 UPROPERTY나 GENERATED_BODY가 없다면 리플렉션을 통해
	* 해당 객체를 찾을 수 없음 선언을 해둬야함 클래스에 대한 정보를 언리얼이
	* 알 수 있게 미리 정의를 해둬야함 (관찰대상으로 넣어줘야함)
	* 언리얼 헤더 툴이 매크로를 정보면 정보(메타데이터)를 기록함
	* 메타 데이터를 읽고 이 객체를 대표하는 DefaultObject 클래스를 샘플로 만들어줌(CDO)
	*/  
	


public:	
	// Sets default values for this actor's properties
	AR1Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//UPROPERTY() 그래프 루트에는 포함이 됨 하지만 에디터 상에서는 나오지않음
	//메타데이터 안에 힌트를 줄 수 있음
	//BlueprintReadWirte기능 = protected, Set, Get이 가능

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat)
	int32 Hp = 100;

	UPROPERTY();
	int32 Mp = 50;

	UPROPERTY();
	float Speed = 3.5f;

};
