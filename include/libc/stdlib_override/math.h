#ifndef __STDLIB_OVERRIDE_MATH_H__
#define __STDLIB_OVERRIDE_MATH_H__

#define _MATH_H
#include "libc/math.h"

#if __has_include_next(<math.h>)
#  include_next <math.h>
#endif

#endif