//
//  Vector4.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <math.h>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/quaternion.hpp"

#include "Vector4.hpp"

using namespace gm;

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {

}

void Vector4::normalize() {
    reinterpret_cast<Vector3*>(this)->normalize();
}

const Vector3& Vector4::vector3() const {
    return reinterpret_cast<const Vector3&>(*this);
}

Vector4& Vector4::operator /= (float value) {
    x /= value;
    y /= value;
    z /= value;
    w /= value;
    return *this;
}

const char* Vector4::to_string() const {
    static std::string result;
    result = std::string() + "[ "
            + std::to_string(x) + ", "
            + std::to_string(y) + ", "
            + std::to_string(z) + ", "
            + std::to_string(w) +
            " ]";
    return result.c_str();
}

Vector4 Vector4::look_at_quaternion(const Vector3& eye, const Vector3& center, const Vector3& up) {
    auto mat = glm::lookAt({   eye.x,    eye.y,    eye.z },
                           {center.x, center.y, center.z },
                 glm::vec3 {    up.x,     up.y,     up.z });

    auto quat = glm::toQuat(mat);

    return { quat.x, quat.y, quat.z, quat.w };
}
