//
//  Point.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Point.hpp"

using namespace gm;


const Point Point::zero;

Point::Point(Direction direction, float length) {
    switch (direction) {
        case Direction::Left:  x = -length; y =  0;      break;
        case Direction::Right: x =  length; y =  0;      break;
        case Direction::Up:    x =  0;      y = -length; break;
        case Direction::Down:  x =  0;      y =  length; break;
    }
}

void Point::trim(float max_lenght) {
    if (length() < max_lenght) {
        return;
    }
    set_length(max_lenght);
}

Point Point::trimmed(float max_length) const {
    Point result = *this;
    result.trim(max_length);
    return result;
}

std::string Point::to_string() const {
    return std::string() + "x: " + std::to_string(x) + " y: " + std::to_string(y);
}
