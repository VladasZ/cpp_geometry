//
//  LineSegment.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "LineSegment.hpp"

using namespace gm;

LineSegment::LineSegment(const Vector3& begin, const Vector3& end) : begin(begin), end(end) {

}

float LineSegment::length() const {
    return begin.distance_to(end);
}

Vector3 LineSegment::direction_vector() const {
    return end - begin;
}

std::string LineSegment::to_string() const {
    return std::string() + "\n" + begin.to_string() + "\n" + end.to_string();
}
