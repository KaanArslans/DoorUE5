// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class MYPROJECT5_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float amplitude = 0.25f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float timeCponstant = 5.f;
	UFUNCTION(BlueprintPure)
	float transformedSin(float value);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess="true"))
	float runningTime;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* itemMesh;
	
};
