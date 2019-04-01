// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdTypeMenuParent.h"
#include "AppodealComponent.h"
#include "NonSkippableMenuParent.generated.h"

/**
 * 
 */
UCLASS()
class APPODEALCPPDEMO_API UNonSkippableMenuParent : public UIAdTypeMenuParent
{
	GENERATED_BODY()
public:
    AdType getAdType() override;
};
