// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values

//스마트 포인트 개념가 아닌 가비지컬렉션 느낌
	//상호참조가 없음 트리를 통해 연결된 참조되었는지 확인
	//루트 노드를 통해서 그래프에서 누가 나를 기억하는지 확인가능

	//UR1Object* obj = NewObject<UR1Object>();
	//obj->AddToRoot() //루트 노드에 넣기

	//GEngine->ForceGarbageCollection(); 강제로 가비지 컬렉션 호출

AR1Actor::AR1Actor()
{
 	//CDO UObject를 상속받으면 리플렉션 시스템에 의해서 UClass객체를 만들어주고 이 안에 CDO라고 이 객체 사본을 만들어줌
	PrimaryActorTick.bCanEverTick = true;
	
	//staticmesh 생성 에디터상에서 바로 Box로 나옴
	//UObject클래스를 상속받은 아이들은 메타데이터가 UHD에 의해서 CDO객체 사본, UClass 갹체가 나옴
	//이 COD객체를 가져와서 반환을 해줌 (FObjectFinder, FClassFinder)
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	RootComponent = Body;//가장 최상위 부모
	Body->SetRelativeScale3D(FVector(2.f, 3.f, 0.5f));

	//Rotaion은 y z x순으로
	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body); //Body의 자식으로
	Wing->SetRelativeLocationAndRotation(FVector(55,-72,88), FRotator(0,90,0));
	Wing->SetRelativeScale3D(FVector(3.75f, 0.25f, 0.5f));

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body); //Body의 자식으로
	Head->SetRelativeLocationAndRotation(FVector(105, 36, 48), FRotator(0, 0, 0));
	Head->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	Wing->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Head->SetRelativeLocation(FVector(0.f, 0.f, 0.f));


	//에셋 찾아오기
	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh
	(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube''"));
	
	if (FindMesh.Succeeded())
	{
		//찾은 객체를 함수를 통해서 셋팅
		Head->SetStaticMesh(FindMesh.Object);
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
	}


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//블루프린트 클래스를 가져올 때 _C를 붙여줘야함
	ConstructorHelpers::FClassFinder<AR1Actor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_R1Actor.BP_R1Actor_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}

}

// 게임 로직과 관련된 부분
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

	//actor 생성
	//Actor = GetWorld()->SpawnActor<AR1Actor>(Loaction, rotator);
	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));

	//dynamic_cast == Cast<>

	//5초 뒤에 삭제
	Actor->SetLifeSpan(5.f);
	//actor삭제
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

		//월드좌표를 기준으로 내 월드좌표 위치에 더해줌
		AddActorWorldOffset(DirectionVector * Distance);
	}
}

