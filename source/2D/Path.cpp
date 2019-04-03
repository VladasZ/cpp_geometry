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

size_t Path::size() const {
    return _points.size();
}

const Path::Points Path::points() const {
    return _points;
}

const float* Path::data() const {
    return reinterpret_cast<const float*>(_points.data());
}

const std::vector<float> Path::floats_vector() const {
    return { data(), data() + _points.size() * sizeof(Point) / sizeof(float) };
}

Path* Path::circle_with(const Point &center, float radius, int precision) {
    auto path = new Path();
    float angle_step = math::tau<float> / precision;
    for (int i = 0; i < precision; i++)
        path->add_point(Point::on_circle(radius, angle_step * i, center));
    return path;
}

std::string Path::to_string() const {
    std::string result;
    for (const auto& point : _points)
        result += std::string() + point.to_string() + "\n";
    result.pop_back();
    return result;
}
