// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.generated.h"

UCLASS()
class TESTTASK_API AMyCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = "MyFunc")
	TArray<AActor*> FindNearests(TArray<AActor*> Enemies, int32 n) const;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
