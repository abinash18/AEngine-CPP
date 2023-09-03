/*****************************************************************/ /**
 * \file   Core.h
 * \brief  Macros for dll imports and exports for engine methods.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#pragma once

#ifdef AE_PLATFORM_WINDOWS
    #if AE_DYNAMIC_LINK
        #ifdef AE_BUILD_DLL
            #define AE_API __declspec(dllexport)
        #else
            #define AE_API __declspec(dllimport)
        #endif // AE_BUILD_DLL
    #else
        #define AE_API
    #endif
#else
    #error AE Only supports windows.
#endif // AE_PLATFORM_WINDOWS

#ifdef AE_DEBUG
    #define AE_ENABLE_ASSERTS
#endif

#ifdef AE_ENABLE_ASSERTS
    #define AE_ASSERT(x, ...) { if(!(x)) { AE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
    #define AE_CORE_ASSERT(x, ...) { if(!(x)) { AE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
    #define AE_ASSERT(x, ...)
    #define AE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
