// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Pawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AR1Pawn::AR1Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//보통은 캡슈을 루트로 잡음 COD를 찾음
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->InitCapsuleSize(34.f, 88.f);
	RootComponent = CapsuleComponent;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletaMesh"));
	Mesh->SetupAttachment(CapsuleComponent);//자식으로 들어가기

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(CapsuleComponent);//자식으로 들어가기

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	//설정값 => 블루프린터를 먼저 만들고 속성값 보고 맞추기
	SpringArm->TargetArmLength = 700.f;

	//Y Z X 
	Mesh->SetRelativeLocationAndRotation(FVector(0, 0, -88), FRotator(0, 90, 0));

}



// Called when the game starts or when spawned
void AR1Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AR1Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Input 관련된 코드 
// 여기서 안한다면 플레이어 컨트롤러에서 하는게 좋음
void AR1Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

