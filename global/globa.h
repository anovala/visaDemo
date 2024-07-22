#pragma  once 

#ifdef M_PLUGIN_LIB
    #define MVISA_LIB __declspec(dllexport)
#else
    #define MVISA_LIB __declspec(dllimport)
#endif
