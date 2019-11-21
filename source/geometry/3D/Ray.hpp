//
//  Ray.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "LineSegment.hpp"

namespace gm {

class Ray : public LineSegment {

public:

    Ray(const Vector3&, const Vector3&);

    Vector3 invdir;
    int sign[3];

};

}
