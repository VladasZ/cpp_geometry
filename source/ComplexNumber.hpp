//
//  ComplexNumber.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/10/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <cmath>
#include <string>

namespace gm {

class ComplexNumber {

public:

    float real = 0;
    float imag = 0;

    ComplexNumber() = default;
    ComplexNumber(float real, float imag) : real(real), imag(imag) { }

    float vector() const {
        return static_cast<float>(std::sqrt(real * real + imag * imag));
    }

    std::string to_string() const {
        return std::to_string(real) + " : " + std::to_string(imag);
    }

    template<class Array, class ComplexArray = std::array<gm::ComplexNumber, std::tuple_size<Array>::value / 2>>
    static const auto& cast_array(const Array& array) {
        return reinterpret_cast<const ComplexArray&>(array);
    }
};

}
