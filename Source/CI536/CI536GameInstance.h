// Copyright © 2020 Jack C. Lloyd.

#pragma once

#pragma region INCLUDES

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CI536Pad.h"
#include "CI536GameInstance.generated.h"

#pragma endregion

#pragma region STRUCTS

/**
 * Player Information.
 */
USTRUCT( BlueprintType )
struct FPlayerInformation
{
	GENERATED_BODY()

	/* The player's ranking (i.e., 1st, 2nd, 3rd, or 4th). */
	UPROPERTY( BlueprintReadOnly )
		int32 Rank = -1;

	/* The player's pad index. */
	UPROPERTY( BlueprintReadOnly )
		int32 Index = -1;

	/* The player's credits. */
	UPROPERTY( BlueprintReadOnly )
		int32 Credits = 3; // TODO: Change to 0, currently hard-coded for testing purposes.
};

#pragma endregion

#pragma region CLASSES

/**
 * Game Instance.
 */
UCLASS()
class CI536_API UCI536GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/* The information of the player(s). */
	UPROPERTY( BlueprintReadOnly, VisibleDefaultsOnly )
		TArray<FPlayerInformation> PlayerInformation;

	/* The number of players (i.e., non-artificial intelligence). */
	UPROPERTY( BlueprintReadOnly, VisibleDefaultsOnly )
		int32 PlayerControllerCount = -1;

	/* Set the number of players (i.e., non-artificial intelligence). */
	UFUNCTION( BlueprintCallable )
		int32 SetPlayerControllerCount(int Count);
};

#pragma endregion