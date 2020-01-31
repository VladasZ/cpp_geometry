//
//  DirectionBone.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/17/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "BaseBone.hpp"

namespace gm {

class DirectionBone : public BaseBone<DirectionBone> {

    Vector3 _direction;

public:

    DirectionBone(float lenght, Vector3 direction = { 1, 0, 0 });

    const Vector3& direction() const;
    void set_direction(const Vector3&);

    Vector3 begin() const override;
    Vector3 end() const override;

};

}
