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

    Vector3 begin;
    Vector3 end;

    constexpr LineSegment(const Vector3& begin, const Vector3& end) : begin(begin), end(end) { }

    constexpr float length() const {
        return begin.distance_to(end);
    }

    constexpr Vector3 direction_vector() const {
        return end - begin;
    }

    virtual std::string to_string() const;
};

}
