// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdTypeMenuParent.h"
#include "AppodealComponent.h"
#include "RewardedMenuParent.generated.h"

/**
 * 
 */
UCLASS()
class APPODEALCPPDEMO_API URewardedMenuParent : public UIAdTypeMenuParent
{
	GENERATED_BODY()
public:
    AdType getAdType() override;
    bool Initialize() override;
	
    UPROPERTY(meta = (BindWidget))
    UButton *getRewardButton;
    
    UFUNCTION()
    void getReward();
};
