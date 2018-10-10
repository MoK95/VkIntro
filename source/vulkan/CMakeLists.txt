add_executable(Vulkan
	main.cpp
	Buffer.cpp
	Buffer.h
	Device.cpp
	Device.h
	Image.cpp
	Image.h
	Instance.cpp
	Instance.h
	Memory.cpp
	Memory.h
	Pipeline.cpp
	Pipeline.h
	Queue.cpp
	Queue.h
	RenderPass.cpp
	RenderPass.h)
	
find_package(Vulkan)
IF(Vulkan_FOUND)
	message(STATUS "Vulkan found!")
	include_directories(${Vulkan_INCLUDE_DIR})
ELSE()
	message(FATAL_ERROR "Failed to find vulkan!")
ENDIF()
	
target_link_libraries(Vulkan LINK_PUBLIC Window ${Vulkan_LIBRARIES})