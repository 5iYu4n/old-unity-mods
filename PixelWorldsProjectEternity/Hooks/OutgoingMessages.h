#ifndef CSY_OUTGOINGMESSAGES_H
#define CSY_OUTGOINGMESSAGES_H

void (*old_OutgoingMessages_SendCollectCollectableMessage)(int id);
void OutgoingMessages_SendCollectCollectableMessage(int id)
{
    if(EnableAntiPickup)
    {
        return;
    }
    return old_OutgoingMessages_SendCollectCollectableMessage(id);
}

#endif
