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

Vector3::Vector3(Float x, Float y, Float z) : x(x), y(y), z(z) {

}

Vector3::Float Vector3::length() const {
    return static_cast<Float>(sqrt(x * x + y * y + z * z));
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
    return *this *= 1 / length();
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

const char* Vector3::to_string() const {
    static std::string result;
    result = std::string() + "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + " ]";
    return result.c_str();
}

const char* Vector3::to_string(const std::vector<Vector3>& points) {
    static std::string result;
    result.clear();
    for (const auto& point : points)
        result += std::string() + point.to_string() + "\n";
    result.pop_back();
    return result.c_str();
}

Vector3 Vector3::middle_point(const std::vector<Vector3>& points) {
	Vector3 result;
	for (const auto& point : points)
		result += point;
	return result / points.size();
}
