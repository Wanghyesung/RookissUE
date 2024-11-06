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
	//무조건 부모 호출

	//범위가 있는 싱글톤(플레이어의 생명주기?를 따름)


	if (auto* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(GetLocalPlayer()))
	{
		//내 맵핑컨텍스트랑 연결, 우선순위 0
		SubSystem->AddMappingContext(InputMappingContext, 0);
	}
	

}

//
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//enhancedInputComponent가져오기
	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		//이벤트 부분 연결 (어떤 함수랑 엮을지) 콜백함수 등록 
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
	//vector2D로 설정한 값 가져오기
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	//x축이 앞
	if (MovementVector.X != 0)
	{
		//FVector::ForwardVector 1,0,0이라는 벡터 월드나 로컬이 아님
		//FVector Dir = FVector::ForwardVector * MovementVector.X;
		//GetPawn()->AddActorWorldOffset(Dir* 50.f);

		FRotator Rotator = GetControlRotation();//playercontroller의 회전값을 가져옴
		FVector Dir = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));//내가 바라보고있는 방향
		GetPawn()->AddMovementInput(Dir, MovementVector.X);//방향기입 -> 이동은 movent컴포넌트에서 해줌
		//moventcomponent 시리즈 중 하나를 가지고있어야함
		
		//movementcomponent를 사용하면 1보다 작은 값을 넣으면 힘이 너무 작아짐
	}
	if (MovementVector.Y != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Dir = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));//내가 바라보고있는 방향
		GetPawn()->AddMovementInput(Dir, MovementVector.Y);//방향기입
	}
}

void AMyPlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	//회전과 관련된 기능은 playercontroller가 관리함
	float val = InputValue.Get<float>(); //첫번째 값만 가져오기 Vector2D.x
	AddYawInput(val);//z playercontrollerActor에 회전값을 변경함
}
