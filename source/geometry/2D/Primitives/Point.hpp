//
//  Point.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <cmath>
#include <string>


namespace gm {

    enum class Direction {
        Right,
        Left,
        Up,
        Down
    };

    class Point {

    public:

        float x = 0;
        float y = 0;

        Point() = default;

        template <class T, class U>
        constexpr Point(T x, U y) : x(static_cast<float>(x)), y(static_cast<float>(y)) { }

        Point(Direction direction, float length = 1);

        float angle()   const { return std::atan2(y, x); }
        bool  is_zero() const { return x == 0 && y == 0; }
        float length()  const { return std::sqrt(x * x + y * y); }

        void invert()   { x = -x; y = -y; }
        void invert_x() { x = -x; }
        void invert_y() { y = -y; }

        Point with_length(float l) const {
            const auto ratio = l / length();
            return { x * ratio, y * ratio };
        }

        void set_length(float l) {
            const auto ratio = l / length();
            x *= ratio;
            y *= ratio;
        }

        void trim(float max_lenght);
        Point trimmed(float max_length) const;

        Direction directionX() const { return x > 0 ? Direction::Right : Direction::Left; }

        float distanceTo(const Point& p) const {
            const auto _x = x - p.x;
            const auto _y = y - p.y;
            return std::sqrt(_x * _x + _y * _y);
        }

        Point operator + (const Point& point) const { return { x + point.x, y + point.y }; }
        Point operator - (const Point& point) const { return { x - point.x, y - point.y }; }

        Point operator * (float value) const { return { x * value, y * value }; }
        Point operator / (float value) const { return { x / value, y / value }; }

        void operator += (const Point& point) { x += point.x; y += point.y; }
        void operator -= (const Point& point) { x -= point.x; y -= point.y; }
    
        void operator *= (float value) { x *= value; y *= value; }
        void operator /= (float value) { x /= value; y /= value; }

        std::string to_string() const;

    public:

        static const Point zero;
        static Point on_circle(float radius, float angle, const Point& center) {
            return { (radius / 2) * std::cos(angle) + center.x, (radius / 2) * std::sin(angle) + center.y };
        }

    };

}
