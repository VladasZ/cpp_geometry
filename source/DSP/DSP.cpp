//
//  ComplexNumber.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/10/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <cmath>

#include "ComplexNumber.hpp"

using namespace gm;

ComplexNumber::ComplexNumber(float real, float imag) : real(real), imag(imag) {

}

float ComplexNumber::vector() const {
    return static_cast<float>(std::sqrt(real * real + imag * imag));
}

std::string ComplexNumber::to_string() const {
    return std::to_string(real) + " : " + std::to_string(imag);
}
