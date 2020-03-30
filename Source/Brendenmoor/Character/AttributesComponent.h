// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Globals/GlobalEnums.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BRENDENMOOR_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributesComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Attributes, meta = (DisplayName = "Get the Value of a Specified Attribute"))
		int32 GetAttribute(EAttributes attribute, bool shouldClamp);

	UFUNCTION(BlueprintCallable, Category = Attributes, meta = (DisplayName = "Modify a Specified Attribute"))
		int32 ModifyResource(EAttributes attribute, int32 amount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TMap<EAttributes, int32> m_Attributes;
		
};
