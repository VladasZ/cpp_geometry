//
//  BoneData.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "BoneData.hpp"

using namespace gm;


BoneData::BoneData(const Vector3& begin, const Vector3& end, float length) : begin(begin), end(end), length(length) {

}

void BoneData::reach_begin(const Vector3& target) {
    begin = (target - end).with_length(length) + end;
}

void BoneData::reach_end(const Vector3& target) {
    end = (target - begin).with_length(length) + begin;
}

LineSegment BoneData::line_segment() const {
    return { begin, end };
}
