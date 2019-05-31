//
//  BoneData.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/31/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "LineSegment.hpp"

namespace gm {

class BoneData {

public:

    Vector3 begin;
    Vector3 end;
    const float length;

    BoneData(const Vector3& begin, const Vector3& end, float length);

    void reach_begin(const Vector3&);
    void reach_end(const Vector3&);

    LineSegment line_segment() const;
};

}
