//
//  Point.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

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

        float angle()   const;
        bool  is_zero() const;
        float length()  const;

        void invert();
        void invert_x();
        void invert_y();

        Point with_length(float length) const;

        void set_length(float length);
        void add_length(float value);

        void trim(float max_lenght);
        Point trimmed(float max_length) const;

        Direction directionX() const;

        float distanceTo(const Point&) const;

        const float* data() const;

        Point operator +  (const Point& point) const;
        void  operator += (const Point& point);

        Point operator -  (const Point& point) const;
        void  operator -= (const Point& point);

        Point operator *  (float value) const;
        void  operator *= (float value);

        Point operator /  (float value) const;
        void  operator /= (float value);

        std::string to_string() const;

    public:

        static const Point zero;
        static Point on_circle(float radius, float angle, const Point& center);

    };

}
