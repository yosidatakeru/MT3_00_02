#pragma once
//#include <Novice.h>
#include <Vector3AndMatrix.h>
#include <math.h>
Matrix4x4 Add(const Matrix4x4 m1, const Matrix4x4 m2);
Matrix4x4 Sudtract(const Matrix4x4 m1, const Matrix4x4 m2);
Matrix4x4 Multiply(const Matrix4x4 m1, const Matrix4x4 m2);
Matrix4x4 inVerseM1(const Matrix4x4 m1);
Matrix4x4 inVerseM2(const Matrix4x4 m2);
Matrix4x4 transposeM1(const Matrix4x4 m1);
Matrix4x4 transposeM2(const Matrix4x4 m2);
Matrix4x4 MakeIdentity4x4(const Matrix4x4);