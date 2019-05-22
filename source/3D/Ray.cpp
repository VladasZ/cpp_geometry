//
//  Ray.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Ray.hpp"

using namespace gm;

Ray::Ray(const Vector3& orig, const Vector3& dir) : LineSegment(orig, dir) {

    invdir.x = 1 / dir.x;
    invdir.y = 1 / dir.y;
    invdir.z = 1 / dir.z;

    sign[0] = (invdir.x < 0);
    sign[1] = (invdir.y < 0);
    sign[2] = (invdir.z < 0);
}
