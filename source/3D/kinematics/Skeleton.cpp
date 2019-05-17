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

    if (root_bone == nullptr) {
        root_bone = bone;
        end_bode = bone;
        return;
    }

    end_bode->add_child(bone);
    end_bode = bone;

}
