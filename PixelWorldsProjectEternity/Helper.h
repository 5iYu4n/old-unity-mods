#ifndef CSY_HELPER_H
#define CSY_HELPER_H

Vector2i WorldToScreen(Vector2 pos)
{
    float worldScaling = worldScaleValue * PixelPerfectCamera_cameraZoom;
    return Vector2i
            {
                    ((int)(pos.X * worldScaling) - (int)(PixelPerfectCamera_cameraOrigin.X * worldScaling)),
                    ((int)(PixelPerfectCamera_cameraOrigin.Y * worldScaling) - (int)(pos.Y * worldScaling))
            };
}

Vector2 WorldToScreenVec2(Vector2 pos)
{
    float worldScaling = worldScaleValue * PixelPerfectCamera_cameraZoom;
    return Vector2
            {
                    ((float)(pos.X * worldScaling) - (float)(PixelPerfectCamera_cameraOrigin.X * worldScaling)),
                    ((float)(PixelPerfectCamera_cameraOrigin.Y * worldScaling) - (float)(pos.Y * worldScaling))
            };
}

Vector2 ScreenToWorld(Vector2 screenPoint)
{
    float worldScaling = worldScaleValue * PixelPerfectCamera_cameraZoom;
    return Vector2
            {
                    PixelPerfectCamera_cameraOrigin.X + (screenPoint.X / worldScaling),
                    PixelPerfectCamera_cameraOrigin.Y + (screenPoint.Y / worldScaling)
            };
}

Vector2 ConvertMapPointToWorldPoint(float x, float y)
{
    return Vector2{ x * tileSizeXVal, y * tileSizeYVal };
}

Vector2i ConvertMapPointToWorldPoint2i(Vector2i pos)
{
    return Vector2i{ (int)((float)pos.x * tileSizeXVal), (int)((float)pos.y * tileSizeYVal) };
}

Vector2 ConvertWorldPointToMapPoint(Vector2 worldPoint)
{
    return Vector2{ (float)(worldPoint.X / (float)tileSizeXVal), (float)((worldPoint.Y + (float)tileSizeYVal / 2) / (float)tileSizeYVal) };
}

Vector2 ScaleToScreen(Vector2 point)
{
    float worldScaling = 100.f * PixelPerfectCamera_cameraZoom;

    return Vector2{ float(point.X * worldScaling), float(point.Y * worldScaling) };
}

Vector2i ConvertWorldPointToMapPointVec2i(Vector2 worldPoint)
{
    return Vector2i{ (int)roundf(worldPoint.X / tileSizeXVal), int((worldPoint.Y + (tileSizeYVal / 2.f)) / tileSizeYVal) };
}

const char* getTime(DateTime Date)
{
    uint64_t dateData = (((uint64_t)Date.dateData & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000;
    time_t t = dateData;
    std::string data = "";
    data.resize(64);
    strftime(data.data(), 64, "%d-%m-%Y %H:%M:%S", localtime(&t));
    return data.c_str();
}


#endif //CSY_HELPER_H
