//
//  DirectionBone.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "DirectionBone.hpp"

using namespace gm;

DirectionBone::DirectionBone(float lenght, Vector3 direction) : BaseBone(lenght), _direction(direction) {

}

const Vector3& DirectionBone::direction() const {
    return _direction;
}

void DirectionBone::set_direction(const Vector3& direction) {
    _direction = direction.normalized();
}

Vector3 DirectionBone::begin() const {
    return is_root() ? Vector3 { } : _parent->end();
}

Vector3 DirectionBone::end() const {
    return begin() + _direction.with_length(_length);
}
