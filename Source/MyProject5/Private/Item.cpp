// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "DrawDebugHelpers.h"
#include "MyProject5/MyProject5.h"
#include <Engine/TriggerBox.h>
// Sets default values


AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	itemMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = itemMesh;
}


// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(1,60.f,FColor::Cyan,FString("succesfulls actor"));
	//UWorld*world = GetWorld();
	//SetActorLocation(FVector(1080, 1500, 60));
	
    
   
    

	

}

float AItem::transformedSin(float value)
{
	return  amplitude * FMath::Sin(value * timeCponstant);
}



// Called every frame
void AItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //float MovementRate = 200.f;
	runningTime += DeltaTime;
	//float deltax = amplitude * FMath::Sin(runningTime * timeCponstant);

   

    // Check if the sphere is currently moving towards the target location
	//AddActorWorldOffset(FVector(deltax,0.f,0.f));
   DRAW_SPEHERE(GetActorLocation())
  
      
}



