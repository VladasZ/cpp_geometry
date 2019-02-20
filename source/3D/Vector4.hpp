//
//  Vector4.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Vector3.hpp"

class Vector4 {
    
public:

    using Float = float;
    
    Float x = 0;
    Float y = 0;
    Float z = 0;
    Float w = 0;

    Vector4() = default;
    Vector4(Float x, Float y, Float z, Float w);

    const Vector3& vector3() const;

    void normalize();

    template<class T>
    void append_to_container(T& container) {
        container.push_back(x);
        container.push_back(y);
        container.push_back(z);
        container.push_back(w);
    }

    const char* to_string() const;

    static Vector4 look_at_quaternion(const Vector3& eye, const Vector3& center, const Vector3& up);
};

