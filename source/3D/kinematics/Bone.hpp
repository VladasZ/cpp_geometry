//
//  Bone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/31/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "BaseBone.hpp"

namespace gm {

class Bone : public _BaseBone<Bone> {

    Vector3 _begin;
    Vector3 _end;

public:

    Bone(const Vector3& begin, const Vector3& end);

    Vector3 begin() const override;
    Vector3 end() const override;

    void reach_begin(const Vector3&);
    void reach_end(const Vector3&);

};

}
