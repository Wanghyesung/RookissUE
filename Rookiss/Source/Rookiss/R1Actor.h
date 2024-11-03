// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Actor.generated.h"
//generated�� �׻� ��������

UCLASS()
class ROOKISS_API AR1Actor : public AActor
{
	GENERATED_BODY()

	/*
	* GENERATED_BODY ���÷����� �����ϱ� ���� ?
	* ���� UPROPERTY�� GENERATED_BODY�� ���ٸ� ���÷����� ����
	* �ش� ��ü�� ã�� �� ���� ������ �ص־��� Ŭ������ ���� ������ �𸮾���
	* �� �� �ְ� �̸� ���Ǹ� �ص־��� (����������� �־������)
	* �𸮾� ��� ���� ��ũ�θ� ������ ����(��Ÿ������)�� �����
	* ��Ÿ �����͸� �а� �� ��ü�� ��ǥ�ϴ� DefaultObject Ŭ������ ���÷� �������(CDO)
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
	//UPROPERTY() �׷��� ��Ʈ���� ������ �� ������ ������ �󿡼��� ����������
	//��Ÿ������ �ȿ� ��Ʈ�� �� �� ����
	//BlueprintReadWirte��� = protected, Set, Get�� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat)
	int32 Hp = 100;

	UPROPERTY();
	int32 Mp = 50;

	UPROPERTY();
	float Speed = 3.5f;

};
