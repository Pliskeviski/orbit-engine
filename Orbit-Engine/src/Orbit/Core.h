#pragma once

#ifdef OBT_PLATFORM_WINDOWS
	#ifdef OBT_BUILD_DLL
		#define ORBIT_API __declspec(dllexport)
	#else
		#define ORBIT_API __declspec(dllimport)
	#endif 
#endif

// BIT Shifter
#define BIT(x) (1 << x)