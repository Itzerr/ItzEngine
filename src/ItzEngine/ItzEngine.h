#pragma once

#ifdef ITZENGINE_STATIC
  #define ITZENGINE_API
#else
  #ifdef _WIN32
    #ifdef ITZENGINE_EXPORT
      #define ITZENGINE_API __declspec(dllexport)
    #else
      #define ITZENGINE_API __declspec(dllimport)
    #endif
  #else
    #define ITZENGINE_API __attribute__((__visibility__("default")))
  #endif
#endif