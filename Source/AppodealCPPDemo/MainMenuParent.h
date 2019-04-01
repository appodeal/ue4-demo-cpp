// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "MainMenuParent.generated.h"

/**
 * 
 */
UCLASS()
class APPODEALCPPDEMO_API UMainMenuParent : public UUserWidget
{
	GENERATED_BODY()
    
public:
	bool Initialize() override;
    UPROPERTY(meta = (BindWidget))
    UButton *interstitialButton;
    UPROPERTY(meta = (BindWidget))
    UButton *bannerButton;
    UPROPERTY(meta = (BindWidget))
    UButton *rewardedButton;
    UPROPERTY(meta = (BindWidget))
    UButton *nonSkippableButton;
    UPROPERTY(meta = (BindWidget))
    UButton *settingsButton;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuInterstitial;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuBanner;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuRewarded;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuNonSkippable;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuSettings;
    
    UFUNCTION()
    void showInterstitialMenu();
    UFUNCTION()
    void showBannerMenu();
    UFUNCTION()
    void showRewardedMenu();
    UFUNCTION()
    void showNonSkippableMenu();
    UFUNCTION()
    void showSettingsMenu();
private:
    void removeAllWidgets();
};
