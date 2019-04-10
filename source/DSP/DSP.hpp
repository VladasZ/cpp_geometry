//
//  ComplexNumber.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/10/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <string>

namespace gm {

class ComplexNumber {

public:

    float real = 0;
    float imag = 0;

    ComplexNumber() = default;
    ComplexNumber(float real, float imag);

    float vector() const;

    std::string to_string() const;
};

}
