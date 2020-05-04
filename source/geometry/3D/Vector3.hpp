//
//  Vector3.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Point.hpp"
#include "GmMath.hpp"
#include "ForceInitializable.hpp"


namespace gm {

    enum class Axis {
        None,
        X, Y, Z
    };

    class Vector3 : public cu::ForceInitializable<Vector3> {

    public:

        Float x = 0;
        Float y = 0;
        Float z = 0;

        constexpr Vector3() = default;
        constexpr explicit Vector3(Float value)          : x(value),   y(value),   z(value) { }
        constexpr explicit Vector3(const Point& point)   : x(point.x), y(point.y), z(0)     { }
        constexpr Vector3(Float x, Float y, Float z = 0) : x(x),       y(y),       z(z)     { }

        const Point& point() const;

        constexpr Float length() const { return math::sqrt(x * x + y * y + z * z); }
        void set_length(Float);

        Vector3 with_length(Float) const;

        Float xy_angle() const;
        Float xz_angle() const;

        Vector3 cross(const Vector3&) const;
        Float     dot(const Vector3&) const;

        constexpr void normalize() { *this *= 1 / length(); }

        Vector3 normalized() const;

        Vector3& flip_height();

        constexpr Vector3 operator +  (const Vector3& v) const { return { x +  v.x, y +  v.y, z +  v.z }; }
        constexpr void    operator += (const Vector3& v)                { x += v.x; y += v.y; z += v.z; }

        constexpr Vector3 operator -  (const Vector3& v) const { return { x -  v.x, y -  v.y, z -  v.z }; }
        constexpr void    operator -= (const Vector3& v)                { x -= v.x; y -= v.y; z -= v.z; }

        constexpr Vector3 operator +  (Float v) const { return { x +  v, y +  v, z +  v }; }
        constexpr void    operator += (Float v)                { x += v; y += v; z += v; }

        constexpr Vector3 operator -  (Float v) const { return { x -  v, y -  v, z -  v }; }
        constexpr void    operator -= (Float v)                { x -= v; y -= v; z -= v; }

        constexpr Vector3 operator *  (Float v) const { return { x *  v, y *  v, z *  v }; }
        constexpr void    operator *= (Float v)                { x *= v; y *= v; z *= v; }

        constexpr Vector3 operator /  (Float v) const { return { x /  v, y /  v, z /  v }; }
        constexpr void    operator /= (Float v)                { x /= v; y /= v; z /= v; }

        constexpr Float distance_to(const Vector3& vec) const {
            const auto _x = x - vec.x;
            const auto _y = y - vec.y;
            const auto _z = z - vec.z;
            return gm::math::sqrt(_x * _x + _y * _y + _z * _z);
        }

        void orbit_shift(const Point&);

        Float get_axis(Axis axis) const;
        void set_axis(Axis axis, Float value);

        template<class T>
        void append_to_container(T& container) const {
            container.push_back(x);
            container.push_back(y);
            container.push_back(z);
        }

        std::string to_string() const;

        template <class T>
        static auto average_point(const T& points) {
            Vector3 result;
            for (const auto& point : points) {
                result += point;
            }
            return result / static_cast<Float>(points.size());
        }

        template <class ArrayT>
        static Vector3 middle_point(const ArrayT& points) {
            static const auto max_value = std::numeric_limits<Float>::max();
            static const auto min_value = std::numeric_limits<Float>::min();

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

    };

}
