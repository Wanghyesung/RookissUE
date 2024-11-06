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

	//������ ĸ���� ��Ʈ�� ���� COD�� ã��
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->InitCapsuleSize(34.f, 88.f);
	RootComponent = CapsuleComponent;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletaMesh"));
	Mesh->SetupAttachment(CapsuleComponent);//�ڽ����� ����

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(CapsuleComponent);//�ڽ����� ����

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	//������ => ��������͸� ���� ����� �Ӽ��� ���� ���߱�
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

// Input ���õ� �ڵ� 
// ���⼭ ���Ѵٸ� �÷��̾� ��Ʈ�ѷ����� �ϴ°� ����
void AR1Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

