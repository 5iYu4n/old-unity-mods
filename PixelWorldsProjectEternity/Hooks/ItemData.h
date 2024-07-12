#ifndef CSY_ITEMDATA_H
#define CSY_ITEMDATA_H

static bool EnableToolGetItemData = false;

static int TouchMapPointState = 1;

Vector2i currentTouchMapPoint = {};
Vector2i currentTouchMapPoint2 = {};
Vector2i finalMapPoint = {};

void GetItemData_ByTouch()
{
    if(EnableToolGetItemData)
    {
        float ScreenTouchXPosXItem = 0;
        float ScreenTouchYPosYItem = 0;

        int WidthSizeItem = (float) Screen_get_width();
        int HeightSizeItem = (float) Screen_get_height();

        if (WidthSizeItem != 0 && HeightSizeItem != 0)
        {
            ImGuiIO &io = ImGui::GetIO();
            int count = IM_ARRAYSIZE(io.MouseDown);

            for (int i = 0; i < count; i++)
                if (ImGui::IsMousePosValid() && ImGui::IsMouseClicked(i))
                {
                    //Get Mouse Pos
                    ScreenTouchXPosXItem = io.MousePos.x;
                    ScreenTouchYPosYItem = io.MousePos.y;

                    //Y Map Point Adjustment
                    int currentY = MyMapPoint.y;
                    int adjustY = 1;
                    for (int i = 1; i < currentY; ++i)
                    {
                        adjustY += 2;
                    }
                    auto STW = ScreenToWorld(Vector2{ScreenTouchXPosXItem, ScreenTouchYPosYItem});
                    auto STW2 = ScreenToWorld(Vector2{MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y});
                    float extraY = STW2.Y - MyPositionOK.Y;
                    auto MP = ConvertWorldPointToMapPointVec2i(Vector2{STW.X, STW.Y - extraY});
                    MP.y =  ((MP.y * -1) + adjustY);
                    if(TouchMapPointState == 1)
                    {
                        currentTouchMapPoint = Vector2i{MP.x, MP.y};
                        TouchMapPointState = 2;
                    }
                    else if(TouchMapPointState == 2)
                    {
                        currentTouchMapPoint2 = Vector2i{MP.x, MP.y};
                        TouchMapPointState = 1;
                    }
                    if(currentTouchMapPoint == currentTouchMapPoint2)
                    {
                        finalMapPoint = currentTouchMapPoint;
                    }
                }
        }
    }
}

