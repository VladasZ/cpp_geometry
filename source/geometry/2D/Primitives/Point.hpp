//
//  Point.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include "Geometry.hpp"


namespace gm {

    enum class Direction {
        Right,
        Left,
        Up,
        Down
    };

    class Point {

    public:

        Float x = 0;
        Float y = 0;

        Point() = default;

        template <class T, class U>
        constexpr Point(T x, U y) : x(static_cast<Float>(x)), y(static_cast<Float>(y)) { }

        Point(Direction direction, Float length = 1);

        Float angle()   const;
        bool  is_zero() const;
        Float length()  const;

        void invert();
        void invert_x();
        void invert_y();

        Point with_length(Float length) const;

        void set_length(Float length);
        void add_length(Float value);

        void trim(Float max_lenght);
        Point trimmed(Float max_length) const;

        Direction directionX() const;

        const Float* data() const;

        Point operator +  (const Point& point) const;
        void  operator += (const Point& point);

        Point operator -  (const Point& point) const;
        void  operator -= (const Point& point);

        Point operator *  (Float value) const;
        void  operator *= (Float value);

        Point operator /  (Float value) const;
        void  operator /= (Float value);

        std::string to_string() const;

    public:

        static Point on_circle(Float radius, Float angle, const Point& center);

    };

}
