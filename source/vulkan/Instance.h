#ifndef H_INSTANCE
#define H_INSTANCE 1

#include <vulkan\vulkan.h>
#include <vector>

struct PhysicalDeviceInfo
{
    VkPhysicalDevice handle;
    VkPhysicalDeviceProperties properties;
};

class Instance
{
public:
    Instance();
    ~Instance();

    VkResult Init();
    void Destroy();

    VkInstance GetInstance() const;
    uint32_t GetPhysicalDeviceCount() const;
    PhysicalDeviceInfo GetPhysicalDeviceInfo(uint32_t index) const;

private:
    VkInstance m_instance;
    std::vector<PhysicalDeviceInfo> m_physicalDeviceInfo;
};

#endif // !H_INSTANCE