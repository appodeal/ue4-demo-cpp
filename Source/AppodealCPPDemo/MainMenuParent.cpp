// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuParent.h"

bool UMainMenuParent::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) { return false; }
    
    if (interstitialButton)
    {
        interstitialButton->OnClicked.AddDynamic(this, &UMainMenuParent::showInterstitialMenu);
    }
    if (bannerButton)
    {
        bannerButton->OnClicked.AddDynamic(this, &UMainMenuParent::showBannerMenu);
    }
    if (rewardedButton)
    {
        rewardedButton->OnClicked.AddDynamic(this, &UMainMenuParent::showRewardedMenu);
    }
    if (nonSkippableButton)
    {
        nonSkippableButton->OnClicked.AddDynamic(this, &UMainMenuParent::showNonSkippableMenu);
    }
    if (settingsButton)
    {
        settingsButton->OnClicked.AddDynamic(this, &UMainMenuParent::showSettingsMenu);
    }
    return true;
}

void UMainMenuParent::removeAllWidgets()
{
    for (TObjectIterator<UUserWidget> Itr; Itr; ++Itr)
    {
        UUserWidget* LiveWidget = *Itr;
        
        /* If the Widget has no World, Ignore it (It's probably in the Content Browser!) */
        if (!LiveWidget->GetWorld())
        {
            continue;
        }
        else
        {
            LiveWidget->RemoveFromParent();
        }
    }
}

void UMainMenuParent::showInterstitialMenu()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuInterstitial, "InterstitialMenu");
    menu->AddToViewport();
}


void UMainMenuParent::showBannerMenu()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuBanner, "BannerMenu");
    menu->AddToViewport();
}

void UMainMenuParent::showRewardedMenu()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuRewarded, "RewardedMenu");
    menu->AddToViewport();
}

void UMainMenuParent::showNonSkippableMenu()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuNonSkippable, "NonSkippableMenu");
    menu->AddToViewport();
}

void UMainMenuParent::showSettingsMenu()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuSettings, "SettingsMenu");
    menu->AddToViewport();
}
