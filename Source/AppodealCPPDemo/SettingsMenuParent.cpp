// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsMenuParent.h"
#include "AppodealComponent.h"

bool USettingsMenuParent::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) { return false; }
    
    if(enableChildButton) disableSmartBannersButton->OnClicked.AddDynamic(this, &USettingsMenuParent::disableSmartBanners);
    if(disableBannerAnimationButton) disableBannerAnimationButton->OnClicked.AddDynamic(this, &USettingsMenuParent::disableBannerAnimation);
    if(disable728x90BannersButton) disable728x90BannersButton->OnClicked.AddDynamic(this, &USettingsMenuParent::disable728x90Banners);
    if(disableLocationButton) disableLocationButton->OnClicked.AddDynamic(this, &USettingsMenuParent::disableLocation);
    if(disableStorageButton) disableStorageButton->OnClicked.AddDynamic(this, &USettingsMenuParent::disableStorage);
    if(enableTestingButton) enableTestingButton->OnClicked.AddDynamic(this, &USettingsMenuParent::enableTesting);
    if(enableLoggingButton) enableLoggingButton->OnClicked.AddDynamic(this, &USettingsMenuParent::enableLogging);
    if(disableNetworkButton) disableNetworkButton->OnClicked.AddDynamic(this, &USettingsMenuParent::disableNetwork);
    if(muteVideoButton) muteVideoButton->OnClicked.AddDynamic(this, &USettingsMenuParent::muteVideo);
    if(enableChildButton) enableChildButton->OnClicked.AddDynamic(this, &USettingsMenuParent::enableChild);
    if(segmentFilterStringButton) segmentFilterStringButton->OnClicked.AddDynamic(this, &USettingsMenuParent::segmentFilterString);
    if(segmentFilterBooleanButton) segmentFilterBooleanButton->OnClicked.AddDynamic(this, &USettingsMenuParent::segmentFilterBoolean);
    if(segmentFilterIntegerButton) segmentFilterIntegerButton->OnClicked.AddDynamic(this, &USettingsMenuParent::segmentFilterInteger);
    if(segmentFilterFloatButton) segmentFilterFloatButton->OnClicked.AddDynamic(this, &USettingsMenuParent::segmentFilterFloat);
    if(trackPurchaseButton) trackPurchaseButton->OnClicked.AddDynamic(this, &USettingsMenuParent::trackPurchase);
    if(showTestScreenButton) showTestScreenButton->OnClicked.AddDynamic(this, &USettingsMenuParent::showTestScreen);
    if(setExtraDataStringButton) setExtraDataStringButton->OnClicked.AddDynamic(this, &USettingsMenuParent::setExtraDataString);
    if(setExtraDataBooleanButton) setExtraDataBooleanButton->OnClicked.AddDynamic(this, &USettingsMenuParent::setExtraDataBoolean);
    if(setExtraDataIntButton) setExtraDataIntButton->OnClicked.AddDynamic(this, &USettingsMenuParent::setExtraDataInt);
    if(setExtraDataFloatButton) setExtraDataFloatButton->OnClicked.AddDynamic(this, &USettingsMenuParent::setExtraDataFloat);
    if(backButton) backButton->OnClicked.AddDynamic(this, &USettingsMenuParent::back);
    
    return true;
}

void USettingsMenuParent::disableSmartBanners()
{
    UAppodealComponent::setSmartBanners(false);
}

void USettingsMenuParent::disableBannerAnimation()
{
    UAppodealComponent::setBannerAnimation(false);
}

void USettingsMenuParent::disable728x90Banners()
{
    UAppodealComponent::set728x90Banners(false);
}

void USettingsMenuParent::disableLocation()
{
    UAppodealComponent::disableLocationPermissionCheck();
}

void USettingsMenuParent::disableStorage()
{
    UAppodealComponent::disableWriteExternalStoragePermissionCheck();
}

void USettingsMenuParent::enableTesting()
{
    UAppodealComponent::setTesting(true);
}

void USettingsMenuParent::enableLogging()
{
    UAppodealComponent::setLogLevel(LogLevel::verbose);
}

void USettingsMenuParent::disableNetwork()
{
    FString networkName = disableNetworkTextBox->GetText().ToString();
    UAppodealComponent::disableNetwork(networkName, AdType::INTERSTITIAL | AdType::BANNER | AdType::NON_SKIPPABLE_VIDEO| AdType::REWARDED_VIDEO);
}

void USettingsMenuParent::muteVideo()
{
    UAppodealComponent::muteVideoIfCallsMuted(true);
}

void USettingsMenuParent::enableChild()
{
    UAppodealComponent::setChildDirectedTreatment(true);
}

void USettingsMenuParent::segmentFilterString()
{
    FString name = filterStringNameTextBox->GetText().ToString();
    FString value = filterStringValueTextBox->GetText().ToString();
    UAppodealComponent::setSegmentFilter(name, value);
}

void USettingsMenuParent::segmentFilterBoolean()
{
    FString name = filterBooleanNameTextBox->GetText().ToString();
    bool value = filterBooleanValueCheckbox->IsChecked();
    UAppodealComponent::setSegmentFilter(name, value);
}

void USettingsMenuParent::segmentFilterInteger()
{
    FString name = filterIntegerNameTextBox->GetText().ToString();
    FString value = filterIntegerValueTextBox->GetText().ToString();
    UAppodealComponent::setSegmentFilter(name, FCString::Atoi(*value));
}

void USettingsMenuParent::segmentFilterFloat()
{
    FString name = filterFloatNameTextBox->GetText().ToString();
    FString value = filterFloatValueTextBox->GetText().ToString();
    UAppodealComponent::setSegmentFilter(name, FCString::Atof(*value));
}

void USettingsMenuParent::trackPurchase()
{
    FString amount = purchaseAmountTextBox->GetText().ToString();
    FString name = purchaseCurrencyTextBox->GetText().ToString();
    UAppodealComponent::trackInAppPurchase(FCString::Atof(*amount), name);
}


void USettingsMenuParent::showTestScreen()
{
    UAppodealComponent::startTestScreen();
}


void USettingsMenuParent::setExtraDataString()
{
    FString name = extraDataStringNameTextBox->GetText().ToString();
    FString value = extraDataStringValueTextBox->GetText().ToString();
    UAppodealComponent::setExtraData(name, value);
}

void USettingsMenuParent::setExtraDataBoolean()
{
    FString name = extraDataBoolNameTextBox->GetText().ToString();
    bool value = extraDataBooleanValueCheckbox->IsChecked();
    UAppodealComponent::setExtraData(name, value);
}

void USettingsMenuParent::setExtraDataInt()
{
    FString name = extraDataIntNameTextBox->GetText().ToString();
    FString value = extraDataIntValueTextBox->GetText().ToString();
    UAppodealComponent::setExtraData(name, FCString::Atoi(*value));
}

void USettingsMenuParent::setExtraDataFloat()
{
    FString name = extraDataFloatNameTextBox->GetText().ToString();
    FString value = extraDataFloatValueTextBox->GetText().ToString();
    UAppodealComponent::setExtraData(name, FCString::Atof(*value));
}

void USettingsMenuParent::back()
{
    removeAllWidgets();
    UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuMain, "MainMenu");
    menu->AddToViewport();
}

void USettingsMenuParent::removeAllWidgets()
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
