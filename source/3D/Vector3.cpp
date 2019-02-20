//
//  Vector3.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <math.h>
#include <string>

#include "Vector3.hpp"
#include "Matrix4.hpp"

const Point& Vector3::point() const {
    return reinterpret_cast<const Point&>(x);
}

Vector3::Float Vector3::length() const {
    return static_cast<Float>(sqrt(x * x + y * y + z * z));
}

void Vector3::set_length(Float length) {
    const float ratio = length / this->length();
    this->operator*=(ratio);
}

Vector3 Vector3::cross(const Vector3& vec) const {
    return {
        y * vec.z - z * vec.y,
        z * vec.x - x * vec.z,
        x * vec.y - y * vec.x
	};
}

Vector3::Float Vector3::dot(const Vector3& vec) const {
	return x * vec.x + y * vec.y + z * vec.z;
}

Vector3& Vector3::normalize() {
    return this->operator*=(1 / length());
}

Vector3 Vector3::normalized() const {
    Vector3 result = *this;
    return result *= 1 / length();
}

Vector3 Vector3::operator + (const Vector3& vec) const {
	return {
		x + vec.x,
		y + vec.y,
		z + vec.z
	};
}

Vector3& Vector3::operator += (const Vector3& vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector3 Vector3::operator - (const Vector3& vec) const {
	return {
		x - vec.x,
		y - vec.y,
		z - vec.z
	};
}

Vector3& Vector3::operator -= (const Vector3& vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

Vector3 Vector3::operator * (Float value) const {
	return {
		x * value,
		y * value,
		z * value
	};
}

Vector3& Vector3::operator *= (Float value) {
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3 Vector3::operator / (Float value) const {
    return {
        x / value,
        y / value,
        z / value
    };
}

Vector3& Vector3::operator /= (Float value) {
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3 Vector3::operator + (Float value) const {
    return {
        x + value,
        y + value,
        z + value
    };
}

Vector3& Vector3::operator += (Float value) {
    x += value;
    y += value;
    z += value;
    return *this;
}

Vector3 Vector3::operator - (Float value) const {
    return {
        x - value,
        y - value,
        z - value
    };
}

Vector3& Vector3::operator -= (Float value) {
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

void Vector3::orbit_shift(const Point& shift) {
    *this = Matrix4::transform::rotation_z(shift.x) * *this;
    const auto _length = length();
    const auto step = _length * 2;
    z += shift.y * step;
    set_length(_length);
}

std::string Vector3::to_string() const {
    return std::string() + "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + " ]";
}
