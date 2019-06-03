//
//  Skeleton.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Bone.hpp"

namespace gm {

class Skeleton {

public:

    std::vector<Bone*> bones;

    void add_bone(Bone*);

    float length() const;

    void reach_to(const Vector3&);

    void _backwards_reach(const Vector3&);
};

}
