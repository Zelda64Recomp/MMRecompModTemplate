#ifndef LIBC_STDLIB_H
#define LIBC_STDLIB_H

#include "stddef.h"

typedef struct {
    /* 0x0 */ int quot;
    /* 0x4 */ int rem;
} div_t;

typedef struct {
    /* 0x0 */ long quot;
    /* 0x4 */ long rem;
} ldiv_t;

typedef struct {
    /* 0x0 */ long long quot;
    /* 0x8 */ long long rem;
} lldiv_t;


#ifdef __cplusplus
extern "C" {
#endif

ldiv_t ldiv(long numer, long denom);
lldiv_t lldiv(long long numer, long long denom);

__attribute__((noreturn)) void abort(void);

double strtod(const char* __restrict__ nptr, char** __restrict__ endptr);
float strtof(const char* __restrict__ nptr, char** __restrict__ endptr);
long double strtold(const char* __restrict__ nptr, char** __restrict__ endptr);
long int strtol(const char* __restrict__ nptr, char** __restrict__ endptr, int base);
long long int strtoll(const char* __restrict__ nptr, char** __restrict__ endptr, int base);
unsigned long int strtoul(const char* __restrict__ nptr, char** __restrict__ endptr, int base);
unsigned long long int strtoull(const char* __restrict__ nptr,
                                char** __restrict__ endptr, int base);

int snprintf(char* __restrict__ s, size_t n, const char* __restrict__ format, ...);

void *malloc( size_t size );
void free(void* ptr);

int posix_memalign(void **memptr, size_t alignment, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* STDLIB_H */