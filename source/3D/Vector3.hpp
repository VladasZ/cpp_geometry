//
//  Vector3.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <limits>
#include <vector>
#include <string>

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

    const Point& point() const;

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

    template<class T>
    void append_to_container(T& container) const {
        container.push_back(x);
        container.push_back(y);
        container.push_back(z);
    }

    std::string to_string() const;

    template <class T>
    static auto to_string(const T& points) {
        std::string result;
        for (auto& point : points)
            result += std::string() + point.to_string() + "\n";
        result.pop_back();
        return result;
    }

    template <class T>
    static auto average_point(const T& points) {
        Vector3 result;
        for (const auto& point : points)
            result += point;
        return result / static_cast<float>(points.size());
    }

    template <class T>
    static Vector3 middle_point(const T& points) {
        static const auto max_value = std::numeric_limits<Float>::max();
        static const auto min_value = std::numeric_limits<Float>::min();

        Float max_x = min_value, min_x = max_value;
        Float max_y = min_value, min_y = max_value;
        Float max_z = min_value, min_z = max_value;

        for (const auto& point : points) {
            if (point.x > max_x) max_x = point.x; if (point.x < min_x) min_x = point.x;
            if (point.y > max_y) max_y = point.y; if (point.y < min_y) min_y = point.y;
            if (point.z > max_z) max_z = point.z; if (point.z < min_z) min_z = point.z;
        }

        return {
            (max_x + min_x) / 2,
            (max_y + min_y) / 2,
            (max_z + min_z) / 2
        };
    }
};

