#ifndef CSY_VISUALWEARABLE_H
#define CSY_VISUALWEARABLE_H

static int currentWearable = 0;
static bool ApplyWearable = false;

void CustomWearable(void *player)
{
    if(ApplyWearable)
    {
        ApplyWearable = false;
        if(ConfigData_IsBlockFamiliar(currentWearable))
        {
            Player_ChangeFamiliarRemote(player, currentWearable, CreateIl2cppString(""), false);
        }
        else
        {
            monoArray<int *> *GetWearableHotSpots = WearableHotSpotsValidity_GetWearableHotSpots(currentWearable);
            for (int i = 0; i < GetWearableHotSpots->getLength(); ++i) {
                int GetWearableHotSpot = GetWearableHotSpots->getPointer()[i];
                Player_ChangeWearableRemote(player, GetWearableHotSpot, currentWearable);
            }
        }

    }
}

#endif //CSY_VISUALWEARABLE_H
