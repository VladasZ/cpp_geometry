//
//  Skeleton.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Bone.hpp"
#include "BoneData.hpp"

namespace gm {

class Skeleton {

    std::vector<Bone*> _all_bones;

public:

    Vector3 origin;

    Bone* root_bone = nullptr;
    Bone* end_bode = nullptr;

    void add_bone(Bone*);

    const std::vector<Bone*>& all_bones() const;

    float length() const;

    void reach_to(const Vector3&);

private:

    void _backwards_reach(std::vector<BoneData>&, const Vector3&);
};

}
