//
//  Vector4.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <cmath>
#include <nlohmann/json.hpp>

#include "Vector4.hpp"

using namespace gm;
using namespace std;


Vector4::Vector4(Float x, Float y, Float z, Float w) : x(x), y(y), z(z), w(w) { }

Float Vector4::length() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

Vector4& Vector4::normalize() {
    this->operator*=(1 / length());
    return *this;
}

const Vector3& Vector4::vector3() const {
    return reinterpret_cast<const Vector3&>(*this);
}

Vector4& Vector4::operator *= (Float value) {
    x *= value;
    y *= value;
    z *= value;
    w *= value;
    return *this;
}

Vector4& Vector4::operator /= (Float value) {
    x /= value;
    y /= value;
    z /= value;
    w /= value;
    return *this;
}

Vector4 Vector4::operator*(const Vector4& other) const {

    auto& q1 = *this;
    auto& q2 = other;

    auto _x =  q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
    auto _y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
    auto _z =  q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
    auto _w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;

    return { _x, _y, _z, _w };
}

Vector4 Vector4::transform::quaternion_rotating_x(Float angle) {
    Vector4 result { std::sin(angle / 2), 0, 0, std::cos(angle / 2) };
    result.normalize();
    return result;}

Vector4 Vector4::transform::quaternion_rotating_y(Float angle) {
    Vector4 result { 0, std::sin(angle / 2), 0, std::cos(angle / 2) };
    result.normalize();
    return result;}

Vector4 Vector4::transform::quaternion_rotating_z(Float angle) {
    Vector4 result { 0, 0, std::sin(angle / 2), std::cos(angle / 2) };
    result.normalize();
    return result;
}

Vector4 Vector4::change_hand() const {
	return { z, y, x, -w };
}

Vector4 Vector4::flip_height() const {
	return { x, z, y, -w };
}

std::string Vector4::to_string() const {
    return std::string() + "[ "
        + std::to_string(x) + ", "
        + std::to_string(y) + ", "
        + std::to_string(z) + ", "
        + std::to_string(w) + "]";
}

Vector4 Vector4::from_json(const string& json_string) {
	auto json = nlohmann::json::parse(json_string);
	Vector4 result;
	result.x = json["x"].get<float>();
	result.y = json["y"].get<float>();
	result.z = json["z"].get<float>();
	result.w = json["w"].get<float>();
	return result;
}

string Vector4::to_json() const {
	return nlohmann::json{
		{ "x", x },
		{ "y", y },
		{ "z", z },
		{ "w", w }
	}.dump();
}
