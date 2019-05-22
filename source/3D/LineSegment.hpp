//
//  LineSegment.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"

namespace gm {

class LineSegment {

public:

    Vector3 orig;
    Vector3 dir;

    LineSegment(const Vector3&, const Vector3&);

    float length() const;

    Vector3 direction_vector() const;

    std::string to_string() const;
};

}
