#ifndef __STDLIB_OVERRIDE_WCTYPE_H__
#define __STDLIB_OVERRIDE_WCTYPE_H__

#define _WCTYPE_H
#include "libc/wchar.h"

#if __has_include_next(<math.h>)
#  include_next <wctype.h>
#endif

#endif