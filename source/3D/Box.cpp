//
//  Box.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Box.hpp"

using namespace gm;

static Vector3 get_max(float length, float width, float height) {
    return { length, width, height };
}

static Vector3 get_min(float length, float width, float height) {
    return { -length, -width, -height };
}

Box::Box(float size) : Box(size, size, size) {

}

Box::Box(float length, float width, float height)
    :
      length(length),
      width(width),
      height(height),
      min(get_min(length, width, height)),
      max(get_max(length, width, height))
{ }

bool Box::intersects_ray(const Ray& r, float &t) const {

    Vector3 bounds[2] = { min, max };
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (bounds[r.sign[0]].x - r.orig.x) * r.invdir.x;
    tmax = (bounds[1-r.sign[0]].x - r.orig.x) * r.invdir.x;
    tymin = (bounds[r.sign[1]].y - r.orig.y) * r.invdir.y;
    tymax = (bounds[1-r.sign[1]].y - r.orig.y) * r.invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (bounds[r.sign[2]].z - r.orig.z) * r.invdir.z;
    tzmax = (bounds[1-r.sign[2]].z - r.orig.z) * r.invdir.z;

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    t = tmin;

    if (t < 0) {
        t = tmax;
        if (t < 0) return false;
    }

    return true;
}

