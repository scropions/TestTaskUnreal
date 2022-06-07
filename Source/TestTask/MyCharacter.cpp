// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Math/Vector.h"
#include "Containers/SortedMap.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

AActor* AMyCharacter::GetActorNear(const FVector& pos, const TArray<AActor*>& Enemies, const TArray<AActor*>& ignore) const 
{
	int max = INT_MAX;
	AActor* result = nullptr;

	for (auto i : Enemies)
	{
		if (ignore.Num() > 0 && ignore.Find(i))
		{
			continue;
		}

		float distance = FVector::Distance(pos, i->GetActorLocation());

		if (max > distance)
		{
			max = distance;
			result = i;
		}
	}

	return result;
}

// Called when 



TArray<AActor*> AMyCharacter::FindNearests(const TArray<AActor*> Enemies, int32 n) const
{
	TArray<AActor*> result;
	TSortedMap<double, TArray<AActor*>> enemies; //because we can have two actor in the same position
	
	int countEnemies = n;

	if (Enemies.Num() < n)
	{
		countEnemies = Enemies.Num();
	}

	for (int i = 0; i < n; i++)
	{

	}

	auto pos = GetActorLocation();
	for (auto i : Enemies)
	{
		double distance = FVector::Dist(i->GetActorLocation(), pos);
		//UE_LOG(LogTemp, Warning, TEXT("Index:%i"), distance);
		if (!enemies.Contains(distance))
		{
			TArray<AActor*> initialize;
			enemies.Add(distance, initialize);
		}
		enemies[distance].Add(i);
	}

	auto it = enemies.CreateIterator();

	while (result.Num() < n)
	{

		result.Append(&(it->Value[0]), it->Value.Num());
		it.operator++();
	}

	return result;
}


//TArray<AActor*> AMyCharacter::FindNearests(const TArray<AActor*> Enemies, int32 n) const
//{
//	auto pos = GetActorLocation();
//	TArray<AActor*> result;
//	
//	for (int i = 0; i < n; i++)
//	{
//		auto enemy = GetActorNear(pos, Enemies, result);
//
//		if (enemy == nullptr)
//		{
//			break;
//		}
//
//		result.Add(enemy);
//	}
//
//	UE_LOG(LogTemp, Warning, TEXT("Log:%i"), result.Num());
//	
//	return result;
//}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

