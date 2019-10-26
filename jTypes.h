#ifndef JTYPES_H
#define JTYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t juint;
typedef int32_t jint;
typedef float jfloat;
typedef double jdouble;

typedef jfloat jvec[2];
typedef struct jintVec
{
    jint x;
    jint y;
} jintVec;

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


// line where the position, `r` at time `t` is given by:
// r = rStart + (t/tScale) * sTarg 
typedef struct jintLine
{
    jintVec rStart; // point where line starts
    jintVec sTarg; // direction of line
    jint tScale; // scale factor
} jintLine;
jintLine createJintLine(jintVec rStart, jintVec sTarg, jint tScale);
jintVec jintLineGetPosition(const jintLine * l, jint t);

// type that can represent line starting at `rStart` running parallel to an
// axis for `length` 
typedef enum AX_PL_DIR
{
    AX_PL_DIR_X, // parallel to x axis
    AX_PL_DIR_Y, // parallel to y axis
} AX_PL_DIR;
typedef struct jintAxPlLine
{
    AX_PL_DIR direction;

    jintVec rStart;
    jint length;
} jintAxPlLine;
jintAxPlLine createJintAxPlLine(
        AX_PL_DIR direction, jintVec rStart, jint length);

#endif
