//
//  Matrix4.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <math.h>
#include <algorithm>

#include "Matrix4.hpp"


Matrix4::Matrix4() : Matrix4 {
                         1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1  } { }

Matrix4::Matrix4(Float value) {
    for (size_t i = 0; i < Matrix4::size; i++)
        *(&data[0][0] + i) = value;
}

Matrix4::Matrix4(const std::initializer_list<Float>& list) {
    if (list.size() != Matrix4::size) throw "Matrix4 invalid initializer";
    auto pointer = list.begin();
    for (unsigned int row = 0; row < 4; row++)
        for (unsigned int column = 0; column < 4; column++)
            data[column][row] = *(pointer++);
}

Matrix4 Matrix4::inversed() const {
    Matrix4 result = *this;

    float inv[16];
    float * m = reinterpret_cast<float *>(&result);

    inv[ 0] =  m[ 5] * m[10] * m[15] -
               m[ 5] * m[11] * m[14] -
               m[ 9] * m[ 6] * m[15] +
               m[ 9] * m[ 7] * m[14] +
               m[13] * m[ 6] * m[11] -
               m[13] * m[ 7] * m[10];

    inv[ 4] = -m[ 4] * m[10] * m[15] +
               m[ 4] * m[11] * m[14] +
               m[ 8] * m[ 6] * m[15] -
               m[ 8] * m[ 7] * m[14] -
               m[12] * m[ 6] * m[11] +
               m[12] * m[ 7] * m[10];

    inv[ 8] =  m[ 4] * m[ 9] * m[15] -
               m[ 4] * m[11] * m[13] -
               m[ 8] * m[ 5] * m[15] +
               m[ 8] * m[ 7] * m[13] +
               m[12] * m[ 5] * m[11] -
               m[12] * m[ 7] * m[ 9];

    inv[12] = -m[ 4] * m[ 9] * m[14] +
               m[ 4] * m[10] * m[13] +
               m[ 8] * m[ 5] * m[14] -
               m[ 8] * m[ 6] * m[13] -
               m[12] * m[ 5] * m[10] +
               m[12] * m[ 6] * m[ 9];

    inv[ 1] = -m[ 1] * m[10] * m[15] +
               m[ 1] * m[11] * m[14] +
               m[ 9] * m[ 2] * m[15] -
               m[ 9] * m[ 3] * m[14] -
               m[13] * m[ 2] * m[11] +
               m[13] * m[ 3] * m[10];

    inv[ 5] =  m[ 0] * m[10] * m[15] -
               m[ 0] * m[11] * m[14] -
               m[ 8] * m[ 2] * m[15] +
               m[ 8] * m[ 3] * m[14] +
               m[12] * m[ 2] * m[11] -
               m[12] * m[ 3] * m[10];

    inv[ 9] = -m[ 0] * m[ 9] * m[15] +
               m[ 0] * m[11] * m[13] +
               m[ 8] * m[ 1] * m[15] -
               m[ 8] * m[ 3] * m[13] -
               m[12] * m[ 1] * m[11] +
               m[12] * m[ 3] * m[ 9];

    inv[13] =  m[ 0] * m[ 9] * m[14] -
               m[ 0] * m[10] * m[13] -
               m[ 8] * m[ 1] * m[14] +
               m[ 8] * m[ 2] * m[13] +
               m[12] * m[ 1] * m[10] -
               m[12] * m[ 2] * m[ 9];

    inv[ 2] =  m[ 1] * m[ 6] * m[15] -
               m[ 1] * m[ 7] * m[14] -
               m[ 5] * m[ 2] * m[15] +
               m[ 5] * m[ 3] * m[14] +
               m[13] * m[ 2] * m[ 7] -
               m[13] * m[ 3] * m[ 6];

    inv[ 6] = -m[ 0] * m[ 6] * m[15] +
               m[ 0] * m[ 7] * m[14] +
               m[ 4] * m[ 2] * m[15] -
               m[ 4] * m[ 3] * m[14] -
               m[12] * m[ 2] * m[ 7] +
               m[12] * m[ 3] * m[ 6];

    inv[10] =  m[ 0] * m[ 5] * m[15] -
               m[ 0] * m[ 7] * m[13] -
               m[ 4] * m[ 1] * m[15] +
               m[ 4] * m[ 3] * m[13] +
               m[12] * m[ 1] * m[ 7] -
               m[12] * m[ 3] * m[ 5];

    inv[14] = -m[ 0] * m[ 5] * m[14] +
               m[ 0] * m[ 6] * m[13] +
               m[ 4] * m[ 1] * m[14] -
               m[ 4] * m[ 2] * m[13] -
               m[12] * m[ 1] * m[ 6] +
               m[12] * m[ 2] * m[ 5];

    inv[ 3] = -m[ 1] * m[ 6] * m[11] +
               m[ 1] * m[ 7] * m[10] +
               m[ 5] * m[ 2] * m[11] -
               m[ 5] * m[ 3] * m[10] -
               m[ 9] * m[ 2] * m[ 7] +
               m[ 9] * m[ 3] * m[ 6];

    inv[ 7] =  m[ 0] * m[ 6] * m[11] -
               m[ 0] * m[ 7] * m[10] -
               m[ 4] * m[ 2] * m[11] +
               m[ 4] * m[ 3] * m[10] +
               m[ 8] * m[ 2] * m[ 7] -
               m[ 8] * m[ 3] * m[ 6];

    inv[11] = -m[ 0] * m[ 5] * m[11] +
               m[ 0] * m[ 7] * m[ 9] +
               m[ 4] * m[ 1] * m[11] -
               m[ 4] * m[ 3] * m[ 9] -
               m[ 8] * m[ 1] * m[ 7] +
               m[ 8] * m[ 3] * m[ 5];

    inv[15] =  m[ 0] * m[ 5] * m[10] -
               m[ 0] * m[ 6] * m[ 9] -
               m[ 4] * m[ 1] * m[10] +
               m[ 4] * m[ 2] * m[ 9] +
               m[ 8] * m[ 1] * m[ 6] -
               m[ 8] * m[ 2] * m[ 5];

    float det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det == 0)
        throw std::string() + "Matrix4. Determinant equal 0";

    det = 1.0f / det;

    for (int i = 0; i < 16; i++)
        m[i] = inv[i] * det;

    return result;
}

