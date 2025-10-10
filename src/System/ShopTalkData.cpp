#include "System/ShopTalkData.h"

#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>

ShopTalkData::ShopTalkData(s32 size, const s32*, s32 itemListSize, const sead::PtrArray<ShopItem::ShopItemInfo>&) : mSize(size) {}

/*
void ShopTalkData::init();
bool ShopTalkData::isEnableExplainShopCoin(s32) const;
bool ShopTalkData::checkShowNewItemAndPrepareSave(const GameDataHolderAccessor&, bool, s32);
bool ShopTalkData::checkExistNewItem(const GameDataHolderAccessor&, s32, s32, bool) const;
void ShopTalkData::write(al::ByamlWriter*) override;
void ShopTalkData::read(const al::ByamlIter&) override;
*/
