#ifndef CSY_TELEPORTATION_H
#define CSY_TELEPORTATION_H

void GetTP_ByTouch()
{
    if(EnableTeleportation)
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
                    if(TPTouchMapPointState == 1)
                    {
                        currentTPTouchMapPoint = Vector2i{MP.x, MP.y};
                        TPTouchMapPointState = 2;
                    }
                    else if(TPTouchMapPointState == 2)
                    {
                        currentTPTouchMapPoint2 = Vector2i{MP.x, MP.y};
                        TPTouchMapPointState = 1;
                    }
                    if(currentTPTouchMapPoint == currentTPTouchMapPoint2)
                    {
                        finalTPMapPoint = currentTPTouchMapPoint;
                    }
                }
        }
    }
}

void TPByTouch(void *player)
{
    if(EnableTeleportation)
    {
        if(!checkIsPlayerInMenu && finalTPMapPoint != Vector2i{-1, -1} && player != nullptr)
        {
            Vector2 WorldPointVec2 = ConvertMapPointToWorldPoint(finalTPMapPoint.x, finalTPMapPoint.y);
            Vector3 WorldPoint = {WorldPointVec2.X, WorldPointVec2.Y, 0};
            WorldPoint -= boxSizeY / 2.4f;

            Vector2 distance = Vector2{MyMapPoint.x - WorldPoint.X, MyMapPoint.y - WorldPoint.Y};
            float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
            if(Pytha >= 4.24f)
            {
                void *myTransform = *(void **)((uint64_t)player + PixelWorlds.Player_myTransform);
                if(myTransform != nullptr)
                {
                    Transform_set_position(myTransform, WorldPoint);
                    finalTPMapPoint = Vector2i{-1, -1};
                }
                else
                {
                    finalTPMapPoint = Vector2i{-1, -1};
                }
            }
            else
            {
                finalTPMapPoint = Vector2i{-1, -1};
            }
        }
    }
}

#endif
