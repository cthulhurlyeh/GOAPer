
#pragma once

#include "GOAPAction.h"
#include "GOAPNode.h"
#include "GOAPPlanner.generated.h"

class AGOAPAIController;

/**
*
*/
UCLASS()
class GOAPER_API UGOAPPlanner : public UObject
{
	GENERATED_UCLASS_BODY()
	UPROPERTY()
	TArray<FGOAPNode> OpenNodes;
	UPROPERTY()
	TArray<FGOAPNode> ClosedNodes;
	UPROPERTY()
	TArray<TWeakObjectPtr<UGOAPAction>> GOAPPlan;
public:

	TArray<TWeakObjectPtr<UGOAPAction>> Plan(UObject* aOuter, const uint8 aState,
		const bool aValue,
		TArray<UGOAPAction*>* aActions,
		FGOAPState* aCurrentState,
		AGOAPAIController& controller);
};
