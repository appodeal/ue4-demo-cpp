// Fill out your copyright notice in the Description page of Project Settings.

#include "RewardedMenuParent.h"

AdType URewardedMenuParent::getAdType()
{
    return AdType::REWARDED_VIDEO;
}

bool URewardedMenuParent::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) { return false; }
    if (getRewardButton)
    {
        getRewardButton->OnClicked.AddDynamic(this, &URewardedMenuParent::getReward);
    }
    
    return true;
}

void URewardedMenuParent::getReward(){
    float amount = UAppodealComponent::getRewardAmount("default");
    FString name = UAppodealComponent::getRewardName("default");
    showText(FString::Printf(TEXT("Reward: %.2f %s"), amount, *name));
}
