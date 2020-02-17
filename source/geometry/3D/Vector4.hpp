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

namespace gm {

class Vector4 : public cu::ForceInitializable<Vector4> {
    
public:
    
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;

    Vector4() = default;
    Vector4(const Vector3& vec3, float w = 1);
    Vector4(float x, float y, float z, float w = 1);

    template <class CompatibleClass>
    explicit Vector4(const CompatibleClass& obj) {
        x = obj.x;
        y = obj.y;
        z = obj.z;
        w = obj.w;
    }

    template <class CompatibleClass>
    CompatibleClass to_compatible() const {
        CompatibleClass result { };
        result.x = x;
        result.y = y;
        result.z = z;
        result.w = w;
        return result;
    }

    const Vector3& vector3() const;

    float length() const;

    Vector4& normalize();

    template<class T>
    void append_to_container(T& container) {
        container.push_back(x);
        container.push_back(y);
        container.push_back(z);
        container.push_back(w);
    }

    Vector4& operator *= (float);
    Vector4& operator /= (float);

    Vector4 operator * (const Vector4&) const;

    std::string to_string() const;

    struct transform {
        static Vector4 quaternion_rotating_x(float);
        static Vector4 quaternion_rotating_y(float);
        static Vector4 quaternion_rotating_z(float);
    };

};

}
