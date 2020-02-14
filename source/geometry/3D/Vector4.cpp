//
//  Vector4.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <math.h>
#include <string>

#include "Vector4.hpp"

using namespace gm;

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {

}

float Vector4::length() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

Vector4& Vector4::normalize() {
    this->operator*=(1 / length());
    return *this;
}

const Vector3& Vector4::vector3() const {
    return reinterpret_cast<const Vector3&>(*this);
}

Vector4& Vector4::operator *= (float value) {
    x *= value;
    y *= value;
    z *= value;
    w *= value;
    return *this;
}

Vector4& Vector4::operator /= (float value) {
    x /= value;
    y /= value;
    z /= value;
    w /= value;
    return *this;
}

Vector4 Vector4::operator*(const Vector4& other) const {

    auto& q1 = *this;
    auto& q2 = other;

    auto x =  q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
    auto y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
    auto z =  q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
    auto w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;

    return { x, y, z, w };
}

const char* Vector4::to_string() const {
    static std::string result;
    result = std::string() + "[ "
            + std::to_string(x) + ", "
            + std::to_string(y) + ", "
            + std::to_string(z) + ", "
            + std::to_string(w) +
            " ]";
    return result.c_str();
}

Vector4 Vector4::quaternion_rotating(float x, float y, float z, float angle) {

    auto factor = sin(angle / 2.0f);

    auto _x = x * factor;
    auto _y = y * factor;
    auto _z = z * factor;

    auto w = cos(angle / 2.0f);

    Vector4 result { _x, _y, _z, w };
    result.normalize();
    return result;
}
