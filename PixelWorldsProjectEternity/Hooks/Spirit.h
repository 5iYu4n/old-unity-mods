#ifndef CSY_SPIRIT_H
#define CSY_SPIRIT_H

static bool EnableSpiritAimbot = false;
static float SpiritAimbotTimer = 0.0f;
static float SpiritAimbotDelay = 0.150f;

void SpiritAimbot()
{
    if(EnableSpiritAimbot)
    {
        SpiritAimbotTimer += deltaTime;
        if(SpiritVec2i != Vector2i{})
        {
            if(SpiritAimbotTimer >= SpiritAimbotDelay)
            {
                Vector2 distance = Vector2{MyMapPoint.x - SpiritVec2i.x, MyMapPoint.y - SpiritVec2i.y};
                float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
                if (Pytha < 4.24f)
                {
                    OutgoingMessages_SendHitSpiritMessage(SpiritVec2i);
                    SpiritAimbotTimer = 0.0f;
                }
            }
        }
    }
}

void SpiritScript(void *spirit)
{
    if(spirit != nullptr)
    {
        void *myTransform = *(void **)((uint64_t)spirit + PixelWorlds.Spirit_myTransform);
        if(myTransform != nullptr)
        {
            Vector3 spiritPos = Transform_get_position(myTransform);
            SpiritVec2 = WorldToScreenVec2(Vector2{spiritPos.X , spiritPos.Y});
            Vector2 spiritDD = ConvertWorldPointToMapPoint(Vector2{spiritPos.X, spiritPos.Y});
            SpiritVec2i = Vector2i{roundf(spiritDD.X),roundf(spiritDD.Y)};
        }
        SpiritAimbot();
    }
    else
    {
        SpiritVec2i = Vector2i{};
    }
}

#endif //CSY_SPIRIT_H
