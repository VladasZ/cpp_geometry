//
//  LineSegment.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "LineSegment.hpp"

using namespace gm;

LineSegment::LineSegment(const Vector3& begin, const Vector3& end) : orig(begin), dir(end) {

}

float LineSegment::length() const {
    return orig.distance_to(dir);
}

Vector3 LineSegment::direction_vector() const {
    return dir - orig;
}

std::string LineSegment::to_string() const {
    return std::string() + "\n" + orig.to_string() + "\n" + dir.to_string();
}
