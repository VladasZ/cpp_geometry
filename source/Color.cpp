//
//  Color.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <cstdlib>
#include <vector>

#include "Color.hpp"

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) { }

Color Color::with_alpha(float alpha) const {
	return { r, g, b, alpha };
}

bool Color::is_transparent() const {
    return this->a <= 0.02f;
}

const float* Color::data() const {
    return &r;
}

Color Color::random() {
    static const std::vector<Color> all = {
        black,
        white,
        red,
        green,
        blue,
        light_blue,
        yellow,
        orange,
        purple,
        turquoise,
        gray,
        light_gray,
        clear
    };

    return all[static_cast<unsigned long>(std::rand()) % all.size()];
}

const Color Color::black      = { 0   , 0   , 0    };
const Color Color::white      = { 1   , 1   , 1    };
const Color Color::red        = { 1   , 0   , 0    };
const Color Color::green      = { 0   , 1   , 0    };
const Color Color::blue       = { 0   , 0   , 0.8f };
const Color Color::light_blue = { 0   , 0   , 1    };
const Color Color::yellow     = { 1   , 1   , 0    };
const Color Color::orange     = { 1   , 0.5f, 0    };
const Color Color::purple     = { 1   , 0   , 1    };
const Color Color::turquoise  = { 0   , 1   , 1    };
const Color Color::gray       = { 0.5f, 0.5f, 0.5f };
const Color Color::light_gray = { 0.8f, 0.8f, 0.8f };
const Color Color::clear      = { 0   , 0   , 0, 0 };
