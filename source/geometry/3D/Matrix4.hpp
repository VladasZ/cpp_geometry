//
//  Matrix4.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <array>
#include <initializer_list>

#include "Vector4.hpp"


namespace gm {

class Matrix4 : public cu::ForceInitializable<Matrix4> {
    
public:
    
    static const size_t size = 16;
    
    Float data[4][4];
    
    Matrix4();
    Matrix4(Float value);
    Matrix4(const std::initializer_list<Float>&);

    template <class CompatibleClass>
    explicit Matrix4(const CompatibleClass& obj) {
        static_assert(sizeof(Matrix4) == sizeof(CompatibleClass), "Matrix4 invalid initializer");
        std::memcpy(&data[0][0], static_cast<const void*>(&obj), sizeof(Matrix4));
    }

    Matrix4 inversed() const;
    
    Matrix4  operator * (const Matrix4&) const;
    Matrix4& operator *=(const Matrix4&);

    Vector3  operator * (const Vector3&) const;
    Vector4  operator * (const Vector4&) const;

    Vector3 multiply_by_normal(const Vector3&) const;

    std::string to_string() const;

    struct transform {
        static Matrix4 scale(Float);
        static Matrix4 scale(const Vector3&);
        static Matrix4 translation(const Vector3&);
        static Matrix4 rotation_x(Float);
        static Matrix4 rotation_y(Float);
        static Matrix4 rotation_z(Float);
        static Matrix4 perspective(Float fovy, Float aspect, Float z_near, Float z_far);
        static Matrix4 look_at(const Vector3& eye, const Vector3& center, const Vector3& up);
        static Matrix4 model_look_at(const Vector3& target);
        static Matrix4 quaternion_rotation(const Vector4& quat);
    };
};

}
