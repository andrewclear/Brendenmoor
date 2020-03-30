#pragma once

//#include "CoreMinimal.h"
#include "GlobalEventSubscriber.generated.h"

/* must have BlueprintType as a specifier to have this interface exposed to blueprints
   with this line you can easily add this interface to any blueprint class */
UINTERFACE(BlueprintType)
class BRENDENMOOR_API UGlobalEventSubscriber : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class BRENDENMOOR_API IGlobalEventSubscriber
{
	GENERATED_IINTERFACE_BODY()

public:
	//classes using this interface must implement ReactToHighNoon
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Global Event System")
	bool SubscribeToEvents();

	//classes using this interface may implement ReactToMidnight
	//UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Global Event System")
	bool UnsubscribeFromEvents();
};



