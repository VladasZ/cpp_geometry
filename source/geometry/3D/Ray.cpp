//
//  Ray.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Ray.hpp"

using namespace gm;

Ray::Ray(const Vector3& origin, const Vector3& end) : LineSegment(origin, end) {
    _direction = end - origin;

    _dirfrac.x = 1.0f / _direction.x;
    _dirfrac.y = 1.0f / _direction.y;
    _dirfrac.z = 1.0f / _direction.z;
}
