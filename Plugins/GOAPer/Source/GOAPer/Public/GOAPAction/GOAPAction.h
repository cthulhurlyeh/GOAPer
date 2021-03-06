#pragma once
#include "GOAPer.h"
#include "GOAPAtom.h"
#include "GOAPState.h"
#include "GOAPStateUI.h"
#include "GOAPAction.generated.h"


class AGOAPAIController;

UCLASS(Blueprintable, BlueprintType, meta = (ShowWorldContextPin))
class GOAPER_API UGOAPAction : public UObject
{
	GENERATED_BODY()

public:
	UGOAPAction(const class FObjectInitializer& ObjectInitializer);
	// Checks if the preconditions are satisfied by the current agent state
	UFUNCTION(BlueprintPure, Category = "GOAP Action")
	bool ArePreconditionsSatisfied(AGOAPAIController* controller);

	// Checks if the agent is within range of whatever it needs to be in range of
	UFUNCTION(BlueprintPure, Category = "GOAP Action")
	bool IsInRange(AGOAPAIController* controller);

	// Checks if the target state (effect) is already satisfied
	UFUNCTION(BlueprintPure, Category = "GOAP Action")
	bool AreEffectsSatisfied(AGOAPAIController* controller);

	// Called each frame while this is the active action, returns true when complete
	UFUNCTION(BlueprintNativeEvent, Category = "GOAP Action")
	bool Execute(AGOAPAIController* controller, float DeltaSeconds);
	virtual bool Execute_Implementation(AGOAPAIController* controller, float DeltaSeconds) { return false;};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GOAP Action")
	FString ActionDescription;

	FGOAPState PreConditions_Internal;
	FGOAPState Effects_Internal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GOAP Action")
	FGOAPStateUI PreConditions;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GOAP Action")
	FGOAPStateUI Effects;

	// Type of actor which is the target of the this action (if any)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP Action")
	TWeakObjectPtr<AActor> ActionTarget = nullptr;
	// Required range from target to perform action
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GOAP Action")
	float InteractionRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GOAP Action")
	bool ShouldInterruptMoveOnTargetAcquisition = false;

	void SetupDefaults();
	
	uint8 Cost;
};
