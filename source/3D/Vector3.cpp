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
    return reinterpret_cast<const Point&>(*this);
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

#include <iostream>
using namespace std;

void Vector3::orbit_shift(const Point& shift) {

//    const auto angle = point().angle();

//    cout << "shift: " << shift.x << endl;
//    cout << "current angle: " << angle << endl;

//    const auto transform_y              = Matrix4::transform::rotation_y(shift.y);
//    const auto transform_to_zero_angle  = Matrix4::transform::rotation_z(-angle);
//    const auto transform_to_final_angle = Matrix4::transform::rotation_z((angle - shift.x));


//    const auto final_transform = transform_y * transform_to_zero_angle;

//    cout << "angle + shift: " << angle + shift.x << endl;

//    *this = final_transform * *this;

//    cout << "final angle: " << point().angle() << endl;
//    cout << "-------------" << endl;

    *this = Matrix4::transform::rotation_z(shift.x) * Matrix4::transform::rotation_x(shift.y) * *this;
}

std::string Vector3::to_string() const {
    return std::string() + "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + " ]";
}
