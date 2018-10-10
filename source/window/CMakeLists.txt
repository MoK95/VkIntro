add_library(Window
	Window.cpp
	Window.h
	WindowWin32.cpp
	WindowWin32.h
	WindowX.cpp
	WindowX.h)
	
target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})