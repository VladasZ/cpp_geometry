//
//  Size.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <cmath>

#include "Size.hpp"

using namespace gm;


Point Size::center() const {
    return { width / 2, height / 2 };
}

float Size::ratio() const {
    return width / height;
}

bool Size::is_negative() const {
    return width < 0 || height < 0;
}

float Size::diagonal() const {
    return std::sqrt(width * width + height * height);
}

Size Size::operator / (float value) const {
    return { width / value, height / value };
}

Size Size::operator * (float value) const {
    return { width * value, height * value };
}

Size& Size::operator *= (float value) {
    width  *= value;
    height *= value;
    return *this;
}

std::string Size::to_string() const {
    return std::string() + "width: " + std::to_string(width) + " height: " + std::to_string(height);
}
