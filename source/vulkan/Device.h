#ifndef H_DEVICE
#define H_DEVICE 1

#include <vulkan\vulkan.h>

class Device
{
public:
    Device();
    ~Device();

    VkResult Init();
    void Destroy();

private:

};

#endif // !H_DEVICE
