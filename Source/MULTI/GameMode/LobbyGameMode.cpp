// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	constexpr int32 PlayersNeeded = 2;

	if (const int32 TotalPlayerCount = GameState.Get()->PlayerArray.Num(); TotalPlayerCount >= PlayersNeeded)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Launching Match..."));
		}

		if (UWorld* World = GetWorld())
		{
			bUseSeamlessTravel = true;

			// The trick is here...
			World->SeamlessTravel("/Game/Maps/BlasterMap?listen");
		}
		else
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to get world!"));
			}
		}
	}
}
