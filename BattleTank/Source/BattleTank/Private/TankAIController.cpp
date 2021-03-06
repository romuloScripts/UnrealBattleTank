// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//auto PlayerTank = GetPlayerTank();
	/*if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player %s"), *(PlayerTank->GetName()));
	}*/
}

//ATank* ATankAIController::GetControlledTank() const
//{
//	return Cast<ATank>(GetPawn());
//}
//
//ATank* ATankAIController::GetPlayerTank() const
//{
//	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//	if (!PlayerPawn) { return nullptr;}
//	return Cast<ATank>(PlayerPawn);
//}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (GetPlayerTank())
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO Move towards the player

		// Aim towards the player
		//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO limit firing rate
	}
}

