//
//  Point.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <type_traits>

namespace gm {

enum Direction {
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
    Point(float x, float y);
    Point(Direction direction, float length = 1);

    template <class CompatibleType>
    Point(const CompatibleType& value) {
        if constexpr (std::is_fundamental_v<CompatibleType>) {
            x = value;
            y = value;
        }
        else {
            x = value.x;
            y = value.y;
        }
    }

    float angle()   const;
    bool  is_zero() const;
    float length()  const;

	void invert();
	void invert_x();
	void invert_y();

    Point with_length(float length) const;

    Direction directionX() const;

    Point operator +  (const Point& point) const;
    void  operator += (const Point& point);

    Point operator -  (const Point& point) const;
    void  operator -= (const Point& point);

    Point operator *  (float value) const;
    void  operator *= (float value);

    Point operator /  (float value) const;
    void  operator /= (float value);

    template<class T>
    void append_to_container(T& container) {
        container.push_back(x);
        container.push_back(y);
    }

    std::string to_string() const;

public:

    static Point on_circle(float radius, float angle, const Point& center);

};

}
