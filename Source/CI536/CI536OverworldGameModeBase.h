// Copyright © 2020 Jack C. Lloyd.

#pragma once

#pragma region INCLUDES

#include "CoreMinimal.h"
#include "CI536GameModeBase.h"
#include "CI536OverworldGameModeBase.generated.h"

#pragma endregion

#pragma region CLASSES

/**
 * Overworld Game Mode Base.
 */
UCLASS()
class CI536_API ACI536OverworldGameModeBase : public ACI536GameModeBase
{
	GENERATED_BODY()
	
private:
	/* An arry of the overworld pads. */
	TArray<class AActor*> Pads;

	/* The active player's controller ID. */
	int32 ActivePlayerControllerID = 0;

	/* The active rank. */
	int32 ActivePlayerRank = -1;

	/* The active player's pad. */
	class ACI536Pad* ActivePad = nullptr;

	/* The active player's pad history. */
	TArray<class ACI536Pad*> History;

protected:
	virtual void BeginPlay() override;

	/* Refresh the active player. */
	void Refresh();

	/* Try to move to the specified pad. */
	bool Try(class ACI536Pad* InPad);

public:
	/* Try to move North. */
	UFUNCTION( BlueprintCallable )
		bool North(int32 InPlayerControllerID);

	/* Try to move East. */
	UFUNCTION( BlueprintCallable )
		bool East(int32 InPlayerControllerID);

	/* Try to move South. */
	UFUNCTION( BlueprintCallable )
		bool South(int32 InPlayerControllerID);

	/* Try to move north. */
	UFUNCTION( BlueprintCallable )
		bool West(int32 InPlayerControllerID);

	/* Try to confirm the path. */
	UFUNCTION( BlueprintCallable )
		bool Confirm(int32 InPlayerControllerID);
};

#pragma endregion