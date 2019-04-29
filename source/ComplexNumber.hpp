//
//  ComplexNumber.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/10/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <math.h>
#include <string>
#include <array>
#include <type_traits>

namespace gm {

class ComplexNumber {

public:

    float real = 0;
    float imag = 0;

    ComplexNumber() = default;
    ComplexNumber(float real, float imag) : real(real), imag(imag) { }

    float modulus() const {
        return sqrtf(real * real + imag * imag);
    }

    float argument() const {
        return atanf(imag / real);
    }

    std::string to_string() const {
        return std::to_string(real) + " : " + std::to_string(imag);
    }

    template<class Array,
             size_t array_size   = std::tuple_size<Array>::value,
             size_t complex_size = array_size/ 2,
             class ComplexArray  = std::array<gm::ComplexNumber, complex_size>>
    static auto cast_array(const Array& array) {
        static_assert(std::is_same_v<typename Array::value_type, float>);
        static_assert(array_size % 2 == 0);
        return reinterpret_cast<const ComplexArray&>(array);
    }
};

}
