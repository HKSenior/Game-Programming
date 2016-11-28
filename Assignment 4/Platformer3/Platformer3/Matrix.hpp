#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include "vec.h"

class Matrix {
public:
    
    Matrix();
    
    union {
        float m[4][4];
        float ml[16];
    };
    
    void identity();
    Matrix operator * (const Matrix &m2) const;
    Matrix operator += (const Matrix& rhs) const;
    friend vec::vec4 operator * (const Matrix& lhs, const vec::vec4& rhs);
    friend Matrix operator + (const Matrix& lhs, const Matrix& rhs);
    Matrix inverse() const;
    
    void Translate(float x, float y, float z);
    void Scale(float x, float y, float z);
    void Rotate(float rotation);
    void Roll(float roll);
    void Pitch(float pitch);
    void Yaw(float yaw);
    
    void setPosition(float x, float y, float z);
    void setScale(float x, float y, float z);
    void setRotation(float rotation);
    void setRoll(float roll);
    void setPitch(float pitch);
    void setYaw(float yaw);
    
    void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);
    void setPerspectiveProjection(float fov, float aspect, float zNear, float zFar);
};

#endif /* __MATRIX_HPP__ defined */