#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

bool UInventoryComponent::TryUseItem(FName TargetItemID)
{
    // 가방에 아이템이 진짜로 들어있는지 확인
    if (!Bag.Contains(TargetItemID)) return false;

    // 아이템 식별자(FName)를 Key값으로 아이템 상세 정보 불러오기
    const FMyItemInfo* FoundItemInfo = ItemDatabase.Find(TargetItemID);
    if (FoundItemInfo == nullptr) return false;

    // 아이템에 요구 칭호가 있다면, 플레이어가 그 칭호를 획득(포함)했는지 검사
    if (!FoundItemInfo->RequiredTitle.IsNone())
    {
        if (!AcquiredTitles.Contains(FoundItemInfo->RequiredTitle))
        {
            UE_LOG(LogTemp, Warning, TEXT("칭호가 부족하여 해당 아이템을 사용할 수 없습니다!"));
            return false;
        }
    }

    // 모든 조건을 통과했다면 사용 성공 및 가방에서 아이템 제거
    UE_LOG(LogTemp, Log, TEXT("%s 아이템을 성공적으로 사용했습니다!"), *FoundItemInfo->ItemName.ToString());
    Bag.RemoveSingle(TargetItemID);

    return true;
}
