// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppodealComponent.h"
#include "Blueprint/UserWidget.h"
#include "AppodealActor.generated.h"

UCLASS()
class APPODEALCPPDEMO_API AAppodealActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAppodealActor(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UAppodealComponent *appodealComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    UFUNCTION()
    void onBannerLoaded(int height, bool isPrecache);
    UFUNCTION()
    void onBannerFailedToLoad();
    UFUNCTION()
    void onBannerShown();
    UFUNCTION()
    void onBannerClicked();
    UFUNCTION()
    void onBannerExpired();
    
    UFUNCTION()
    void onInterstitialLoaded(bool isPrecache);
    UFUNCTION()
    void onInterstitialFailedToLoad();
    UFUNCTION()
    void onInterstitialShown();
    UFUNCTION()
    void onInterstitialClicked();
    UFUNCTION()
    void onInterstitialClosed();
    UFUNCTION()
    void onInterstitialExpired();
    
    UFUNCTION()
    void onNonSkippableVideoLoaded(bool isPrecache);
    UFUNCTION()
    void onNonSkippableVideoFailedToLoad();
    UFUNCTION()
    void onNonSkippableVideoShown();
    UFUNCTION()
    void onNonSkippableVideoFinished();
    UFUNCTION()
    void onNonSkippableVideoClosed(bool isFinished);
    UFUNCTION()
    void onNonSkippableVideoExpired();
    
    UFUNCTION()
    void onRewardedVideoLoaded(bool isPrecache);
    UFUNCTION()
    void onRewardedVideoFailedToLoad();
    UFUNCTION()
    void onRewardedVideoShown();
    UFUNCTION()
    void onRewardedVideoFinished(int amount, FString name);
    UFUNCTION()
    void onRewardedVideoClosed(bool isFinished);
    UFUNCTION()
    void onRewardedVideoExpired();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menus")
    TSubclassOf<UUserWidget> menuMain;
private:
    void showDebugMessage(FString message);
};
