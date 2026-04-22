#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" 
#include "ItemInfo.generated.h"

USTRUCT(BlueprintType)
struct FMyItemInfo : public FTableRowBase
{
    GENERATED_BODY()

    // UI에 보여질 아이템의 이름
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    FText ItemName;

    // 이 아이템을 쓰기 위해 필요한 칭호
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    FName RequiredTitle;
};