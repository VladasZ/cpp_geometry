//
//  Box.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Box.hpp"
#include "GmMath.hpp"
#include "StringUtils.hpp"

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
        min_bound(get_min(length, width, height)),
        max_bound(get_max(length, width, height))
{ }

Box::Box(const Vector3& min, const Vector3& max)
    :
        length(gm::math::distance(min.x, max.x)),
        width(gm::math::distance(min.y, max.y)),
        height(gm::math::distance(min.z, max.z)),
        min_bound(min),
        max_bound(max)
{ }

bool Box::intersects_ray(const Ray& ray) const {

    using namespace std;

    float t1 = (min_bound.x - ray.begin.x) * ray.dirfrac().x;
    float t2 = (max_bound.x - ray.begin.x) * ray.dirfrac().x;
    float t3 = (min_bound.y - ray.begin.y) * ray.dirfrac().y;
    float t4 = (max_bound.y - ray.begin.y) * ray.dirfrac().y;
    float t5 = (min_bound.z - ray.begin.z) * ray.dirfrac().z;
    float t6 = (max_bound.z - ray.begin.z) * ray.dirfrac().z;

    float tmax = min(min(max(t1, t2), max(t3, t4)), max(t5, t6));

    if (tmax < 0) return false;

    float tmin = max(max(min(t1, t2), min(t3, t4)), min(t5, t6));

    return tmin <= tmax;
}

Vector3 Box::dimensions() const {
    return { length, width, height };
}

std::string Box::to_string() const {
    return std::string() +
            "l: " + cu::String::from_float(length) +
            " w: " + cu::String::from_float(width)  +
            " h: " + cu::String::from_float(height);
}
