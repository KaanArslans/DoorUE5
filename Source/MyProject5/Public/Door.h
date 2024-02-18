// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimeLineComponent.h"
#include "Door.generated.h"


UCLASS()
class MYPROJECT5_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimeline TimeLine;
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;
	bool isDoorClosed = true;

	UPROPERTY(EditAnywhere)
	float angle = 90.f;
	UFUNCTION()
	void openDoor(float value);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnInteract();
private:

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Door;
};
