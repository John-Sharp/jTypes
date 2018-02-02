#include "jTypes.h"
#include <math.h>

jfloat * jvecAdd(jvec a, jvec b)
{
    a[0] += b[0];
    a[1] += b[1];

    return a;
}

jfloat * jvecSub(jvec a, jvec b)
{
    a[0] -= b[0];
    a[1] -= b[1];

    return a;
}

jfloat * jvecNorm(jvec a)
{
    jfloat mag = sqrtf(a[0]*a[0] + a[1]*a[1]);
    a[0] /= mag;
    a[1] /= mag;
    return a;
}

jfloat jvecDot(jvec a, jvec b)
{
    return a[0]*b[0] + a[1]*b[1];
}

