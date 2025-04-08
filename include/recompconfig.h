#ifndef __RECOMPCONFIG_H__
#define __RECOMPCONFIG_H__

#include "modding.h"

RECOMP_IMPORT("*", unsigned long recomp_get_config_u32(const char* key));
RECOMP_IMPORT("*", double recomp_get_config_double(const char* key));
RECOMP_IMPORT("*", char* recomp_get_config_string(const char* key));
RECOMP_IMPORT("*", void recomp_free_config_string(char* str));
RECOMP_IMPORT("*", void recomp_get_mod_version(unsigned long* major, unsigned long* minor, unsigned long* patch));

#endif
