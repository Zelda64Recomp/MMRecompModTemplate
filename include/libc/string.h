#ifndef LIBC_STRING_H
#define LIBC_STRING_H

#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

char* strchr(const char* s, int c);
size_t strlen(const char* s);
void* memcpy(void* s1, const void* s2, size_t n);

void* memset(void* ptr, int val, size_t size);
int strcmp(const char* str1, const char* str2);
char* strcpy(char* dst, const char* src);
void* memmove(void* dst, const void* src, size_t size);
int memcmp(const void* lhs, const void* rhs, size_t count);

const char* strpbrk(const char*, const char*);
const char* strrchr(const char*, int);
const void* memchr(const void*, int, size_t);
const char* strstr(const char*, const char*);

#ifdef __cplusplus
}
#endif

#endif
