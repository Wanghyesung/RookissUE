// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"

AMyPlayerController::AMyPlayerController(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//������ �θ� ȣ��

	//������ �ִ� �̱���(�÷��̾��� �����ֱ�?�� ����)


	if (auto* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(GetLocalPlayer()))
	{
		//�� �������ؽ�Ʈ�� ����, �켱���� 0
		SubSystem->AddMappingContext(InputMappingContext, 0);
	}
	

}

//
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//enhancedInputComponent��������
	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		//�̺�Ʈ �κ� ���� (� �Լ��� ������) �ݹ��Լ� ��� 
		EnhancedInputComponent->BindAction(TestAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Test);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Turn);

	}


}

void AMyPlayerController::Input_Test(const FInputActionValue& InputValue)
{

}

void AMyPlayerController::Input_Move(const FInputActionValue& InputValue)
{
	//vector2D�� ������ �� ��������
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	//x���� ��
	if (MovementVector.X != 0)
	{
		//FVector::ForwardVector 1,0,0�̶�� ���� ���峪 ������ �ƴ�
		//FVector Dir = FVector::ForwardVector * MovementVector.X;
		//GetPawn()->AddActorWorldOffset(Dir* 50.f);

		FRotator Rotator = GetControlRotation();//playercontroller�� ȸ������ ������
		FVector Dir = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));//���� �ٶ󺸰��ִ� ����
		GetPawn()->AddMovementInput(Dir, MovementVector.X);//������� -> �̵��� movent������Ʈ���� ����
		//moventcomponent �ø��� �� �ϳ��� �������־����
		
		//movementcomponent�� ����ϸ� 1���� ���� ���� ������ ���� �ʹ� �۾���
	}
	if (MovementVector.Y != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Dir = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));//���� �ٶ󺸰��ִ� ����
		GetPawn()->AddMovementInput(Dir, MovementVector.Y);//�������
	}
}

void AMyPlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	//ȸ���� ���õ� ����� playercontroller�� ������
	float val = InputValue.Get<float>(); //ù��° ���� �������� Vector2D.x
	AddYawInput(val);//z playercontrollerActor�� ȸ������ ������
}
