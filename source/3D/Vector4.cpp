//
//  Vector4.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <math.h>
#include <string>

#include "Vector4.hpp"

Vector4::Vector4(Float x, Float y, Float z, Float w) : x(x), y(y), z(z), w(w) {

}

const Vector3& Vector4::vector3() const {
    return reinterpret_cast<const Vector3&>(*this);
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
