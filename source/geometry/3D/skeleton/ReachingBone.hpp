//
//  ReachingBone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/31/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "BaseBone.hpp"

namespace gm {

    class ReachingBone : public BaseBone<ReachingBone> {

        Vector3 _begin;
        Vector3 _end;

    public:

        ReachingBone(const Vector3& begin, const Vector3& end);

        void set_z(float z) {
            set_begin(begin().with_z(z));
            set_end(end().with_z(z));
        }

        Vector3 begin() const override;
        Vector3 end() const override;

        void set_begin(const Vector3&);
        void set_end(const Vector3&);

        void reach_begin(const Vector3&);
        void reach_end(const Vector3&);

    };

}
