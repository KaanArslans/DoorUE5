// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DOORFRAME"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DOOR"));
	RootComponent = DoorFrame;
	Door->SetupAttachment(DoorFrame);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	if (CurveFloat) {
		FOnTimelineFloat TimeLineProgress;
		TimeLineProgress.BindDynamic(this, &ADoor::openDoor);
		TimeLine.AddInterpFloat(CurveFloat, TimeLineProgress);
	}
}

void ADoor::openDoor(float value)
{
	FRotator rotator = FRotator(0.f, angle * value, 0.f);
	Door->SetRelativeRotation(rotator);

}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeLine.TickTimeline(DeltaTime);
}

void ADoor::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("dOOR OPens"));
	if (isDoorClosed) {

		TimeLine.Play();
	}
	else {
		TimeLine.Reverse();
	}
	isDoorClosed = !isDoorClosed;
}