void DrawGetItemData()
{
    if(EnableToolGetItemData)
    {
        if(!checkIsPlayerInMenu)
        {
            float width = Screen_get_width();
            float height = Screen_get_height();
            ImGui::Begin(OBFUSCATE("Item Data"), &EnableToolGetItemData, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
            if(WorldInstantiate != nullptr)
            {
                int blockType = World_GetBlockType(WorldInstantiate, finalMapPoint.x, finalMapPoint.y);
                void *GetWorldItemData = World_GetWorldItemData(WorldInstantiate, finalMapPoint.x, finalMapPoint.y);
                if(GetWorldItemData != nullptr)
                {
                    if(blockType == 80) //SmallChest
                    {
                        ImGui::Text(OBFUSCATE("Item: Small Chest"));
                        if(SmallChestData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < SmallChestData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[SmallChestData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], SmallChestData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Small Chest"));
                        }
                    }
                    else if(blockType == 135) //Safe
                    {
                        ImGui::Text(OBFUSCATE("Item: Safe"));
                        if(SafeData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < SafeData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[SafeData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], SafeData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Safe"));
                        }
                    }
                    else if(blockType == 295) //VortexPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Vortex"));
                        ImGui::Text(OBFUSCATE("Name: %s"), VortexPortalData_GetName(GetWorldItemData)->getChars());
                        if(VortexPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), VortexPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), VortexPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), VortexPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 329) //Portal
                    {
                        ImGui::Text(OBFUSCATE("Item: Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalData_GetName(GetWorldItemData)->getChars());
                        if(PortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 410) //LockSmall
                    {
                        ImGui::Text(OBFUSCATE("Item: Small Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockSmallData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockSmallData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockSmallData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockSmallData_GetIgnoreEmptyArea(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Do Not Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockSmallData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockSmallData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockSmallData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, OBFUSCATE("%d-%m-%Y %H:%M:%S"), localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 411) //LockMedium
                    {
                        ImGui::Text(OBFUSCATE("Item: Medium Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockMediumData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockMediumData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockMediumData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockMediumData_GetIgnoreEmptyArea(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Do Not Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockMediumData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockMediumData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockMediumData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 412) //LockLarge
                    {
                        ImGui::Text(OBFUSCATE("Item: Large Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockLargeData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockLargeData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockLargeData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockLargeData_GetIgnoreEmptyArea(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Do Not Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockLargeData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockLargeData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockLargeData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 413) //LockWorld
                    {
                        ImGui::Text(OBFUSCATE("Item: World Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockWorldData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockWorldData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockWorldData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockWorldData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockWorldData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockWorldData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 416) //LockClan
                    {
                        ImGui::Text(OBFUSCATE("Item: Clan Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockClanData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockClanData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockClanData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockClanData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockClanData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockClanData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockClanData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 796) //LockPlatinum
                    {
                        ImGui::Text(OBFUSCATE("Item: Platinum Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockPlatinumData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockPlatinumData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockPlatinumData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockPlatinumData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockPlatinumData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockPlatinumData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockPlatinumData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 882) //LockWorldDark
                    {
                        ImGui::Text(OBFUSCATE("Item: Dark Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockWorldDarkData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockWorldDarkData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockWorldDarkData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldDarkData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockWorldDarkData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text("%s", PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockWorldDarkData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockWorldDarkData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 1131) //LockWorldBattle
                    {
                        ImGui::Text(OBFUSCATE("Item: Battle World Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockWorldBattleData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockWorldBattleData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockWorldBattleData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldBattleData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldBattleData_GetIsBattleOn(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle On"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle Off"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockWorldBattleData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockWorldBattleData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockWorldBattleData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 1132) //LockBattle
                    {
                        ImGui::Text(OBFUSCATE("Item: Battle Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockBattleData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockBattleData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockBattleData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockBattleData_GetIgnoreEmptyArea(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Do Not Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        if(LockBattleData_GetIsBattleOn(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle On"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle Off"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockBattleData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockBattleData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockBattleData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 1481) //AnniversaryPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Anniversary Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), AnniversaryPortalData_GetName(GetWorldItemData)->getChars());
                        if(AnniversaryPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), AnniversaryPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), AnniversaryPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), AnniversaryPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 1596) //PortalWOTW
                    {
                        ImGui::Text(OBFUSCATE("Item: WOTW Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalWOTWData_GetName(GetWorldItemData)->getChars());
                        if(PortalWOTWData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalWOTWData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalWOTWData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalWOTWData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 1799) //NetherGroupPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Nether Group Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), NetherGroupPortalData_GetName(GetWorldItemData)->getChars());
                        if(NetherGroupPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), NetherGroupPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), NetherGroupPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), NetherGroupPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 1994) //LabEnterPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Lab Entry Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), LabEnterPortalData_GetName(GetWorldItemData)->getChars());
                        if(LabEnterPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), LabEnterPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), LabEnterPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), LabEnterPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 1995) //LabExitPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Lab Exit Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), LabExitPortalData_GetName(GetWorldItemData)->getChars());
                        if(LabExitPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), LabExitPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), LabExitPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), LabExitPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 2001) //BluePortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Blue Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), BluePortalData_GetName(GetWorldItemData)->getChars());
                        if(BluePortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), BluePortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), BluePortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), BluePortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 2087) //QuantumSafe
                    {
                        ImGui::Text(OBFUSCATE("Item: Quantum Safe"));
                        if(QuantumSafeData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < QuantumSafeData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[QuantumSafeData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], QuantumSafeData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Quantum Safe"));
                        }
                    }
                    else if(blockType == 2212) //LockWorldNoob
                    {
                        ImGui::Text(OBFUSCATE("Item: Noob World Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockWorldNoobData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockWorldNoobData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockWorldNoobData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldNoobData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockWorldNoobData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockWorldNoobData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockWorldNoobData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 2389) //BloodyChest
                    {
                        ImGui::Text(OBFUSCATE("Item: Bloody Chest"));
                        if(BloodyChestData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < BloodyChestData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[BloodyChestData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], BloodyChestData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Bloody Chest"));
                        }
                    }
                    else if(blockType == 2403) //SmallChestBlackGold
                    {
                        ImGui::Text(OBFUSCATE("Item: Black Gold Chest"));
                        if(SmallChestBlackGoldData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < SmallChestBlackGoldData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[SmallChestBlackGoldData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], SmallChestBlackGoldData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Black Gold Chest"));
                        }
                    }
                    else if(blockType == 2904) //TutorialCablePortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Tutorial Cable Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), TutorialCablePortalData_GetName(GetWorldItemData)->getChars());
                        if(TutorialCablePortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), TutorialCablePortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), TutorialCablePortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), TutorialCablePortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 2992) //RiftPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Rift Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), RiftPortalData_GetName(GetWorldItemData)->getChars());
                        if(RiftPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), RiftPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), RiftPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), RiftPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 3031) //AlienChest
                    {
                        ImGui::Text(OBFUSCATE("Item: Alien Chest"));
                        if(AlienChestData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < AlienChestData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[AlienChestData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], AlienChestData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Alien Chest"));
                        }
                    }
                    else if(blockType == 3438) //PortalPassword
                    {
                        ImGui::Text(OBFUSCATE("Item: Password Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalPasswordData_GetName(GetWorldItemData)->getChars());
                        if(PortalPasswordData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalPasswordData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalPasswordData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalPasswordData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 3596) //LockBattleFaction
                    {
                        ImGui::Text(OBFUSCATE("Item: Faction Battle Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockBattleFactionData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockBattleFactionData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockBattleFactionData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockBattleFactionData_GetIgnoreEmptyArea(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Do Not Ignore Empty Area"));
                            ImGui::PopStyleColor();
                        }
                        if(LockBattleFactionData_GetIsBattleOn(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle On"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle Off"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockBattleFactionData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockBattleFactionData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockBattleFactionData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 3600) //PortalFactionDark
                    {
                        ImGui::Text(OBFUSCATE("Item: Dark Faction Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalFactionDarkData_GetName(GetWorldItemData)->getChars());
                        if(PortalFactionDarkData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalFactionDarkData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalFactionDarkData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalFactionDarkData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 3601) //PortalFactionLight
                    {
                        ImGui::Text(OBFUSCATE("Item: Light Faction Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalFactionLightData_GetName(GetWorldItemData)->getChars());
                        if(PortalFactionLightData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalFactionLightData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalFactionLightData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalFactionLightData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 3606) //LockWorldBattleFaction
                    {
                        ImGui::Text(OBFUSCATE("Item: Faction Battle World Lock"));
                        ImGui::Text(OBFUSCATE("Owner ID: %s"), LockWorldBattleFactionData_GetPlayerWhoOwnsLockId(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Owner Name: %s"), LockWorldBattleFactionData_GetPlayerWhoOwnsLockName(GetWorldItemData)->getChars());
                        if(LockWorldBattleFactionData_GetIsOpen(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Open, Anyone Can Build"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Closed, Need Right To Build"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldBattleFactionData_GetIsPunchingAllowed(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Allowed"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Hitting Not Allowed"));
                            ImGui::PopStyleColor();
                        }
                        if(LockWorldBattleFactionData_GetIsBattleOn(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle On"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Battle Off"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveAccessToLock = LockWorldBattleFactionData_GetPlayersWhoHaveAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveAccessToLock = PlayersWhoHaveAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveAccessToLock->getChars());
                        }
                        ImGui::Text(OBFUSCATE("Players Who Have Minor Access To Lock:"));
                        monoList<monoString **> *PlayersWhoHaveMinorAccessToLock = LockWorldBattleFactionData_GetPlayersWhoHaveMinorAccessToLock(GetWorldItemData);
                        for (int i = 0; i < PlayersWhoHaveMinorAccessToLock->getSize(); ++i) {
                            monoString *PlayerWhoHaveMinorAccessToLock = PlayersWhoHaveMinorAccessToLock->getItems()[i];
                            ImGui::Text(OBFUSCATE("%s"), PlayerWhoHaveMinorAccessToLock->getChars());
                        }
                        uint64_t dateData = (((uint64_t)LockWorldBattleFactionData_GetLastActivatedTime(GetWorldItemData).dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
                        time_t t = dateData;
                        std::string data = "";
                        data.resize(64);
                        strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
                        ImGui::Text(OBFUSCATE("Last Time Online: %s"), data.c_str());
                    }
                    else if(blockType == 3964) //PortalCryptic
                    {
                        ImGui::Text(OBFUSCATE("Item: Cryptic Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalCrypticData_GetName(GetWorldItemData)->getChars());
                        if(PortalCrypticData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalCrypticData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalCrypticData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalCrypticData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 3965) //PortalPixelMines
                    {
                        ImGui::Text(OBFUSCATE("Item: Pixel Mines Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalPixelMinesData_GetName(GetWorldItemData)->getChars());
                        if(PortalPixelMinesData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalPixelMinesData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalPixelMinesData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalPixelMinesData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 3966) //PortalMineExit
                    {
                        ImGui::Text(OBFUSCATE("Item: Mine Exit Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalMineExitData_GetName(GetWorldItemData)->getChars());
                        if(PortalMineExitData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalMineExitData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalMineExitData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalMineExitData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 4103) //PortalMiningEntry
                    {
                        ImGui::Text(OBFUSCATE("Item: Mining Entry Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), PortalMiningEntryData_GetName(GetWorldItemData)->getChars());
                        if(PortalMiningEntryData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), PortalMiningEntryData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), PortalMiningEntryData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), PortalMiningEntryData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 4373) //JetRaceGroupPortal
                    {
                        ImGui::Text(OBFUSCATE("Item: Jet Race Group Portal"));
                        ImGui::Text(OBFUSCATE("Name: %s"), JetRaceGroupPortalData_GetName(GetWorldItemData)->getChars());
                        if(JetRaceGroupPortalData_GetIsLocked(GetWorldItemData))
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Close"));
                            ImGui::PopStyleColor();
                        }
                        else
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
                            ImGui::Text(OBFUSCATE("Portal Is Open"));
                            ImGui::PopStyleColor();
                        }
                        ImGui::Text(OBFUSCATE("Entry Point ID: %s"), JetRaceGroupPortalData_GetEntryPointID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target World ID: %s"), JetRaceGroupPortalData_GetTargetWorldID(GetWorldItemData)->getChars());
                        ImGui::Text(OBFUSCATE("Target Entry Point ID: %s"), JetRaceGroupPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars());
                    }
                    else if(blockType == 4761) //TinyChest
                    {
                        ImGui::Text(OBFUSCATE("Item: Tiny Chest"));
                        if(TinyChestData_GetIsSomethingIn(GetWorldItemData))
                        {
                            for (int i = 0; i < TinyChestData_GetNumberOfItems(GetWorldItemData); ++i) {
                                ImGui::Text(OBFUSCATE("Item Number: %d | %s x%d"), i, blockTypeToString[TinyChestData_GetInventoryKeyOfSlot(GetWorldItemData, i).blockType], TinyChestData_GetInventoryAmountOfSlot(GetWorldItemData, i));
                            }
                        }
                        else
                        {
                            ImGui::Text(OBFUSCATE("Empty Tiny Chest"));
                        }
                    }
                    else
                    {
                        ImGui::Text(OBFUSCATE("Item Data Not Registered"));
                    }
                }
                else
                {
                    ImGui::Text(OBFUSCATE("No Item Date Selected"));
                }
            }
            else
            {
                ImGui::Text(OBFUSCATE("No Item Data Selected"));
            }
            ImGui::End();
        }
    }
}

#endif //CSY_ITEMDATA_H
