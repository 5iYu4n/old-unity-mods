#ifndef CSY_PORTALTP_H
#define CSY_PORTALTP_H

static bool EnablePortalTP = false;

static bool DoJoinPortalOnce = false;

static int PortalTPTouchMapPointState = 1;

Vector2i currentPortalTPTouchMapPoint = {};
Vector2i currentPortalTPTouchMapPoint2 = {};
Vector2i finalPortalTPMapPoint = Vector2i{-1, -1};

void GetPortalTP_ByTouch()
{
    if(EnablePortalTP)
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
                    if(PortalTPTouchMapPointState == 1)
                    {
                        currentPortalTPTouchMapPoint = Vector2i{MP.x, MP.y};
                        PortalTPTouchMapPointState = 2;
                    }
                    else if(PortalTPTouchMapPointState == 2)
                    {
                        currentPortalTPTouchMapPoint2 = Vector2i{MP.x, MP.y};
                        PortalTPTouchMapPointState = 1;
                    }
                    if(currentPortalTPTouchMapPoint == currentPortalTPTouchMapPoint2)
                    {
                        finalPortalTPMapPoint = currentPortalTPTouchMapPoint;
                    }
                }
        }
    }
}

void TpPortalMod()
{
    if(EnablePortalTP)
    {
        if(WorldInstantiate != nullptr && DoJoinPortalOnce && !checkIsPlayerInMenu){
            int blockType = World_GetBlockType(WorldInstantiate, finalPortalTPMapPoint.x, finalPortalTPMapPoint.y);
            void *GetWorldItemData = World_GetWorldItemData(WorldInstantiate, finalPortalTPMapPoint.x, finalPortalTPMapPoint.y);
            if (GetWorldItemData != nullptr)
            {
                if(blockType == 295) //VortexPortal
                {
                    if(VortexPortalData_GetIsLocked(GetWorldItemData))
                    {
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                    }
                    else
                    {
                        const char *WorldName = VortexPortalData_GetTargetWorldID(GetWorldItemData)->getChars();
                        const char *WorldEntryPoint = VortexPortalData_GetTargetEntryPointID(GetWorldItemData)->getChars();
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                        DoJoinPortalOnce = false;
                    }
                }
                else if(blockType == 329) //Portal
                {
                    if(PortalData_GetIsLocked(GetWorldItemData))
                    {
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                    }
                    else
                    {
                        const char *WorldName = PortalData_GetTargetWorldID(GetWorldItemData)->getChars();
                        const char *WorldEntryPoint = PortalData_GetTargetEntryPointID(GetWorldItemData)->getChars();
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                        DoJoinPortalOnce = false;
                    }
                }
                else if(blockType == 1481) //AnniversaryPortal
                {
                    if(AnniversaryPortalData_GetIsLocked(GetWorldItemData))
                    {
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                    }
                    else
                    {

                    }
                }
                else if(blockType == 3438) //PortalPassword
                {
                    if(PortalPasswordData_GetIsLocked(GetWorldItemData))
                    {
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                    }
                    else
                    {

                    }
                }
                else if(blockType == 3600) //PortalFactionDark
                {
                    if(PortalFactionDarkData_GetIsLocked(GetWorldItemData))
                    {
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                    }
                    else
                    {

                    }
                }
                else if(blockType == 3601) //PortalFactionLight
                {
                    if(PortalFactionLightData_GetIsLocked(GetWorldItemData))
                    {
                        finalPortalTPMapPoint = Vector2i{-1, -1};
                    }
                    else
                    {

                    }
                }
                else
                {
                    finalPortalTPMapPoint = Vector2i{-1, -1};
                }
            }
        }
    }
}

#endif
