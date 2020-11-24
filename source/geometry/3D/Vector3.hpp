//
//  Vector3.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <cmath>
#include <vector>

#include "Point.hpp"
#include "GmMath.hpp"


namespace gm {

    enum class Axis {
        X = 0, 
        Y = 1, 
        Z = 2,
        None
    };

    template <class T>
    class V3 {

    public:

        using Value = T;

        T x = 0;
        T y = 0;
        T z = 0;

        constexpr V3() = default;
        constexpr explicit V3(T value)            : x(value),   y(value),   z(value) { }
        constexpr explicit V3(const Point& point) : x(point.x), y(point.y), z(0)     { }
        constexpr V3(T x, T y, T z = 0)           : x(x),       y(y),       z(z)     { }

        constexpr T length() const { return gm::math::sqrt(x * x + y * y + z * z); }

        std::string to_string() const {
            return std::string() + "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
        }
    };

    class Vector3 : public V3<float> {

    public:

        using V3<float>::V3;

        const Point& point() const;

        void set_length(float);

        Vector3 with_length(float) const;

        Value xy_angle() const;
        Value xz_angle() const;

        Vector3 cross(const Vector3&) const;
        Value     dot(const Vector3&) const;

        constexpr void normalize() { *this *= 1 / length(); }

        Vector3 normalized() const;

        Vector3 with_fliped_height() const;
        Vector3& flip_height();

        Value* data() { return &x; }

        constexpr Vector3 operator +  (const Vector3& v) const { return { x +  v.x, y +  v.y, z +  v.z }; }
        constexpr void    operator += (const Vector3& v)                { x += v.x; y += v.y; z += v.z; }

        constexpr Vector3 operator -  (const Vector3& v) const { return { x -  v.x, y -  v.y, z -  v.z }; }
        constexpr void    operator -= (const Vector3& v)                { x -= v.x; y -= v.y; z -= v.z; }

        constexpr Vector3 operator +  (float v) const { return { x +  v, y +  v, z +  v }; }
        constexpr void    operator += (float v)                { x += v; y += v; z += v; }

        constexpr Vector3 operator -  (float v) const { return { x -  v, y -  v, z -  v }; }
        constexpr void    operator -= (float v)                { x -= v; y -= v; z -= v; }

        constexpr Vector3 operator *  (float v) const { return { x *  v, y *  v, z *  v }; }
        constexpr void    operator *= (float v)                { x *= v; y *= v; z *= v; }

        constexpr Vector3 operator /  (float v) const { return { x /  v, y /  v, z /  v }; }
        constexpr void    operator /= (float v)                { x /= v; y /= v; z /= v; }

        constexpr float distance_to(const Vector3& vec) const {
            const auto _x = x - vec.x;
            const auto _y = y - vec.y;
            const auto _z = z - vec.z;
            return gm::math::sqrt(_x * _x + _y * _y + _z * _z);
        }

        void orbit_shift(const Point&);

        Value get_axis(Axis axis) const {
            return (&x)[(int)axis];
        }

        void set_axis(Axis axis, Value value) {
            data()[(int)axis] = value;
        }

        template<class T>
        void append_to_container(T& container) const {
            container.push_back(x);
            container.push_back(y);
            container.push_back(z);
        }

        std::string to_string() const {
            return std::string() + "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
        }

        template <class T>
        static auto average_point(const T& points) {
            Vector3 result;
            for (const auto& point : points) {
                result += point;
            }
            return result / static_cast<float>(points.size());
        }

        template <class ArrayT>
        static Vector3 middle_point(const ArrayT& points) {
            static const auto max_value = std::numeric_limits<float>::max();
            static const auto min_value = std::numeric_limits<float>::min();

            auto max_x = min_value, min_x = max_value;
            auto max_y = min_value, min_y = max_value;
            auto max_z = min_value, min_z = max_value;

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

		static Vector3 from_json(const std::string&);
		std::string to_json() const;

    };

}
