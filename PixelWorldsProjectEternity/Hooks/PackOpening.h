#ifndef CSY_PACKOPENING_H
#define CSY_PACKOPENING_H

const char* GemPackID = "";
static int buyPackTimes = 1;
static int currentCategory = 0;

void Auto_PackOpening()
{
    for (int i = 0; i < buyPackTimes; ++i) {
        OutgoingMessages_BuyItemPack(CreateIl2cppString(GemPackID));
    }
    SceneLoader_ReloadGame();
}

const char *CategoryId[] = {"Kits", "Themes", "FashionPack", "Seeds", "Locks", "Fishing", "Familiars", "Pets", "Orbs", "Cards", "Wiring", "Items", "Blueprints", "Community", "Clan"};
const char *CategoryIdName[] = {"Kits", "Boosters", "Wearables", "Seeds", "Locks", "Fishing", "Familiars", "Pets", "Orbs", "Battle Cards", "Wiring", "Special Items", "Blueprints", "Community Items", "Clan Items"};

void GetPackName()
{
    LOGI("Csy Debug: %s  -> %d", CategoryId[currentCategory], currentCategory);
    monoList<ItemPack *> *GetItemPacksList = ItemPacks_GetItemPacksList(CreateIl2cppString(CategoryId[currentCategory]));
    for (int j = 0; j < GetItemPacksList->getSize(); ++j) {
        LOGI("Csy Debug: %s -> %s", CategoryIdName[currentCategory], GetItemPacksList->getItems()[j].id->getChars());
    }
}


#endif //CSY_PACKOPENING_H
