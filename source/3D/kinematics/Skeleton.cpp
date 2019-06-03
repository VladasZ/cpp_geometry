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

    if (bones.size())
        bones.back()->add_child(bone);

    bones.push_back(bone);
}

float Skeleton::length() const {
    float result = 0;
    for (auto bone : bones)
        result += bone->lenght();
    return result;
}

void Skeleton::reach_to(const Vector3& target) {

    if (target.length() > length()) {



        return;
    }

    //_backwards_reach(target);

}

#include <iostream>
using namespace std;

void Skeleton::_backwards_reach(const Vector3& target) {

    cout << target.to_string() << endl;
}
