//
//  FabrikKinematics.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "FabrikKinematics.hpp"

using namespace gm;

void FabrikKinematics::add_bone(Bone* bone) {
    if (bones.size()) {
        bones.back()->add_child(bone);
    }
    bones.push_back(bone);
}

float FabrikKinematics::length() const {
    float result = 0;
    for (auto bone : bones) {
        result += bone->lenght();
    }
    return result;
}

void FabrikKinematics::reach_to(const Vector3& target) {

    if (target.distance_to(origin) > length()) {

        bones.front()->set_begin(origin);
        bones.front()->reach_end(target);

        for (auto bone : bones) {
            if (bone->is_root()) {
                continue;
            }
            bone->set_begin(bone->parent()->end());
            bone->reach_end(target);
        }

        return;
    }

    for (auto bone : bones) {
        bone->set_z(2000);
    }

    for (size_t i = 0; i < iterations; i++) {
        _backward_reach(target);
        _forward_reach(target);
    }
}

void FabrikKinematics::_backward_reach(const Vector3& target) {
    for (int i = static_cast<int>(bones.size()) - 1; i >= 0; i--) {
        auto bone = bones[static_cast<size_t>(i)];
        if (bone->is_end()) {
            bone->set_end(target);
            bone->reach_begin(bone->parent()->end());
            continue;
        }
        if (bone->is_root()) {
            bone->set_end(bone->first_child()->begin());
            bone->reach_begin(origin);
            continue;
        }
        bone->set_end(bone->first_child()->begin());
        bone->reach_begin(bone->parent()->end());
    }
}

void FabrikKinematics::_forward_reach(const Vector3& target) {
    for (auto bone : bones) {
        if (bone->is_root()) {
            bone->set_begin(origin);
            bone->reach_end(bone->first_child()->begin());
            continue;
        }
        if (bone->is_end()) {
            bone->set_begin(bone->parent()->end());
            bone->reach_end(target);
            continue;
        }
        bone->set_begin(bone->parent()->end());
        bone->reach_end(bone->first_child()->begin());
    }
}

