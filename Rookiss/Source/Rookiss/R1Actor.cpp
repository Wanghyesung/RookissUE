// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
// Sets default values

//스마트 포인트 개념가 아닌 가비지컬렉션 느낌
	//상호참조가 없음 트리를 통해 연결된 참조되었는지 확인
	//루트 노드를 통해서 그래프에서 누가 나를 기억하는지 확인가능

	//UR1Object* obj = NewObject<UR1Object>();
	//obj->AddToRoot() //루트 노드에 넣기

	//GEngine->ForceGarbageCollection(); 강제로 가비지 컬렉션 호출

AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

