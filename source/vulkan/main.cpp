#include <WindowWin32.h>
#include <iostream>
#include <vector>
#include "Instance.h"

int main()
{
    Instance instance;

    auto success = instance.Init();

    if (success != VK_SUCCESS)
    {
        return 1;
    }

    uint32_t deviceCount = instance.GetPhysicalDeviceCount();

    PhysicalDeviceInfo info;
    for (uint32_t i = 0; i < deviceCount; ++i)
    {
        info = instance.GetPhysicalDeviceInfo(i);
        if (info.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
        {
            break;
        }
    }


    instance.Destroy();


    getchar();
    return 0;
}