Matrix4 Matrix4::operator *(const Matrix4& in) const {

    const auto& data = in.data;
    const auto& mat = *this;

    Matrix4 res;
    res.data[0][0] = data[0][0] * mat.data[0][0] + data[0][1] * mat.data[1][0] + data[0][2] * mat.data[2][0] + data[0][3] * mat.data[3][0];
    res.data[0][1] = data[0][0] * mat.data[0][1] + data[0][1] * mat.data[1][1] + data[0][2] * mat.data[2][1] + data[0][3] * mat.data[3][1];
    res.data[0][2] = data[0][0] * mat.data[0][2] + data[0][1] * mat.data[1][2] + data[0][2] * mat.data[2][2] + data[0][3] * mat.data[3][2];
    res.data[0][3] = data[0][0] * mat.data[0][3] + data[0][1] * mat.data[1][3] + data[0][2] * mat.data[2][3] + data[0][3] * mat.data[3][3];

    res.data[1][0] = data[1][0] * mat.data[0][0] + data[1][1] * mat.data[1][0] + data[1][2] * mat.data[2][0] + data[1][3] * mat.data[3][0];
    res.data[1][1] = data[1][0] * mat.data[0][1] + data[1][1] * mat.data[1][1] + data[1][2] * mat.data[2][1] + data[1][3] * mat.data[3][1];
    res.data[1][2] = data[1][0] * mat.data[0][2] + data[1][1] * mat.data[1][2] + data[1][2] * mat.data[2][2] + data[1][3] * mat.data[3][2];
    res.data[1][3] = data[1][0] * mat.data[0][3] + data[1][1] * mat.data[1][3] + data[1][2] * mat.data[2][3] + data[1][3] * mat.data[3][3];

    res.data[2][0] = data[2][0] * mat.data[0][0] + data[2][1] * mat.data[1][0] + data[2][2] * mat.data[2][0] + data[2][3] * mat.data[3][0];
    res.data[2][1] = data[2][0] * mat.data[0][1] + data[2][1] * mat.data[1][1] + data[2][2] * mat.data[2][1] + data[2][3] * mat.data[3][1];
    res.data[2][2] = data[2][0] * mat.data[0][2] + data[2][1] * mat.data[1][2] + data[2][2] * mat.data[2][2] + data[2][3] * mat.data[3][2];
    res.data[2][3] = data[2][0] * mat.data[0][3] + data[2][1] * mat.data[1][3] + data[2][2] * mat.data[2][3] + data[2][3] * mat.data[3][3];

    res.data[3][0] = data[3][0] * mat.data[0][0] + data[3][1] * mat.data[1][0] + data[3][2] * mat.data[2][0] + data[3][3] * mat.data[3][0];
    res.data[3][1] = data[3][0] * mat.data[0][1] + data[3][1] * mat.data[1][1] + data[3][2] * mat.data[2][1] + data[3][3] * mat.data[3][1];
    res.data[3][2] = data[3][0] * mat.data[0][2] + data[3][1] * mat.data[1][2] + data[3][2] * mat.data[2][2] + data[3][3] * mat.data[3][2];
    res.data[3][3] = data[3][0] * mat.data[0][3] + data[3][1] * mat.data[1][3] + data[3][2] * mat.data[2][3] + data[3][3] * mat.data[3][3];
    return res;
}

