//
//  Bone.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Bone.hpp"

using namespace gm;


Bone::Bone(const Vector3& begin, const Vector3& end) : _BaseBone<Bone>(begin.distance_to(end)), _begin(begin), _end(end) {

}

Vector3 Bone::begin() const {
    return _begin;
}

Vector3 Bone::end() const {
    return _end;
}

void Bone::set_begin(const Vector3& begin) {
    _begin = begin;
}

void Bone::set_end(const Vector3& end) {
    _end = end;
}

void Bone::reach_begin(const Vector3& target) {
    _begin = (target - _end).with_length(_length) + _end;
}

void Bone::reach_end(const Vector3& target) {
    _end = (target - _begin).with_length(_length) + _begin;
}
