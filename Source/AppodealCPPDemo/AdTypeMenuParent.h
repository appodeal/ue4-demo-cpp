// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/CheckBox.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"
#include "AppodealComponent.h"
#include "AdTypeMenuParent.generated.h"

/**
 * 
 */
UCLASS()
class APPODEALCPPDEMO_API UIAdTypeMenuParent : public UUserWidget
{
	GENERATED_BODY()
public:
    
    bool Initialize() override;
    
    UPROPERTY(meta = (BindWidget))
    UCheckBox *disableAutoCacheCheckbox;
    UPROPERTY(meta = (BindWidget))
    UCheckBox *enableTriggerOnLoadedOnPrecacheCheckbox;
    
    UPROPERTY(meta = (BindWidget))
    UButton *initializeButton;
    UPROPERTY(meta = (BindWidget))
    UButton *cacheButton;
    UPROPERTY(meta = (BindWidget))
    UButton *showButton;
    
    UPROPERTY(meta = (BindWidget))
    UButton *getPredictedECPMButton;
    UPROPERTY(meta = (BindWidget))
    UButton *isInitialisedButton;
    UPROPERTY(meta = (BindWidget))
    UButton *isAutoCacheEnabledButton;
    UPROPERTY(meta = (BindWidget))
    UButton *canShowButton;
    UPROPERTY(meta = (BindWidget))
    UButton *isLoadedButton;
    
    UPROPERTY(meta = (BindWidget))
    UButton *backButton;
    
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox *statusTextBox;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuMain;

    virtual AdType getAdType();
    
    void showText(FString text);
    
    UFUNCTION()
    void initialize();
    UFUNCTION()
    void cache();
    UFUNCTION()
    void show();
    UFUNCTION()
    void getPredictedECPM();
    UFUNCTION()
    void isInitialized();
    UFUNCTION()
    void isAutoCacheEnabled();
    UFUNCTION()
    void canShow();
    UFUNCTION()
    void isLoaded();
    UFUNCTION()
    void back();
    
private:
    void removeAllWidgets();
	
};
