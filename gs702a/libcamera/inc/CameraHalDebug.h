#ifndef __CAMERAHAL_DEBUG__
#define __CAMERAHAL_DEBUG__



//Uncomment to enable more verbose/debug logs
//#define DEBUG_LOG

#define DEBUG_LOGE   (1)
#define DEBUG_LOGD   (2)
#define DEBUG_LOGV   (4)
#define DEBUG_LOGI   (8)
#define DEBUG_DUMP_CAPS  (16)
#define DEBUG_FUNC_SEQ (32)
#define DEBUG_SAVE_FILE (64)
#define DEBUG_INTERFACE_FUNC_SEQ (128)



#ifdef DEBUG_LOG 
#define DEBUG_LEVEL  (DEBUG_LOGE|DEBUG_DUMP_CAPS|DEBUG_LOGD|DEBUG_LOGV|DEBUG_LOGI)
#else
#define DEBUG_LEVEL  (DEBUG_LOGE)
#endif

////////////////////DEBUG LEVEL/////////////////////////
//
//#undef DEBUG_LEVEL
//#define DEBUG_LEVEL (DEBUG_LOGE|DEBUG_LOGD|DEBUG_LOGV|DEBUG_LOGI|DEBUG_FUNC_SEQ|DEBUG_INTERFACE_FUNC_SEQ)
//#define DEBUG_LEVEL (DEBUG_LOGE|DEBUG_INTERFACE_FUNC_SEQ)
//
/////////////////////////////////////////////////


#include "DebugUtils.h"


#define CAMHAL_LOGDA(str)
#define CAMHAL_LOGDB(str, ...)
#define CAMHAL_LOGVA(str)
#define CAMHAL_LOGVB(str, ...)


#define CAMHAL_LOGEA 
#define CAMHAL_LOGEB 

#define CAMHAL_LOGI 

#undef LOG_FUNCTION_NAME
#undef LOG_FUNCTION_NAME_EXIT
#define LOG_FUNCTION_NAME
#define LOG_FUNCTION_NAME_EXIT

#undef LOG_IF_FUNCTION_NAME
#undef LOG_IF_FUNCTION_NAME_EXIT
#define LOG_IF_FUNCTION_NAME
#define LOG_IF_FUNCTION_NAME_EXIT


#define SAVE_FILE(buf, w, h, bpp)

#define DUMP_CAPS_LOGA  
#define DUMP_CAPS_LOGB  

#if (DEBUG_LEVEL&DEBUG_LOGE)
#undef CAMHAL_LOGEA
#undef CAMHAL_LOGEB
#define CAMHAL_LOGEA DBGUTILS_LOGEA
#define CAMHAL_LOGEB DBGUTILS_LOGEB
#endif

#if (DEBUG_LEVEL&DEBUG_LOGD)
#undef CAMHAL_LOGDA
#undef CAMHAL_LOGDB
#define CAMHAL_LOGDA DBGUTILS_LOGDA
#define CAMHAL_LOGDB DBGUTILS_LOGDB
#endif

#if (DEBUG_LEVEL&DEBUG_LOGV)
#undef CAMHAL_LOGVA
#undef CAMHAL_LOGVB
#define CAMHAL_LOGVA DBGUTILS_LOGVA
#define CAMHAL_LOGVB DBGUTILS_LOGVB
#endif

#if (DEBUG_LEVEL&DEBUG_LOGI)
#undef CAMHAL_LOGI
#define CAMHAL_LOGI DBGUTILS_LOGI
#endif


#if (DEBUG_LEVEL&DEBUG_FUNC_SEQ)
#undef LOG_FUNCTION_NAME 
#undef LOG_FUNCTION_NAME_EXIT 
#define LOG_FUNCTION_NAME DBGUTILS_LOG_FUNCTION_NAME
#define LOG_FUNCTION_NAME_EXIT DBGUTILS_LOG_FUNCTION_NAME_EXIT
#endif

#if (DEBUG_LEVEL&DEBUG_INTERFACE_FUNC_SEQ)
#undef LOG_IF_FUNCTION_NAME 
#undef LOG_IF_FUNCTION_NAME_EXIT 
#define LOG_IF_FUNCTION_NAME DBGUTILS_LOG_FUNCTION_NAME
#define LOG_IF_FUNCTION_NAME_EXIT DBGUTILS_LOG_FUNCTION_NAME_EXIT_RET
#endif


#if (DEBUG_LEVEL&DEBUG_SAVE_FILE)
#undef SAVE_FILE
#define SAVE_FILE(buf, w, h, bpp)  saveFile(buf, w, h, bpp)
#endif

#if (DEBUG_LEVEL&DEBUG_DUMP_CAPS)
#undef DUMP_CAPS_LOGA  
#undef DUMP_CAPS_LOGB  
#define DUMP_CAPS_LOGA  DBGUTILS_LOGDA
#define DUMP_CAPS_LOGB  DBGUTILS_LOGDB
#endif


#endif
