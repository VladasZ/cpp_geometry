//
//  FabrikKinematics.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "ReachingBone.hpp"

namespace gm {

class FabrikKinematics {

public:

    Vector3 origin;

    const size_t iterations = 20;

    std::vector<ReachingBone*> bones;

    void add_bone(ReachingBone*);

    float length() const;

    void reach_to(const Vector3&);

private:

    void _backward_reach(const Vector3&);
    void _forward_reach(const Vector3&);
};

}
