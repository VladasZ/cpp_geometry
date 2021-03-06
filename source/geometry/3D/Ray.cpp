//
//  Ray.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Ray.hpp"

using namespace gm;


std::pair<Vector3, Vector3> Ray::closest_points_with(const Ray& ray) const {

    const auto u = direction();
    const auto v = ray.direction();
    const auto w = begin - ray.begin;

    const auto a = u.dot(u);
    const auto b = u.dot(v);
    const auto c = v.dot(v);
    const auto d = u.dot(w);
    const auto e = v.dot(w);
    const auto D = a * c - b * b;
    float sc, tc;

    if (D < 1e-5f) {
        sc = 0.0;
        tc = (b > c ? d / b : e / c);
    } else {
        sc = (b * e - c * d) / D;
        tc = (a * e - b * d) / D;
    }

    const auto relative_a = u * sc;
    const auto relative_b = v * tc;

    const auto a_pos = relative_a + begin;
    const auto b_pos = relative_b + ray.begin;

    return { a_pos, b_pos };
}

bool Ray::intersects_plane(const LineSegment& plane) const {
    return distance_to_plane(plane) >= 0;
}

float Ray::distance_to_plane(const LineSegment& plane) const {
    return plane.end.dot(plane.begin - begin) / plane.end.dot(direction());
}

Vector3 Ray::plane_intersection(const LineSegment& plane) const {
    const auto distance = distance_to_plane(plane);
    if (distance < 0) return { };
    return _direction * distance;
}

std::string Ray::to_string() const {
    return LineSegment::to_string() + " Direction: " + _direction.to_string();
}
