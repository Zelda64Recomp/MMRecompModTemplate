#ifndef LIBC_MATH_H
#define LIBC_MATH_H

// Types

typedef float float_t;
typedef double double_t;

// Constants

#define HUGE_VALF (__builtin_huge_valf())
#define HUGE_VAL (__builtin_huge_val())
#define HUGE_VALL (__builtin_huge_vall())
#define INFINITY (__builtin_inff())
#define NAN (__builtin_nanf(""))

#define FP_NAN 0
#define FP_INFINITE 1
#define FP_ZERO 2
#define FP_SUBNORMAL 3
#define FP_NORMAL 4

#define M_PI 3.14159265358979323846
#define M_PIf 3.14159265358979323846f

// Functions

#define fpclassify(x) __builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL, FP_SUBNORMAL, FP_ZERO, x)
#define fabsf(f) __builtin_fabsf((float)(f))

#define isnan(x) __builtin_isnan
#define isinf(x) __builtin_isinf
#define isfinite(x) __builtin_isfinite
#define signbit(x) __builtin_signbit

#ifdef __cplusplus
extern "C" {
#endif

double      acos(double);
float       acosf(float);
long double acosl(long double);

double      asin(double);
float       asinf(float);
long double asinl(long double);

double      atan(double);
float       atanf(float);
long double atanl(long double);

double      atan2(double, double);
float       atan2f(float, float);
long double atan2l(long double, long double);

double      ceil(double);
float       ceilf(float);
long double ceill(long double);

double      cos(double);
float       cosf(float);
long double cosl(long double);

double      cosh(double);
float       coshf(float);
long double coshl(long double);

double      exp(double);
float       expf(float);
long double expl(long double);

double      fabs(double);
long double fabsl(long double);

double      cosh(double);
float       coshf(float);
long double coshl(long double);

double      exp(double);
float       expf(float);
long double expl(long double);

double      floor(double);
float       floorf(float);
long double floorl(long double);

double      fmod(double, double);
float       fmodf(float, float);
long double fmodl(long double, long double);

double      pow(double, double);
float       powf(float, float);
long double powl(long double, long double);

double      frexp(double, int*);
float       frexpf(float, int*);
long double frexpl(long double, int*);

double      ldexp(double, int);
float       ldexpf(float, int);
long double ldexpl(long double, int);

double      log(double);
float       logf(float);
long double logl(long double);

double      log10(double);
float       log10f(float);
long double log10l(long double);

double      modf(double, double*);
float       modff(float, float*);
long double modfl(long double, long double*);

double      sin(double);
float       sinf(float);
long double sinl(long double);

double      sinh(double);
float       sinhf(float);
long double sinhl(long double);


double      sqrt(double);
float       sqrtf(float);
long double sqrtl(long double);


double      tan(double);
float       tanf(float);
long double tanl(long double);


double      tanh(double);
float       tanhf(float);
long double tanhl(long double);


double      acosh(double);
float       acoshf(float);
long double acoshl(long double);


double      asinh(double);
float       asinhf(float);
long double asinhl(long double);


double      atanh(double);
float       atanhf(float);
long double atanhl(long double);


double      cbrt(double);
float       cbrtf(float);
long double cbrtl(long double);


double      erf(double);
float       erff(float);
long double erfl(long double);


double      exp2(double);
float       exp2f(float);
long double exp2l(long double);


double      expm1(double);
float       expm1f(float);
long double expm1l(long double);


double      fdim(double, double);
float       fdimf(float, float);
long double fdiml(long double, long double);


double      erfc(double);
float       erfcf(float);
long double erfcl(long double);


double      fmax(double, double);
float       fmaxf(float, float);
long double fmaxl(long double, long double);


double      fmin(double, double);
float       fminf(float, float);
long double fminl(long double, long double);


double      hypot(double, double);
float       hypotf(float, float);
long double hypotl(long double, long double);


double      ilogb(double);
float       ilogbf(float);
long double ilogbl(long double);


double      lgamma(double);
float       lgammaf(float);
long double lgammal(long double);


double      log1p(double);
float       log1pf(float);
long double log1pl(long double);


double      log2(double);
float       log2f(float);
long double log2l(long double);

double      logb(double);
float       logbf(float);
long double logbl(long double);


double      nearbyint(double);
float       nearbyintf(float);
long double nearbyintl(long double);


double      nextafter(double, double);
float       nextafterf(float, float);
long double nextafterl(long double, long double);


double      nexttoward(double, long double);
float       nexttowardf(float, long double);
long double nexttowardl(long double, long double);

double      remainder(double, double);
float       remainderf(float, float);
long double remainderl(long double, long double);

double      remquo(double, double, int*);
float       remquof(float, float, int*);
long double remquol(long double, long double, int*);

double      scalbln(double, long);
float       scalblnf(float, long);
long double scalblnl(long double, long);

double      scalbn(double, int);
float       scalbnf(float, int);
long double scalbnl(long double, int);

double      tgamma(double);
float       tgammaf(float);
long double tgammal(long double);

#ifdef __cplusplus
}
#endif

#endif
