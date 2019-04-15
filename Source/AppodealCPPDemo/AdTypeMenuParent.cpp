// Fill out your copyright notice in the Description page of Project Settings.

#include "AdTypeMenuParent.h"
#include "AppodealComponent.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"

bool UIAdTypeMenuParent::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) { return false; }
    
    if (initializeButton)
    {
        initializeButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::initialize);
    }
    if (cacheButton)
    {
        cacheButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::cache);
    }
    if (showButton)
    {
        showButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::show);
    }
    if (getPredictedECPMButton)
    {
        getPredictedECPMButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::getPredictedECPM);
    }
    if (isInitialisedButton)
    {
        isInitialisedButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::isInitialized);
    }
    if (isAutoCacheEnabledButton)
    {
        isAutoCacheEnabledButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::isAutoCacheEnabled);
    }
    if (canShowButton)
    {
        canShowButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::canShow);
    }
    if (isLoadedButton)
    {
        isLoadedButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::isLoaded);
    }
    if (backButton)
    {
        backButton->OnClicked.AddDynamic(this, &UIAdTypeMenuParent::back);
    }
    return true;
}

AdType UIAdTypeMenuParent::getAdType()
{
    return AdType::INTERSTITIAL;
}

void UIAdTypeMenuParent::removeAllWidgets()
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

void UIAdTypeMenuParent::initialize()
{
    FString appKey;
    #if PLATFORM_ANDROID
    appKey = FString(TEXT("fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f"));
    #elif PLATFORM_IOS
    appKey = FString(TEXT("4b46ef930cd37cf11da84ae4d41019abb7234d5bbce3f000"));
    #endif
    if(disableAutoCacheCheckbox->IsChecked()){
        UAppodealComponent::setAutoCache(getAdType(), false);
        cacheButton->SetVisibility(ESlateVisibility::Visible);
    }
    if(enableTriggerOnLoadedOnPrecacheCheckbox->IsChecked()) UAppodealComponent::setTriggerOnLoadedOnPrecache(getAdType(), true);
    UAppodealComponent::initialize(appKey, true, getAdType());
}

void UIAdTypeMenuParent::cache()
{
    UAppodealComponent::cache(getAdType());
}

void UIAdTypeMenuParent::show()
{
    UAppodealComponent::show(getAdType());
}

void UIAdTypeMenuParent::getPredictedECPM()
{
    float ecpm = UAppodealComponent::getPredictedEcpm(getAdType());
    showText(FString::Printf(TEXT("ECPM: %f"), ecpm));
}

void UIAdTypeMenuParent::isInitialized()
{
    bool init = UAppodealComponent::isInitialized(getAdType());
    showText(FString::Printf(TEXT("Initialized: %d"), init));
}

void UIAdTypeMenuParent::isAutoCacheEnabled()
{
    bool autocache = UAppodealComponent::isAutoCacheEnabled(getAdType());
    showText(FString::Printf(TEXT("AutoCache enabled: %d"), autocache));
}

void UIAdTypeMenuParent::canShow()
{
    bool cs = UAppodealComponent::canShow(getAdType(), "default");
    showText(FString::Printf(TEXT("Can Show: %d"), cs));
}

void UIAdTypeMenuParent::isLoaded()
{
    bool loaded = UAppodealComponent::isLoaded(getAdType());
    showText(FString::Printf(TEXT("Loaded: %d"), loaded));
}

void UIAdTypeMenuParent::back()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuMain, "MainMenu");
    menu->AddToViewport();
}

void UIAdTypeMenuParent::showText(FString text)
{
    statusTextBox->SetText(FText::FromString(text));
}
