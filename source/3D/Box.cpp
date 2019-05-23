//
//  Box.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Box.hpp"
#include "GmMath.hpp"

using namespace gm;

static Vector3 get_max(float length, float width, float height) {
    return { length / 2, width / 2, height / 2 };
}

static Vector3 get_min(float length, float width, float height) {
    return { -length / 2, -width / 2, -height / 2 };
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

Box::Box(const Vector3& min, const Vector3& max)
    :
      length(gm::math::distance(min.x, max.x)),
      width(gm::math::distance(min.y, max.y)),
      height(gm::math::distance(min.z, max.z)),
      min(min),
      max(max)
{ }

bool Box::intersects_ray(const Ray& ray) const {

    const Vector3 bounds[2] = { min, max };

    auto tmin  = (bounds[    ray.sign[0]].x - ray.orig.x) * ray.invdir.x;
    auto tmax  = (bounds[1 - ray.sign[0]].x - ray.orig.x) * ray.invdir.x;
    auto tymin = (bounds[    ray.sign[1]].y - ray.orig.y) * ray.invdir.y;
    auto tymax = (bounds[1 - ray.sign[1]].y - ray.orig.y) * ray.invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    auto tzmin = (bounds[    ray.sign[2]].z - ray.orig.z) * ray.invdir.z;
    auto tzmax = (bounds[1 - ray.sign[2]].z - ray.orig.z) * ray.invdir.z;

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    return !(tmin < 0 && tmax < 0);
}

std::string Box::to_string() const {
    return std::string() +
            "length: " + std::to_string(length) +
            "width: "  + std::to_string(width)  +
            "height: " + std::to_string(height);
}

