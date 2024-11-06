// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values

//����Ʈ ����Ʈ ���䰡 �ƴ� �������÷��� ����
	//��ȣ������ ���� Ʈ���� ���� ����� �����Ǿ����� Ȯ��
	//��Ʈ ��带 ���ؼ� �׷������� ���� ���� ����ϴ��� Ȯ�ΰ���

	//UR1Object* obj = NewObject<UR1Object>();
	//obj->AddToRoot() //��Ʈ ��忡 �ֱ�

	//GEngine->ForceGarbageCollection(); ������ ������ �÷��� ȣ��

AR1Actor::AR1Actor()
{
 	//CDO UObject�� ��ӹ����� ���÷��� �ý��ۿ� ���ؼ� UClass��ü�� ������ְ� �� �ȿ� CDO��� �� ��ü �纻�� �������
	PrimaryActorTick.bCanEverTick = true;
	
	//staticmesh ���� �����ͻ󿡼� �ٷ� Box�� ����
	//UObjectŬ������ ��ӹ��� ���̵��� ��Ÿ�����Ͱ� UHD�� ���ؼ� CDO��ü �纻, UClass ��ü�� ����
	//�� COD��ü�� �����ͼ� ��ȯ�� ���� (FObjectFinder, FClassFinder)
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	RootComponent = Body;//���� �ֻ��� �θ�
	Body->SetRelativeScale3D(FVector(2.f, 3.f, 0.5f));

	//Rotaion�� y z x������
	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body); //Body�� �ڽ�����
	Wing->SetRelativeLocationAndRotation(FVector(55,-72,88), FRotator(0,90,0));
	Wing->SetRelativeScale3D(FVector(3.75f, 0.25f, 0.5f));

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body); //Body�� �ڽ�����
	Head->SetRelativeLocationAndRotation(FVector(105, 36, 48), FRotator(0, 0, 0));
	Head->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	Wing->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Head->SetRelativeLocation(FVector(0.f, 0.f, 0.f));


	//���� ã�ƿ���
	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh
	(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube''"));
	
	if (FindMesh.Succeeded())
	{
		//ã�� ��ü�� �Լ��� ���ؼ� ����
		Head->SetStaticMesh(FindMesh.Object);
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
	}


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//�������Ʈ Ŭ������ ������ �� _C�� �ٿ������
	ConstructorHelpers::FClassFinder<AR1Actor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_R1Actor.BP_R1Actor_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}

}

// ���� ������ ���õ� �κ�
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT(""), Actors);

	if (Actors.Num() > 0)
	{
		Target = Actors[0];
	}

	FVector Loaction = { 0.f,0.f,0.f };
	FRotator rotator = { 0.f,0.f,0.f };

	//actor ����
	//Actor = GetWorld()->SpawnActor<AR1Actor>(Loaction, rotator);
	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));

	//dynamic_cast == Cast<>

	//5�� �ڿ� ����
	Actor->SetLifeSpan(5.f);
	//actor����
	GetWorld()->DestroyActor(Actor);
	
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target != nullptr)
	{
		float Speed = 50.f;
		float Distance = DeltaTime * Speed;

		FVector Location = GetActorLocation();

		FVector DirectionVector = Target->GetActorLocation() - Location;
		DirectionVector.Normalize();

		//������ǥ�� �������� �� ������ǥ ��ġ�� ������
		AddActorWorldOffset(DirectionVector * Distance);
	}
}

