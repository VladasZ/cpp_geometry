//
//  Path.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//


#include "GmMath.hpp"
#include "PointsPath.hpp"

using namespace gm;


PointsPath::PointsPath(const Rect& rect) {
    _points = {
          rect.origin,
        { rect.origin.x,                    rect.origin.y + rect.size.width },
        { rect.origin.x + rect.size.height, rect.origin.y + rect.size.width },
        { rect.origin.x + rect.size.height, rect.origin.y                   }
    };
}

void PointsPath::add_point(const Point& point) {
    _points.push_back(point);
}

size_t PointsPath::size() const {
    return _points.size();
}

const std::vector<Point>& PointsPath::points() {
    return _points;
}

void PointsPath::clear() {
    _points.clear();
}

PointsPath* PointsPath::circle_with(const Point &center, float radius, int precision) {
    auto path = new PointsPath();
    auto angle_step = math::tau<float> / precision;
    for (int i = 0; i < precision; i++) {
        path->add_point(Point::on_circle(radius, angle_step * i, center));
    }
    return path;
}

std::string PointsPath::to_string() const {
    std::string result;
    for (const auto& point : _points) {
        result += point.to_string() + "\n";
    }
    result.pop_back();
    return result;
}
