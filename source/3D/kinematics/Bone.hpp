//
//  Bone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"

namespace gm {

class Bone {

    const float _length;
    Vector3 _direction;

    Bone* _parent = nullptr;
    Bone* _child = nullptr;

public:

    Bone(float lenght, Vector3 direction = { 1, 0, 0 });

    float length() const;

    const Vector3& direction() const;
    void set_direction(const Vector3&);

    Bone* parent() const;
    Bone* child() const;

    Vector3 begin() const;
    Vector3 end() const;
    Vector3 center() const;

    bool is_root() const;
    bool is_end() const;

    void add_child(Bone*);

};

}
