/*****************************************************************/ /**
 * \file   Core.h
 * \brief  Macros for dll imports and exports for engine methods.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#pragma once

#ifdef AE_PLATFORM_WINDOWS

    #ifdef AE_BUILD_DLL
        #define AE_API __declspec(dllexport)
    #else
        #define AE_API __declspec(dllimport)
    #endif // AE_BUILD_DLL
#else
    #error AE Only supports windows.
#endif // AE_PLATFORM_WINDOWS

#define BIT(x) (1 << x)