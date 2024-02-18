// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Door.h"
#include "DrawDebugHelpers.h"

#include "Math/Vector.h"
// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	
	SetRootComponent(capsule);


	birdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	birdMesh->SetupAttachment(GetRootComponent());
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	linetraceLenght = 350;
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABird::MoveForward(float Value)
{
	if ((Value != 0)&&(Controller!=nullptr)) {

		FVector Forward=GetActorForwardVector();
		AddMovementInput(Forward, Value);

	}
}

void ABird::Interact()
{
	if (capsule == nullptr) {
		return;

	}

	FHitResult HitResult;
	FVector Start = capsule->GetComponentLocation();
	Start += capsule->GetForwardVector() * 50.0f;
	FVector End = Start + capsule->GetForwardVector() * linetraceLenght;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f);
	DrawDebugPoint(GetWorld(),End, 20.f,FColor::Red, false, 2.f);
	DrawDebugPoint(GetWorld(), Start, 20.f, FColor::Blue, false, 2.f);
	AActor* Actor = HitResult.GetActor();
	
	ADoor *Door=Cast<ADoor>(HitResult.GetActor());

	if (Door!=nullptr) {
		Door->OnInteract();

	}
	else {
		if(Actor!=nullptr)
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString(Actor->GetActorNameOrLabel()));
	}
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"),this, &ABird::MoveForward);
	PlayerInputComponent->BindAction("Interact",IE_Pressed,this,&ABird::Interact);

}

