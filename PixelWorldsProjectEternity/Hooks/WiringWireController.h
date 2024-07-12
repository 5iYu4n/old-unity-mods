#ifndef CSY_WIRINGWIRECONTROLLER_H
#define CSY_WIRINGWIRECONTROLLER_H

void (*old_WiringWireController_Update)(void *instance);
void WiringWireController_Update(void *instance)
{
    if(instance != nullptr)
    {
        LOGI("PW -> Wiring OK");
    }
    old_WiringWireController_Update(instance);
}

#endif //CSY_WIRINGWIRECONTROLLER_H
