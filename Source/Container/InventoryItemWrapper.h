#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemInfo.h"
#include "InventoryItemWrapper.generated.h"

UCLASS(BlueprintType, Blueprintable)
class CONTAINER_API UInventoryItemWrapper : public UObject
{
	GENERATED_BODY()
	
public:
	// UI 타일에 전달할 핵심 아이템 정보
	UPROPERTY(BlueprintReadWrite, Category = "UI Data")
	FMyItemInfo ItemData;
};