Matrix4& Matrix4::operator *=(const Matrix4& mat) {
    return *this = this->operator*(mat);
}

Vector3 Matrix4::operator * (const Vector3& vec) const {
    return {
        data[0][0] * vec.x + data[1][0] * vec.y + data[2][0] * vec.z + data[3][0] * 1,
        data[0][1] * vec.x + data[1][1] * vec.y + data[2][1] * vec.z + data[3][1] * 1,
        data[0][2] * vec.x + data[1][2] * vec.y + data[2][2] * vec.z + data[3][2] * 1
    };
}

Vector3 Matrix4::multiply_by_normal(const Vector3& vec) const {
    return {
        data[0][0] * vec.x + data[1][0] * vec.y + data[2][0] * vec.z,
        data[0][1] * vec.x + data[1][1] * vec.y + data[2][1] * vec.z,
        data[0][2] * vec.x + data[1][2] * vec.y + data[2][2] * vec.z
    };
}

std::string Matrix4::to_string() const {
    std::string result;

    static const uint8_t row_count = static_cast<uint8_t>(sqrt(Matrix4::size));

    for (size_t i = 0; i < Matrix4::size; i++) {
        if (i % row_count == 0)
            result += "\n";
        result += std::to_string(*(&data[0][0] + i)) + " ";
    }

    return result;
}

Matrix4 Matrix4::transform::scale(Float scale) {
    return  {
        scale,     0,     0, 0,
            0, scale,     0, 0,
            0,     0, scale, 0,
            0,     0,     0, 1
    };
}

Matrix4 Matrix4::transform::scale(const Vector3& scale) {
    return  {
        scale.x,       0,       0, 0,
              0, scale.y,       0, 0,
              0,       0, scale.z, 0,
              0,       0,       0, 1
    };
}

Matrix4 Matrix4::transform::translation(const Vector3& location) {
    return {
        1, 0, 0, location.x,
        0, 1, 0, location.y,
        0, 0, 1, location.z,
        0, 0, 0, 1
    };
}

Matrix4 Matrix4::transform::rotation_x(Float angle) {
    const auto cos_x = cos(angle);
    const auto sin_x = sin(angle);
    return {
        1,      0,     0, 0,
        0,  cos_x, sin_x, 0,
        0, -sin_x, cos_x, 0,
        0,      0,     0, 1
    };
}

Matrix4 Matrix4::transform::rotation_y(Float angle) {
    const auto cos_y = cos(angle);
    const auto sin_y = sin(angle);
    return {
        cos_y, 0, -sin_y, 0,
            0, 1,      0, 0,
        sin_y, 0,  cos_y, 0,
            0, 0,      0, 1
    };
}

Matrix4 Matrix4::transform::rotation_z(Float angle) {
    const auto cos_z = cos(angle);
    const auto sin_z = sin(angle);
    return {
        cos_z, sin_z, 0, 0,
       -sin_z, cos_z, 0, 0,
            0,     0, 1, 0,
            0,     0, 0, 1
    };
}

Matrix4 Matrix4::transform::perspective(Float fovy, Float aspect, Float z_near, Float z_far) {

    const auto tan_half_fovy = static_cast<Float>(tan(fovy / 2.0f));

    Matrix4 result(0.0f);
    result.data[0][0] =  1.0f / (aspect * tan_half_fovy);
    result.data[1][1] =  1.0f / (tan_half_fovy);
    result.data[2][3] = -1.0f;

    result.data[2][2] = -(z_far +        z_near) / (z_far - z_near);
    result.data[3][2] = -(2.0f * z_far * z_near) / (z_far - z_near);

    return result;
}

Matrix4 Matrix4::transform::look_at(const Vector3& eye, const Vector3& center, const Vector3& up) {

    const auto f = (center - eye).normalized();
    const auto s = (f.cross(up)).normalized();
    const auto u = s.cross(f);

    Matrix4 result;

    result.data[0][0] =  s.x;
    result.data[1][0] =  s.y;
    result.data[2][0] =  s.z;
    result.data[0][1] =  u.x;
    result.data[1][1] =  u.y;
    result.data[2][1] =  u.z;
    result.data[0][2] = -f.x;
    result.data[1][2] = -f.y;
    result.data[2][2] = -f.z;
    result.data[3][0] = -s.dot(eye);
    result.data[3][1] = -u.dot(eye);
    result.data[3][2] =  f.dot(eye);

    return result;
}

Matrix4 Matrix4::transform::model_look_at(const Vector3& target) {
    const auto rotation_z      = Matrix4::transform::rotation_z(-target.xy_angle());
    const auto rotation_back_z = Matrix4::transform::rotation_z(target.xy_angle());
    const auto rotated_target  = rotation_back_z * target;
    const auto rotation_y      = Matrix4::transform::rotation_y(rotated_target.xz_angle());
    return rotation_z * rotation_y;
}
