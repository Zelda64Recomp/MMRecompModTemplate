#ifndef __STDLIB_OVERRIDE_CTYPE_H__
#define __STDLIB_OVERRIDE_CTYPE_H__

#define _CTYPE_H

#if __has_include_next(<math.h>)
#  include_next <ctype.h>
#endif

#endif