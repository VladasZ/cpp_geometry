//
//  Box.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Ray.hpp"

namespace gm {

class Box {

public:

    const float length;
    const float width;
    const float height;

    const Vector3 min_bound;
    const Vector3 max_bound;

    Box(float size = 1);
    Box(float, float, float);
    Box(const Vector3& min, const Vector3& max);

    bool intersects_ray(const Ray&) const;

    std::string to_string() const;

};

}
