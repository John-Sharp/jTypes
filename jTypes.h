#ifndef JTYPES_H
#define JTYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t juint;
typedef int32_t jint;
typedef float jfloat;
typedef double jdouble;

typedef jfloat jvec[2];
typedef jint jintVec[2];

jfloat * jvecAdd(jvec a, jvec b);
jfloat * jvecSub(jvec a, jvec b);
jfloat * jvecNorm(jvec a);
jfloat jvecDot(jvec a, jvec b);

typedef struct jcircle
{
    jvec c; // centre
    jfloat r; // radius
} jcircle;

typedef struct jrect
{
  jvec bl; // bottom left
  jvec tr; // top right
} jrect;

typedef struct jintRect
{
  jintVec bl; // bottom left
  jintVec tr; // top right
} jintRect;
jintRect createJintRect(jint x1, jint y1, jint x2, jint y2);

#endif
