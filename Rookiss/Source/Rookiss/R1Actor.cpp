// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
// Sets default values

//����Ʈ ����Ʈ ���䰡 �ƴ� �������÷��� ����
	//��ȣ������ ���� Ʈ���� ���� ����� �����Ǿ����� Ȯ��
	//��Ʈ ��带 ���ؼ� �׷������� ���� ���� ����ϴ��� Ȯ�ΰ���

	//UR1Object* obj = NewObject<UR1Object>();
	//obj->AddToRoot() //��Ʈ ��忡 �ֱ�

	//GEngine->ForceGarbageCollection(); ������ ������ �÷��� ȣ��

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

