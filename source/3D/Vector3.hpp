//
//  Vector3.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Point.hpp"

class Vector3 {
    
public:

    using Float = float;
    
    Float x = 0;
    Float y = 0;
    Float z = 0;
    
    Vector3() = default;
    Vector3(Float x, Float y, Float z = 0);

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

    float distance_to(const Vector3&) const;

    void orbit_shift(const Point&);

    const char* to_string() const;

    static const char* to_string(const std::vector<Vector3>&);

    static Vector3 middle_point(const std::vector<Vector3>&);
};

