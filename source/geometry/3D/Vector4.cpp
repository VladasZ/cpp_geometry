//
//  Vector4.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <cmath>
#include <string>

#include "Vector4.hpp"

using namespace gm;

Vector4::Vector4(const Vector3& vec3, float w) : Vector4(vec3.x, vec3.y, vec3.z, w) {

}

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

Vector4 Vector4::transform::quaternion_rotating_x(float angle) {
    Vector4 result { sin(angle / 2.0f), 0, 0, cos(angle / 2.0f) };
    result.normalize();
    return result;}

Vector4 Vector4::transform::quaternion_rotating_y(float angle) {
    Vector4 result { 0, sin(angle / 2.0f), 0, cos(angle / 2.0f) };
    result.normalize();
    return result;}

Vector4 Vector4::transform::quaternion_rotating_z(float angle) {
    Vector4 result { 0, 0, sin(angle / 2.0f), cos(angle / 2.0f) };
    result.normalize();
    return result;
}

std::string Vector4::to_string() const {
    return std::string() + "[ "
           + std::to_string(x) + ", "
           + std::to_string(y) + ", "
           + std::to_string(z) + ", "
           + std::to_string(w) +
           " ] " +
           "Length: " + std::to_string(length());
}
