//
//  Bone.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Bone.hpp"

using namespace gm;

Bone::Bone(float lenght, Vector3 direction) : _length(lenght), _direction(direction) {

}

float Bone::length() const {
    return _length;
}

const Vector3& Bone::direction() const {
    return _direction;
}

void Bone::set_direction(const Vector3& direction) {
    _direction = direction.normalized();
}

Bone* Bone::parent() const {
    return _parent;
}

Bone* Bone::child() const {
    return _child;
}

Vector3 Bone::begin() const {
    return is_root() ? Vector3 { } : _parent->end();
}

Vector3 Bone::end() const {
    return begin() + _direction * _length;
}

Vector3 Bone::center() const {
    return (begin() + end()) / 2;
}

bool Bone::is_root() const {
    return _parent == nullptr;
}

bool Bone::is_end() const {
    return _child == nullptr;
}

void Bone::add_child(Bone* bone) {
    _child = bone;
    bone->_parent = this;
}
