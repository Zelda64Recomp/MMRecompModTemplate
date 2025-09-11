#ifndef __STDLIB_OVERRIDE_STDINT_H__
#define __STDLIB_OVERRIDE_STDINT_H__

#define _STDINT_H
#include "libc/stdint.h"

#if __has_include_next(<stdint.h>)
#  include_next <stdint.h>
#endif

#endif