//
//  ReachingBone.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ReachingBone.hpp"

using namespace gm;


ReachingBone::ReachingBone(const Vector3& begin, const Vector3& end) : BaseBone(begin.distance_to(end)), _begin(begin), _end(end) {

}

Vector3 ReachingBone::begin() const {
    return _begin;
}

Vector3 ReachingBone::end() const {
    return _end;
}

void ReachingBone::set_begin(const Vector3& begin) {
    _begin = begin;
}

void ReachingBone::set_end(const Vector3& end) {
    _end = end;
}

void ReachingBone::reach_begin(const Vector3& target) {
    _begin = (target - _end).with_length(_length) + _end;
}

void ReachingBone::reach_end(const Vector3& target) {
    _end = (target - _begin).with_length(_length) + _begin;
}
