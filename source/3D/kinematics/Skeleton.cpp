//
//  Skeleton.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Skeleton.hpp"

using namespace gm;

void Skeleton::add_bone(Bone* bone) {

    _all_bones.push_back(bone);

    if (root_bone == nullptr) {
        root_bone = bone;
        end_bode = bone;
        return;
    }

    end_bode->add_child(bone);
    end_bode = bone;
}

const std::vector<Bone*>& Skeleton::all_bones() const {
    return _all_bones;
}

float Skeleton::length() const {
    float result = 0;
    for (auto bone : all_bones())
        result += bone->length();
    return result;
}

void Skeleton::reach_to(const Vector3& target) {

    if (target.length() > length()) {
        for (auto bone : all_bones())
            bone->set_direction(target);
        return;
    }

    std::vector<BoneData> data;

    for (auto bone : all_bones())
        data.emplace_back(bone->begin(), bone->end(), bone->length());

    _backwards_reach(data, target);

}

void Skeleton::_backwards_reach(std::vector<BoneData>& data, const Vector3& target) {


}
