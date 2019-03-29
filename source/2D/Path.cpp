//
//  Path.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//


#include "Path.hpp"
#include "Math.hpp"

using namespace gm;


Path::Path(Points&& points) : _points(points) {

}

Path::Path(const Rect& rect) {
    _points = {
          rect.origin,
        { rect.origin.x,                    rect.origin.y + rect.size.width },
        { rect.origin.x + rect.size.height, rect.origin.y + rect.size.width },
        { rect.origin.x + rect.size.height, rect.origin.y                   }
    };
}

void Path::add_point(float x, float y) {
    _points.emplace_back(x, y);
}

void Path::add_point(const Point& point) {
    _points.push_back(point);
}

const Path::Points Path::points() const {
    return _points;
}

const void* Path::data() const {
    return _points.data();
}

Path* Path::circle_with(const Point &center, float radius, int precision) {
    auto path = new Path();
    float angle_step = math::tau<float> / precision;
    for (int i = 0; i < precision; i++)
        path->add_point(Point::on_circle(radius, angle_step * i, center));
    return path;
}
