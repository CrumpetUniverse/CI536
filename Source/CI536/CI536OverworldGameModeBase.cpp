// Copyright © 2020 Jack C. Lloyd.


#include "CI536OverworldGameModeBase.h"
#include "CI536GameInstance.h"
#include "CI536Pad.h"

// Copyright © 1998 Epic Games, Inc.

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/RandomStream.h"

void ACI536OverworldGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	/* Get the pads and sort them for safe index access. */
	UGameplayStatics::GetAllActorsOfClass(this, ACI536Pad::StaticClass(), Pads);
	Pads.Sort();

	if (IsValid(GameInstance))
	{
		FRandomStream RandomStream;
		RandomStream.Initialize(FName(EName::NAME_None));

		/*If a pad is not assigned, assaign a random one. */
		for (auto& PlayerInformation : GameInstance->PlayerInformation)
		{
			if (PlayerInformation.Index == -1)
			{
				PlayerInformation.Index = RandomStream.RandRange(0, Pads.Num() - 1);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to access game instance!"));
	}









	// WHO;'S GO TISS IT?????

	ActivePad = Cast<ACI536Pad>(Pads[GameInstance->PlayerInformation[ActivePlayerControllerID].Index]);

	if (!IsValid(ActivePad))
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to access active pad!"));
	}

	History.Empty(); /// INITIAL HISTORY

	/* Initial refresh. */
	Refresh();
}

void ACI536OverworldGameModeBase::Refresh()
{
	UE_LOG(LogTemp, Warning, TEXT("ID: %d Credits: %d"), ActivePlayerControllerID, GameInstance->PlayerInformation[ActivePlayerControllerID].Credits);

	FVector Location = ActivePad->GetActorLocation();
	PlayerActors[ActivePlayerControllerID]->SetActorLocation(Location);
}

bool ACI536OverworldGameModeBase::Try(class ACI536Pad* InPad)
{
	if (IsValid(InPad) && !InPad->IsLocked())
	{
		if (History.Num() != 0 && History.Top() == InPad)
		{
			ActivePad = History.Pop();
			GameInstance->PlayerInformation[ActivePlayerControllerID].Credits++; // verbose

			Refresh();

			return true;
		}
		else
		{
			if (GameInstance->PlayerInformation[ActivePlayerControllerID].Credits > 0)  // verbose
			{
				History.Push(ActivePad);
				ActivePad = InPad;
				GameInstance->PlayerInformation[ActivePlayerControllerID].Credits--;  // verbose

				Refresh();

				return true;
			}
		}
	}

	return false;
}

bool ACI536OverworldGameModeBase::North(int32 InPlayerControllerID)
{
	if (InPlayerControllerID != ActivePlayerControllerID)
		return false;

	return Try(ActivePad->NorthPad);
}

bool ACI536OverworldGameModeBase::East(int32 InPlayerControllerID)
{
	if (InPlayerControllerID != ActivePlayerControllerID)
		return false;

	return Try(ActivePad->EastPad);
}

bool ACI536OverworldGameModeBase::South(int32 InPlayerControllerID)
{
	if (InPlayerControllerID != ActivePlayerControllerID)
		return false;

	return Try(ActivePad->SouthPad);
}

bool ACI536OverworldGameModeBase::West(int32 InPlayerControllerID)
{
	if (InPlayerControllerID != ActivePlayerControllerID)
		return false;

	return Try(ActivePad->WestPad);
}

bool ACI536OverworldGameModeBase::Confirm(int32 InPlayerControllerID)
{
	if (InPlayerControllerID != ActivePlayerControllerID)
		return false;

	return true;
}
