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

    Vector3 origin;

    Bone* root_bone = nullptr;
    Bone* end_bode = nullptr;

    void add_bone(Bone*);

    std::vector<Bone*> all_bones() const;

    float length() const;

    void reach_to(const Vector3&);
};

}
