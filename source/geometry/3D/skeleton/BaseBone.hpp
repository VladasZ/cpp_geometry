//
//  BaseBone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 6/3/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>
#include <functional>

#include "Log.hpp"
#include "Vector3.hpp"
#include "Matrix4.hpp"
#include "LineSegment.hpp"

namespace gm {

    template <class BoneT>
    class BaseBone {

    protected:

        const float _length;

    public:

        Vector4 rotation_quat = { 1, 0, 0, 0 };

    protected:

        BoneT* _parent = nullptr;
        std::vector<BoneT*> _childred;

        BaseBone(float length) : _length(length) { }

        virtual ~BaseBone() {
//            for (auto child : _childred) {
//                delete child;
//            }
        }

    public:

        float lenght() const { return _length; }

        BoneT* parent()      const { return _parent;           }
        BoneT* first_child() const { return _childred.front(); }

        bool is_root() const { return _parent == nullptr; }
        bool is_end()  const { return _childred.empty();  }


        Vector4 absolute_rotation() const {
            if (is_root()) return rotation_quat;
            return _parent->absolute_rotation() * rotation_quat;
        }

        virtual Vector3 begin() const {
            if (is_root()) return { };
            return _parent->end();
        }

        virtual Vector3 end() const {
            return begin() + Matrix4::transform::quaternion_rotation(absolute_rotation()) * Vector3 { _length, 0, 0 };
        }

        LineSegment line_segment() const { return { begin(), end() }; }

        void add_child(BoneT* bone) {
            bone->_parent = (BoneT*)this;
            _childred.push_back(bone);
        }

        void iterate(std::function<void(BoneT*)> action) {
            action((BoneT*)this);
            iterate_childred(action);
        }

        void iterate_childred(std::function<void(BoneT*)> action) {
            for (auto child : _childred) {
                child->iterate(action);
            }
        }

        std::string to_string() const {
            return begin().to_string() + " " + end().to_string();
        }

    };

}
