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

    const Vector3 min;
    const Vector3 max;

    Box(float size = 1);
    Box(float, float, float);

    bool intersects_ray(const Ray&, float &t) const;

};

}
