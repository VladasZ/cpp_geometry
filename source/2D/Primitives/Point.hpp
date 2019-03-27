//
//  Point.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

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

    template <class CompatibleClass>
    Point(const CompatibleClass& obj) {
        x = obj.x;
        y = obj.y;
    }

    float angle()   const;
    bool  is_zero() const;
    float length()  const;

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

    const char* to_string() const;

public:

    static Point on_circle(float radius, float angle, const Point& center);

};

}
