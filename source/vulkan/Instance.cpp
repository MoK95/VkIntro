#include "Instance.h"

Instance::Instance()
{

}

Instance::~Instance()
{

}

void Instance::Destroy()
{
    vkDestroyInstance(m_instance, NULL);
}

VkInstance Instance::GetInstance() const
{
    return m_instance;
}

VkResult Instance::Init()
{
    // Initialise the vulkan instance.
    VkApplicationInfo applicationInfo;
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pNext = NULL;
    applicationInfo.applicationVersion = 1;
    applicationInfo.pApplicationName = "VulkanApp";
    applicationInfo.engineVersion = 1;
    applicationInfo.pEngineName = "VulkanEngine";
    applicationInfo.apiVersion = VK_API_VERSION_1_1;

    VkInstanceCreateInfo instanceCreateInfo;
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pNext = NULL;
    instanceCreateInfo.flags = 0;
    instanceCreateInfo.pApplicationInfo = &applicationInfo;
    instanceCreateInfo.enabledLayerCount = 0;
    instanceCreateInfo.ppEnabledLayerNames = NULL;
    instanceCreateInfo.enabledExtensionCount = 0;
    instanceCreateInfo.ppEnabledExtensionNames = NULL;

    VkResult err = vkCreateInstance(&instanceCreateInfo, NULL, &m_instance);
    if (err != VK_SUCCESS)
    {
        return err;
    }
    
    // Get all physical devices and properties, allowing users to query and choose a device to work with.
    uint32_t deviceCount;
    vkEnumeratePhysicalDevices(m_instance, &deviceCount, NULL);
    
    if (deviceCount <= 0)
    {
        return VK_ERROR_DEVICE_LOST;
    }

    std::vector<VkPhysicalDevice> physicalDevices(deviceCount);

    vkEnumeratePhysicalDevices(m_instance, &deviceCount, physicalDevices.data());

    m_physicalDeviceInfo.reserve(deviceCount);

    PhysicalDeviceInfo physicalDeviceInfo;
    for (const auto& physicalDevice : physicalDevices)
    {
        physicalDeviceInfo.handle = physicalDevice;
        vkGetPhysicalDeviceProperties(physicalDeviceInfo.handle, &physicalDeviceInfo.properties);
        m_physicalDeviceInfo.push_back(physicalDeviceInfo);
    }

    return err;
}

uint32_t Instance::GetPhysicalDeviceCount() const
{
    return m_physicalDeviceInfo.size();
}

PhysicalDeviceInfo Instance::GetPhysicalDeviceInfo(uint32_t index) const
{
    if(index < m_physicalDeviceInfo.size())
        return m_physicalDeviceInfo[index];

    return PhysicalDeviceInfo();
}