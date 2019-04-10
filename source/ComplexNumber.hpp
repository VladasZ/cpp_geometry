//
//  ComplexNumber.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/10/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <string>

//#include "arra

namespace gm {

class ComplexNumber {

public:

    float real = 0;
    float imag = 0;

    ComplexNumber() = default;
    ComplexNumber(float real, float imag);

    float vector() const;

    std::string to_string() const;

    template<class Array, class ComplexArray = std::array<gm::ComplexNumber, std::tuple_size<Array>::value / 2>>
    static const auto& cast_array(const Array& array) {
        return reinterpret_cast<const ComplexArray&>(array);
    }
};

}
