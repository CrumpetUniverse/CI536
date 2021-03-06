// Copyright © 2020 Jack C. Lloyd.

#include "CI536GameInstance.h"

int UCI536GameInstance::SetPlayerControllerCount(int Count)
{
	/* A minimum of 1 and a maximum of 4 players, respectively. */
	PlayerControllerCount = Count < 1 ? 1 : Count > 4 ? 4 : Count;

	/* Empty and reallocate. */
	PlayerInformation.Empty();
	for (int32 i = 0; i < PlayerControllerCount; i++)
		PlayerInformation.Add(FPlayerInformation());

	return PlayerControllerCount;
}