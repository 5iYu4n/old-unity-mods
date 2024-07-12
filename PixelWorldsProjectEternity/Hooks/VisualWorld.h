#ifndef CSY_VISUALWORLD_H
#define CSY_VISUALWORLD_H

static bool DoVisualBlockOnce = false;

void VisualItem_ByTouch()
{
    if(EnableDrawVisualBlock)
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
                    if(VisualItemTouchMapPointState == 1)
                    {
                        VisualItemTouchMapPoint = Vector2i{MP.x, MP.y};
                        VisualItemTouchMapPointState = 2;
                    }
                    else if(VisualItemTouchMapPointState == 2)
                    {
                        VisualItemTouchMapPoint2 = Vector2i{MP.x, MP.y};
                        VisualItemTouchMapPointState = 1;
                    }
                    if(VisualItemTouchMapPoint == VisualItemTouchMapPoint2)
                    {
                        DoVisualBlockOnce = true;
                        VisualItemMapPoint = VisualItemTouchMapPoint;
                    }
                }
        }
    }
}

int BlockLayerType(int blockType)
{
    if(blockType == 0)
    {
        return 0;
    }
    else if(ConfigData_GetBlockSortingLayerType(blockType) == 35)
    {
        return 1;
    }
    else if(ConfigData_GetBlockSortingLayerType(blockType) == 2)
    {
        return 2;
    }
    else if(ConfigData_GetBlockSortingLayerType(blockType) == 6 || ConfigData_GetBlockSortingLayerType(blockType) == 15)
    {
        return 3;
    }
}

void SetVisualBlock(void *WorldController)
{
    if(DoVisualBlockOnce && EnableDrawVisualBlock && VisualItemMapPoint != Vector2i{-1, -1})
    {
        DoVisualBlockOnce = false;
        if(BlockToRemoveState != 0)
        {
            if(BlockToRemoveState == 1)
            {
                WorldController_DestroyBlockSpriteOrQuad(WorldController, VisualItemMapPoint.x, VisualItemMapPoint.y);
            }
            else if(BlockToRemoveState == 2)
            {
                WorldController_DestroyBlockBackgroundSpriteOrQuad(WorldController, VisualItemMapPoint.x, VisualItemMapPoint.y);
            }
            else if(BlockToRemoveState == 3)
            {
                WorldController_DestroyBlockWaterSpriteOrQuad(WorldController, VisualItemMapPoint.x, VisualItemMapPoint.y);
            }
            VisualItemMapPoint = Vector2i{-1, -1};
            VisualItemTouchMapPoint = Vector2i{-1, -1};
        }
        if(BlockLayerType(setVisualBlockType) == 1 && BlockToRemoveState == 0)
        {
            WorldController_SetBlockWater(WorldController, setVisualBlockType, VisualItemMapPoint.x, VisualItemMapPoint.y);
            VisualItemMapPoint = Vector2i{-1, -1};
            VisualItemTouchMapPoint = Vector2i{-1, -1};
        }
        else if(BlockLayerType(setVisualBlockType) == 2 && BlockToRemoveState == 0)
        {
            WorldController_SetBlockBackground(WorldController, setVisualBlockType, VisualItemMapPoint.x, VisualItemMapPoint.y);
            VisualItemMapPoint = Vector2i{-1, -1};
            VisualItemTouchMapPoint = Vector2i{-1, -1};
        }
        else if(BlockLayerType(setVisualBlockType) == 3 && BlockToRemoveState == 0)
        {
            WorldController_SetBlock(WorldController, setVisualBlockType, VisualItemMapPoint.x, VisualItemMapPoint.y);
            VisualItemMapPoint = Vector2i{-1, -1};
            VisualItemTouchMapPoint = Vector2i{-1, -1};
        }
    }
}

#endif //CSY_VISUALWORLD_H
