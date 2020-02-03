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

    Vector3 _direction;
    Vector3 _dirfrac;

public:

    Ray(const Vector3& origin, const Vector3& end);

    Vector3 direction() const { return _direction; }
    Vector3 dirfrac()   const { return _dirfrac;   }

};

}
