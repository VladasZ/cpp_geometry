//
//  BaseBone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 6/3/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Vector3.hpp"
#include "LineSegment.hpp"

namespace gm {

    class BaseBone {

    protected:

        const float _length;

        BaseBone* _parent = nullptr;
        std::vector<BaseBone*> _childred;

        BaseBone(float length) : _length(length) { }
        virtual ~BaseBone() { }

    public:

        float lenght() const { return _length; }

        BaseBone* parent()      const { return _parent;           }
        BaseBone* first_child() const { return _childred.front(); }

        bool is_root() const { return _parent == nullptr; }
        bool is_end()  const { return _childred.empty();  }

        virtual Vector3 begin() const = 0;
        virtual Vector3 end()   const = 0;

        virtual void set_begin(const Vector3&) = 0;
        virtual void set_end(const Vector3&)   = 0;

        void set_z(float z) {
            set_begin(begin().with_z(z));
            set_end(end().with_z(z));
        }

        LineSegment line_segment() const { return { begin(), end() }; }

        void add_child(BaseBone* bone) {
            bone->_parent = this;
            _childred.push_back(bone);
        }

        void iterate(std::function<void(BaseBone*)> action) {
            action(this);
            for (auto child : _childred) {
                child->iterate(action);
            }
        }

        std::string to_string() const {
            return begin().to_string() + " " + end().to_string();
        }

    };

}
