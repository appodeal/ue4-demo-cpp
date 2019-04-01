// Fill out your copyright notice in the Description page of Project Settings.

#include "BannerMenuParent.h"

AdType UBannerMenuParent::getAdType()
{
    return AdType::BANNER;
}

bool UBannerMenuParent::Initialize(){
    bool Success = Super::Initialize();
    if (!Success) return false;
    if (hideButton)
    {
        hideButton->OnClicked.AddDynamic(this, &UBannerMenuParent::hide);
    }
    if (destroyButton)
    {
        destroyButton->OnClicked.AddDynamic(this, &UBannerMenuParent::destroy);
    }
    return true;
}

void UBannerMenuParent::hide()
{
    UAppodealComponent::hide(getAdType());
}

void UBannerMenuParent::destroy()
{
    UAppodealComponent::destroy(getAdType());
}
