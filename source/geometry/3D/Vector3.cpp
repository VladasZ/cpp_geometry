//
//  Vector3.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <cmath>

#include "Log.hpp"
#include "Vector3.hpp"
#include "Matrix4.hpp"
#include "StringUtils.hpp"
#include "JsonInclude.hpp"

using namespace gm;
using namespace std;


const Point& Vector3::point() const {
	return reinterpret_cast<const Point&>(x);
}

void Vector3::set_length(Float _length) {
	*this *= _length / length();
}

Vector3 Vector3::with_length(Float _length) const {
	return *this * _length / length();
}

Float Vector3::xy_angle() const {
	return std::atan2(y, x);
}

Float Vector3::xz_angle() const {
	return std::atan2(z, x);
}

Vector3 Vector3::cross(const Vector3& vec) const {
	return {
			y * vec.z - z * vec.y,
			z * vec.x - x * vec.z,
			x * vec.y - y * vec.x
	};
}

Float Vector3::dot(const Vector3& vec) const {
	return x * vec.x + y * vec.y + z * vec.z;
}

Vector3 Vector3::normalized() const {
	Vector3 result = *this;
	result *= 1 / length();
	return result;
}

Vector3 Vector3::with_fliped_height() const {
	return { x, z, y };
}

Vector3& Vector3::flip_height() {
	std::swap(y, z);
	return *this;
}

void Vector3::orbit_shift(const Point& shift) {
	*this = Matrix4::transform::rotation_z(shift.x) * *this;
	const auto _length = length();
	const auto step = _length * 2;
	z += shift.y * step;
	set_length(_length);
}

Vector3 Vector3::from_json(const string& json_string) {
#ifdef USING_JSON
	auto json = nlohmann::json::parse(json_string);
	Vector3 result;
	result.x = json["x"].get<float>();
	result.y = json["y"].get<float>();
	result.z = json["z"].get<float>();
	return result;
#else
    return { };
#endif
}

string Vector3::to_json() const {
#ifdef USING_JSON
	return nlohmann::json {
		{ "x", x },
		{ "y", y },
		{ "z", z }
	}.dump();
#else
    return "Built without JSON";
#endif
}
