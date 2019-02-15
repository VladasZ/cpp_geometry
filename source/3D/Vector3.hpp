//
//  Vector3.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Math.hpp"
#include "Point.hpp"

class Vector3 {
    
public:

    using Float = float;
    
    Float x = 0;
    Float y = 0;
    Float z = 0;
    
    constexpr Vector3() { }
    constexpr Vector3(Float x, Float y, Float z = 0) : x(x), y(y), z(z) { }

    Point point() const;

    Float length() const;
    
    Vector3 cross(const Vector3&) const;
    Float     dot(const Vector3&) const;

    Vector3& normalize();
    Vector3 normalized() const;

    Vector3  operator +  (const Vector3&) const;
    Vector3& operator += (const Vector3&);

    Vector3  operator -  (const Vector3&) const;
    Vector3& operator -= (const Vector3&);

    Vector3  operator *  (Float) const;
    Vector3& operator *= (Float);

    Vector3  operator /  (Float) const;
    Vector3& operator /= (Float);

    constexpr float distance_to(const Vector3& vec) const {
        const auto _x = x - vec.x;
        const auto _y = y - vec.y;
        const auto _z = z - vec.z;
        return math::sqrt(_x * _x + _y * _y + _z * _z);
    }

    void orbit_shift(const Point&);

    const char* to_string() const;

    static const char* to_string(const std::vector<Vector3>&);

    static Vector3 middle_point(const std::vector<Vector3>&);
};

