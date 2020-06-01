// Copyright © 2020 Jack C. Lloyd.

#pragma once

#pragma region INCLUDES

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CI536GameModeBase.generated.h"

#pragma endregion

#pragma region CLASSES

/**
 * Game Mode Base.
 */
UCLASS()
class CI536_API ACI536GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
  /* Cache a casted reference for performance. */
  class UCI536GameInstance* GameInstance = nullptr;

  virtual void BeginPlay();

public:
  /* The number of players (i.e., non-artificial intelligence). */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
  int32 PlayerControllerCount = -1;

  /* The array of player controllers (i.e., non-artificial intelligence). */
  UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
  TArray<class APlayerController*> PlayerControllers;

  /* The array of player actors (i.e., non-artificial intelligence). */
  UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
  TArray<class AActor*> PlayerActors;

  /* The array of player materials (i.e., red, green, blue, and yellow). */
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
  TArray<class UMaterialInterface*> PlayerMaterials;
};

#pragma endregion