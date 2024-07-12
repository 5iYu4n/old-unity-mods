#ifndef CSY_PIXELPERFECTCAMERA_H
#define CSY_PIXELPERFECTCAMERA_H

void (*old_PixelPerfectCamera_LateUpdate)(void *instance);
void PixelPerfectCamera_LateUpdate(void *instance){
    if(instance != nullptr){
        if(EnableZoomHack && ZoomSlider != nullptr)
        {
            *(int *)((uint64_t)instance + PixelWorlds.PixelPerfectCamera_cameraZoom) = (*(int *)((uint64_t)ZoomSlider + 0x1C)) + 1;
        }
        else
        {
            *(int *)((uint64_t)instance + PixelWorlds.PixelPerfectCamera_cameraZoom);
        }
        PixelPerfectCamera_cameraZoom = *(int *)((uint64_t)instance + PixelWorlds.PixelPerfectCamera_cameraZoom);
        PixelPerfectCamera_cameraOrigin = *(Vector2 *)((uint64_t)instance + PixelWorlds.PixelPerfectCamera_cameraOrigin);
    }
    old_PixelPerfectCamera_LateUpdate(instance);
}

#endif
