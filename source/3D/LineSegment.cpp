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

Vector3 LineSegment::direction() const {
    return end - begin;
}

