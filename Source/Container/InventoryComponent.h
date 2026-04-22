#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemInfo.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CONTAINER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool TryUseItem(FName TargetItemID);

protected:
    // 가방 (TArray): 실제 아이템 ID들이 순서대로 담깁니다.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
    TArray<FName> Bag;

    // 아이템 정보 확인 (TMap): 아이템 ID를 열쇠(Key)로 세부 정보를 띄웁니다.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
    TMap<FName, FMyItemInfo> ItemDatabase;

    // 칭호 획득 (TSet): 특정 칭호를 보유하고 있는지 즉시 검사합니다.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
    TSet<FName> AcquiredTitles;
};
