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

jintVec jintVecAdd(const jintVec a, const jintVec b)
{
    jintVec ret;

    ret.v[0] = a.v[0] + b.v[0];
    ret.v[1] = a.v[1] + b.v[1];

    return ret;
}

jintVec jintVecSub(const jintVec a, const jintVec b)
{
    jintVec ret;

    ret.v[0] = a.v[0] - b.v[0];
    ret.v[1] = a.v[1] - b.v[1];

    return ret;
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

jint jintRectGetWidth(const jintRect * r)
{
    return r->tr.v[0] - r->bl.v[0];
}

jint jintRectGetHeight(const jintRect * r)
{
    return r->tr.v[1] - r->bl.v[1];
}

// TODO work out the scale correctly
jintVecScaled jintVecScaledAdd(const jintVecScaled * a, const jintVecScaled * b)
{
    jintVecScaled ret = {
        .v = {{a->v.v[0] + b->v.v[0], a->v.v[1] + b->v.v[1]}},
        .s = a->s
    };
    return ret;
}

// TODO work out the scale correctly
jintVecScaled jintVecScaledSub(const jintVecScaled * a, const jintVecScaled * b)
{
    jintVecScaled ret = {
        .v = {{a->v.v[0] - b->v.v[0], a->v.v[1] - b->v.v[1]}},
        .s = a->s
    };
    return ret;
}

jintLine createJintLine(jintVec rStart, jintVecScaled sTarg) 
{
    jintLine ret = {
        .rStart = rStart,
        .sTarg = sTarg
    };

    return ret;
}

jintVec jintLineGetPosition(const jintLine * l, jint t)
{
    jintVec ret = {{
        l->rStart.v[0] + t * l->sTarg.v.v[0] / l->sTarg.s,
        l->rStart.v[1] + t * l->sTarg.v.v[1] / l->sTarg.s 
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
