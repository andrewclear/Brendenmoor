// Fill out your copyright notice in the Description page of Project Settings.

#include "StatusEffect.h"

UStatusEffect::UStatusEffect()
{
}

UStatusEffect::~UStatusEffect()
{
}

void UStatusEffect::Clone(UStatusEffect *otherStatusEffect)
{
	if (otherStatusEffect == nullptr)
	{
		otherStatusEffect = NewObject<UStatusEffect>(UStatusEffect::StaticClass());
	}

	otherStatusEffect->Name = Name;
	otherStatusEffect->Icon = Icon;
	otherStatusEffect->ExpiresOnDeath = ExpiresOnDeath;
	otherStatusEffect->Duration = Duration;
	otherStatusEffect->ApplyPerTick = ApplyPerTick;
	otherStatusEffect->TickLength = TickLength;
	otherStatusEffect->RandomVariationPerTick = RandomVariationPerTick;
	otherStatusEffect->VariationAmount = VariationAmount;
	otherStatusEffect->ParticleEffect = ParticleEffect;

	for (auto& affectedStat : StatsAfffected)
	{
		otherStatusEffect->StatsAfffected.Add(affectedStat.Key, affectedStat.Value);
	}
}

void UStatusEffect::Start()
{

}

void UStatusEffect::OnTick()
{

}
