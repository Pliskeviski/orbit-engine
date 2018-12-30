#pragma once

#ifdef OBT_PLATFORM_WINDOWS
	#ifdef OBT_BUILD_DLL
		#define ORBIT_API __declspec(dllexport)
	#else
		#define ORBIT_API __declspec(dllimport)
	#endif 
#endif

#ifdef OBT_ENABLE_ASSERTS
	#define OBT_ASSERT(x, ...) { if(!(x)) { ORBIT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define OBT_CORE_ASSERT(x, ...) { if(!(x)) { ORBIT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define OBT_ASSERT(x, ...)
	#define OBT_CORE_ASSERT(x, ...)
#endif

// BIT Shifter
#define BIT(x) (1 << x)