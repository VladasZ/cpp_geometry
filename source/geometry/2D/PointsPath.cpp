//
//  Path.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//


#include "PointsPath.hpp"
#include "GmMath.hpp"

using namespace gm;


PointsPath::PointsPath(Points&& points) : _points(points) {

}

PointsPath::PointsPath(const Rect& rect) {
    _points = {
          rect.origin,
        { rect.origin.x,                    rect.origin.y + rect.size.width },
        { rect.origin.x + rect.size.height, rect.origin.y + rect.size.width },
        { rect.origin.x + rect.size.height, rect.origin.y                   }
    };
}

void PointsPath::add_point(float x, float y) {
    _points.emplace_back(x, y);
}

void PointsPath::add_point(const Point& point) {
    _points.push_back(point);
}

size_t PointsPath::size() const {
    return _points.size();
}

PointsPath::Points& PointsPath::points() {
    return _points;
}

const float* PointsPath::data() const {
    return reinterpret_cast<const float*>(_points.data());
}

const std::vector<float> PointsPath::floats_vector() const {
    return { data(), data() + _points.size() * sizeof(Point) / sizeof(float) };
}

void PointsPath::clear() {
    _points.clear();
}

PointsPath* PointsPath::circle_with(const Point &center, float radius, int precision) {
    auto path = new PointsPath();
    float angle_step = math::tau<float> / precision;
    for (int i = 0; i < precision; i++)
        path->add_point(Point::on_circle(radius, angle_step * i, center));
    return path;
}

std::string PointsPath::to_string() const {
    std::string result;
    for (const auto& point : _points)
        result += std::string() + point.to_string() + "\n";
    result.pop_back();
    return result;
}
