// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdTypeMenuParent.h"
#include "AppodealComponent.h"
#include "BannerMenuParent.generated.h"

/**
 * 
 */
UCLASS()
class APPODEALCPPDEMO_API UBannerMenuParent : public UIAdTypeMenuParent
{
	GENERATED_BODY()
public:
    AdType getAdType() override;
    bool Initialize() override;
    
    UPROPERTY(meta = (BindWidget))
    UButton *hideButton;
    UPROPERTY(meta = (BindWidget))
    UButton *destroyButton;
    
    UFUNCTION()
    void hide();
    UFUNCTION()
    void destroy();
};
