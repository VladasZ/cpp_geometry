//
//  Color.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <vector>

#include "Color.hpp"

using namespace gm;


void Color::set_alpha(float alpha) {
    this->a = alpha;
}

const float* Color::data() const {
    return &r;
}

std::string Color::to_string() const {
    return std::string() +
             "r: " + std::to_string(r) +
            " g: " + std::to_string(g) +
            " b: " + std::to_string(b) +
            " a: " + std::to_string(a);
}

static const std::vector<Color> all = {
    Color::black,
    Color::white,
    Color::red,
    Color::green,
    Color::blue,
    Color::light_blue,
    Color::yellow,
    Color::orange,
    Color::purple,
    Color::turquoise,
    Color::gray,
    Color::light_gray
};

const Color& Color::random() {
    return all[static_cast<unsigned long>(std::rand()) % all.size()];
}

const Color Color::black      = { 0   , 0   , 0    };
const Color Color::white      = { 1   , 1   , 1    };
const Color Color::red        = { 1   , 0   , 0    };
const Color Color::green      = { 0   , 1   , 0    };
const Color Color::blue       = { 0   , 0   , 0.8f };
const Color Color::light_blue = { 0   , 0.7f, 1    };
const Color Color::yellow     = { 1   , 1   , 0    };
const Color Color::orange     = { 1   , 0.6f, 0    };
const Color Color::purple     = { 1   , 0   , 1    };
const Color Color::turquoise  = { 0   , 1   , 1    };
const Color Color::gray       = { 0.5f, 0.5f, 0.5f };
const Color Color::brown      = { 0.7f, 0.4f, 0.2f };
const Color Color::light_gray = { 0.8f, 0.8f, 0.8f };
const Color Color::clear      = { 0   , 0   , 0, 0 };
