// Fill out your copyright notice in the Description page of Project Settings.

#include "AppodealActor.h"
#include "AppodealComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AAppodealActor::AAppodealActor(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
    appodealComponent = ObjectInitializer.CreateDefaultSubobject<UAppodealComponent>(this, TEXT("Appodeal"));
}

void AAppodealActor::onBannerLoaded(int height, bool isPrecache){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Banner Loaded. Height: %d, isPrecache: %d" ), height, isPrecache));
}
void AAppodealActor::onBannerFailedToLoad(){
    showDebugMessage(FString(TEXT("Appodeal. On Banner failed to load")));
}
void AAppodealActor::onBannerShown(){
    showDebugMessage(FString(TEXT("Appodeal. On Banner Shown")));
}
void AAppodealActor::onBannerClicked(){
    showDebugMessage(FString(TEXT("Appodeal. On Banner clicked")));
}
void AAppodealActor::onBannerExpired(){
    showDebugMessage(FString(TEXT("Appodeal. On Banner Expired")));
}

void AAppodealActor::onInterstitialLoaded(bool isPrecache){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Interstitial Loaded. isPrecache: %d" ), isPrecache));
}
void AAppodealActor::onInterstitialFailedToLoad(){
    showDebugMessage(FString(TEXT("Appodeal. On Interstitial Failed To Load")));
}
void AAppodealActor::onInterstitialShown(){
    showDebugMessage(FString(TEXT("Appodeal. On Interstitial Shown")));
}
void AAppodealActor::onInterstitialClicked(){
    showDebugMessage(FString(TEXT("Appodeal. On Interstitial Clicked")));
}
void AAppodealActor::onInterstitialClosed(){
    showDebugMessage(FString(TEXT("Appodeal. On Interstitial Closed")));
}
void AAppodealActor::onInterstitialExpired(){
    showDebugMessage(FString(TEXT("Appodeal. On Interstitial Expired")));
}

void AAppodealActor::onNonSkippableVideoLoaded(bool isPrecache){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Non Skippable Video Loaded. isPrecache: %d" ), isPrecache));
}
void AAppodealActor::onNonSkippableVideoFailedToLoad(){
    showDebugMessage(FString(TEXT("Appodeal. On Non Skippable Video Failed To Load")));
}
void AAppodealActor::onNonSkippableVideoShown(){
    showDebugMessage(FString(TEXT("Appodeal. On Non Skippable Video Shown")));
}
void AAppodealActor::onNonSkippableVideoFinished(){
    showDebugMessage(FString(TEXT("Appodeal. On Non Skippable Video Finished")));
}
void AAppodealActor::onNonSkippableVideoClosed(bool isFinished){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Non Skippable Video Closed. Finished: %d" ), isFinished));
}
void AAppodealActor::onNonSkippableVideoExpired(){
    showDebugMessage(FString(TEXT("Appodeal. On Non Skippable Video Expired")));
}

void AAppodealActor::onRewardedVideoLoaded(bool isPrecache){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Rewarded Video Loaded. isPrecache: %d" ), isPrecache));
}
void AAppodealActor::onRewardedVideoFailedToLoad(){
    showDebugMessage(FString(TEXT("Appodeal. On Rewarded Video Failed To Load")));
}
void AAppodealActor::onRewardedVideoShown(){
    showDebugMessage(FString(TEXT("Appodeal. On Rewarded Video Shown")));
}
void AAppodealActor::onRewardedVideoFinished(int amount, FString name){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Rewarded Video Finished. Reward: %d %s" ), amount, *name));
}
void AAppodealActor::onRewardedVideoClosed(bool isFinished){
    showDebugMessage(FString::Printf(TEXT("Appodeal. On Rewarded Video Closed. Finished: %d"), isFinished));
}
void AAppodealActor::onRewardedVideoExpired(){
    showDebugMessage(FString(TEXT("Appodeal. On Rewarded Video Expired")));
}

// Called when the game starts or when spawned
void AAppodealActor::BeginPlay()
{
	Super::BeginPlay();
    if(menuMain){
        //UUserWidget *menu = CreateWidgetInstance(*GetWorld(), menuMain, "MainMenu");
        //UUserWidget *menu = CreateWidget<UUserWidget>(*GetWorld(), menuMain, TEXT("Main Menu"));
        UUserWidget *menu = CreateWidget<UUserWidget>(GetGameInstance(), menuMain);
        menu->AddToViewport();
    }
    if(appodealComponent){
        appodealComponent->OnBannerLoaded.AddDynamic(this, &AAppodealActor::onBannerLoaded);
        appodealComponent->OnBannerFailedToLoad.AddDynamic(this, &AAppodealActor::onBannerFailedToLoad);
        appodealComponent->OnBannerShown.AddDynamic(this, &AAppodealActor::onBannerShown);
        appodealComponent->OnBannerClicked.AddDynamic(this, &AAppodealActor::onBannerClicked);
        appodealComponent->OnBannerExpired.AddDynamic(this, &AAppodealActor::onBannerExpired);
        
        appodealComponent->OnInterstitialLoaded.AddDynamic(this, &AAppodealActor::onInterstitialLoaded);
        appodealComponent->OnInterstitialFailedToLoad.AddDynamic(this, &AAppodealActor::onInterstitialFailedToLoad);
        appodealComponent->OnInterstitialShown.AddDynamic(this, &AAppodealActor::onInterstitialShown);
        appodealComponent->OnInterstitialClicked.AddDynamic(this, &AAppodealActor::onInterstitialClicked);
        appodealComponent->OnInterstitialClosed.AddDynamic(this, &AAppodealActor::onInterstitialClosed);
        appodealComponent->OnInterstitialExpired.AddDynamic(this, &AAppodealActor::onInterstitialExpired);
        
        appodealComponent->OnNonSkippableVideoLoaded.AddDynamic(this, &AAppodealActor::onNonSkippableVideoLoaded);
        appodealComponent->OnNonSkippableVideoFailedToLoad.AddDynamic(this, &AAppodealActor::onNonSkippableVideoFailedToLoad);
        appodealComponent->OnNonSkippableVideoShown.AddDynamic(this, &AAppodealActor::onNonSkippableVideoShown);
        appodealComponent->OnNonSkippableVideoFinished.AddDynamic(this, &AAppodealActor::onNonSkippableVideoFinished);
        appodealComponent->OnNonSkippableVideoClosed.AddDynamic(this, &AAppodealActor::onNonSkippableVideoClosed);
        appodealComponent->OnNonSkippableVideoExpired.AddDynamic(this, &AAppodealActor::onNonSkippableVideoExpired);
        
        appodealComponent->OnRewardedVideoLoaded.AddDynamic(this, &AAppodealActor::onRewardedVideoLoaded);
        appodealComponent->OnRewardedVideoFailedToLoad.AddDynamic(this, &AAppodealActor::onRewardedVideoFailedToLoad);
        appodealComponent->OnRewardedVideoShown.AddDynamic(this, &AAppodealActor::onRewardedVideoShown);
        appodealComponent->OnRewardedVideoFinished.AddDynamic(this, &AAppodealActor::onRewardedVideoFinished);
        appodealComponent->OnRewardedVideoClosed.AddDynamic(this, &AAppodealActor::onRewardedVideoClosed);
        appodealComponent->OnRewardedVideoExpired.AddDynamic(this, &AAppodealActor::onRewardedVideoExpired);
    }
}

// Called every frame
void AAppodealActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAppodealActor::showDebugMessage(FString m)
{
    if(GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, m);
}
