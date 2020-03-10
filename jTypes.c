#include "jTypes.h"
#include <math.h>

jfloat * jcolorSet(jcolor color, jfloat r, jfloat g, jfloat b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;

    return color;
}

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

jintRect createJintRect(jint x1, jint y1, jint x2, jint y2)
{
    jintRect ret = {.bl = {{x1, y1}}, .tr = {{x2, y2}}};
    return ret;
}

jintLine createJintLine(jintVec rStart, jintVec sTarg, jint tScale) 
{
    jintLine ret = {
        .rStart = rStart,
        .sTarg = sTarg,
        .tScale = tScale
    };

    return ret;
}

jintVec jintLineGetPosition(const jintLine * l, jint t)
{
    jintVec ret = {{
        l->rStart.v[0] + t * l->sTarg.v[0] / l->tScale,
        l->rStart.v[1] + t * l->sTarg.v[1] / l->tScale 
    }};

    return ret;
}

jintAxPlLine createJintAxPlLine(
        AX_PL_DIR direction, jintVec rStart, jint length)
{
    jintAxPlLine ret = {
        .direction = direction,
        .rStart = rStart,
        .length = length
    };

    return ret;
}
