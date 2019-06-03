//
//  BaseBone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 6/3/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "LineSegment.hpp"

namespace gm {

template<class Bone>
class _BaseBone {

protected:

    const float _length;

    Bone* _parent = nullptr;
    Bone* _child = nullptr;

public:

    _BaseBone(float length) : _length(length) { }

    virtual ~_BaseBone() { }

    float lenght() const { return _length; }

    Bone* parent() const { return _parent; }
    Bone* child() const { return _child; }

    bool is_root() const { return _parent == nullptr; }
    bool is_end() const { return _child == nullptr; }

    virtual Vector3 begin() const = 0;
    virtual Vector3 end() const = 0;

    LineSegment line_segment() const { return  { begin(), end() }; }

    void add_child(Bone* bone) {
        bone->_parent = reinterpret_cast<Bone*>(this);
        _child = bone;
    }

};

}
