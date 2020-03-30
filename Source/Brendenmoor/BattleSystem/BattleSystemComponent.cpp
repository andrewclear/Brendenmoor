// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleSystemComponent.h"
#include "Skill.h"
#include "StatusEffect.h"
#include "EventSystem/GlobalEventSystem.h"
#include "XmlParser.h"
#include "Engine.h"

// Sets default values for this component's properties
UBattleSystemComponent::UBattleSystemComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

//void UBattleSystemComponent::ActivateSkill(USkill* skillToActivate)
void UBattleSystemComponent::ActivateSkill(UObject* skillToActivate)
{
	TestLoad();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Activate Skill called"));

	if (m_GameInstance == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("game instance is nullptr"));
	}
	else if (m_GameInstance->GlobalEvents == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("global events is nullptr"));
	}

	int32 result = 8 / 2 * (2 + 2);
	GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::FromInt(result));


	if (m_GameInstance != nullptr && m_GameInstance->GlobalEvents != nullptr)
	{
		USkill *skill = Cast<USkill>(skillToActivate);

		if (skill != nullptr) {
			m_GameInstance->GlobalEvents->OnQueueBattleCommand.Broadcast(skill);//skillToActivate);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("skill is nullptr"));
		}
	}
}

void UBattleSystemComponent::ApplyStatusEffect(UStatusEffect* statusEffect)
{
	UStatusEffect* newStatusEffect = nullptr;
	statusEffect->Clone(newStatusEffect);

	newStatusEffect->Start();
	m_ActiveStatusEffects.Add(newStatusEffect);
}

void UBattleSystemComponent::SetAutoAttackSkill(USkill* autoAttackSkill)
{
	m_AutoAttackSkill = autoAttackSkill;
}

void UBattleSystemComponent::TestLoad()
{
	FString oldFilename = FPaths::GameContentDir() + "test.xml";

	FXmlFile* xmlFile = new FXmlFile(oldFilename, EConstructMethod::Type::ConstructFromFile);
	if (xmlFile == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("xmlFile is nullptr"));
		return;
	}

	//FString filename = "test.xml"; // FPaths::ProjectContentDir() + "test.xml";
	//GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Red, filename);
	//GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Yellow, oldFilename);

	if (xmlFile->IsValid() == false) //xmlFile->LoadFile(oldFilename, EConstructMethod::Type::ConstructFromFile) == false)
	{
		FString errorMsg = xmlFile->GetLastError();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, errorMsg);
	}
	else
	{
		FXmlNode* xmlRoot = xmlFile->GetRootNode();
		if (xmlRoot == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("root node is nullptr"));
		}
		else
		{
			FXmlNode* childNode = xmlRoot->FindChildNode("skill");

			if (childNode == nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("child node is nullptr"));
			}
			else
			{
	
				FString returnString = childNode->GetAttribute("name");
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, returnString);
				FString errorMsg = xmlFile->GetLastError();
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, errorMsg);
			}
		}
	}
	/*
	FXmlNode* xmlRoot = xmlFile->GetRootNode();
	if (xmlRoot == nullptr)
		return;

	FXmlAttribute* xmlAttribute = new FXmlAttribute(TEXT("Name"), TEXT("MyGame"));
	if (xmlAttribute == nullptr)
		return;

	xmlRoot->SetContent(TEXT("Game"));

	xmlFile->Save(filename);
	xmlFile->Clear();

	delete xmlAttribute;
	*/
	delete xmlFile;
}
