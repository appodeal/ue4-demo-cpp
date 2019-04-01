// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/CheckBox.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"
#include "SettingsMenuParent.generated.h"

/**
 * 
 */
UCLASS()
class APPODEALCPPDEMO_API USettingsMenuParent : public UUserWidget
{
	GENERATED_BODY()
public:
    bool Initialize() override;
    
    UPROPERTY(meta = (BindWidget))
    UButton *disableSmartBannersButton;
    UFUNCTION()
    void disableSmartBanners();
    
    UPROPERTY(meta = (BindWidget))
    UButton *disableBannerAnimationButton;
    UFUNCTION()
    void disableBannerAnimation();
    
    UPROPERTY(meta = (BindWidget))
    UButton *disable728x90BannersButton;
    UFUNCTION()
    void disable728x90Banners();
    
    UPROPERTY(meta = (BindWidget))
    UButton *disableLocationButton;
    UFUNCTION()
    void disableLocation();
    
    UPROPERTY(meta = (BindWidget))
    UButton *disableStorageButton;
    UFUNCTION()
    void disableStorage();
    
    UPROPERTY(meta = (BindWidget))
    UButton *enableTestingButton;
    UFUNCTION()
    void enableTesting();
    
    UPROPERTY(meta = (BindWidget))
    UButton *enableLoggingButton;
    UFUNCTION()
    void enableLogging();
    
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *disableNetworkTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *disableNetworkButton;
    UFUNCTION()
    void disableNetwork();
    
    UPROPERTY(meta = (BindWidget))
    UButton *muteVideoButton;
    UFUNCTION()
    void muteVideo();
    
    UPROPERTY(meta = (BindWidget))
    UButton *enableChildButton;
    UFUNCTION()
    void enableChild();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterStringNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterStringValueTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *segmentFilterStringButton;
    UFUNCTION()
    void segmentFilterString();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterBooleanNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UCheckBox *filterBooleanValueCheckbox;
    UPROPERTY(meta = (BindWidget))
    UButton *segmentFilterBooleanButton;
    UFUNCTION()
    void segmentFilterBoolean();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterIntegerNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterIntegerValueTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *segmentFilterIntegerButton;
    UFUNCTION()
    void segmentFilterInteger();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterFloatNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *filterFloatValueTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *segmentFilterFloatButton;
    UFUNCTION()
    void segmentFilterFloat();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *purchaseAmountTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *purchaseCurrencyTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *trackPurchaseButton;
    UFUNCTION()
    void trackPurchase();
    
    UPROPERTY(meta = (BindWidget))
    UButton *showTestScreenButton;
    UFUNCTION()
    void showTestScreen();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataStringNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataStringValueTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *setExtraDataStringButton;
    UFUNCTION()
    void setExtraDataString();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataBoolNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UCheckBox *extraDataBooleanValueCheckbox;
    UPROPERTY(meta = (BindWidget))
    UButton *setExtraDataBooleanButton;
    UFUNCTION()
    void setExtraDataBoolean();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataIntNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataIntValueTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *setExtraDataIntButton;
    UFUNCTION()
    void setExtraDataInt();
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataFloatNameTextBox;
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *extraDataFloatValueTextBox;
    UPROPERTY(meta = (BindWidget))
    UButton *setExtraDataFloatButton;
    UFUNCTION()
    void setExtraDataFloat();
    
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuMain;
    UPROPERTY(meta = (BindWidget))
    UButton *backButton;
    UFUNCTION()
    void back();
    
private:
    void removeAllWidgets();
};
