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

    const size_t iterations = 20;

    std::vector<Bone*> bones;

    void add_bone(Bone*);

    float length() const;

    void reach_to(const Vector3&);

private:

    void _backward_reach(const Vector3&);
    void _forward_reach(const Vector3&);
};

}
