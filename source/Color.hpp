//
//  Color.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>

namespace gm {

class Color {

public:

    float r = 0;
    float g = 0;
    float b = 0;
    float a = 0;

    Color() = default;
    Color(float r, float g, float b, float a = 1);

    void set_alpha(float);

    Color with_alpha(float) const;

    bool is_clear() const;
    bool is_opaque() const;

    const float* data() const;

    template<class T>
    void append_to_container(T& container, bool with_alpha = false) {
        container.push_back(r);
        container.push_back(g);
        container.push_back(b);
        if (with_alpha)
            container.push_back(a);
    }

    std::string to_string() const;

    static Color random();

    static const Color black;
    static const Color white;
    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color light_blue;
    static const Color yellow;
    static const Color orange;
    static const Color purple;
    static const Color turquoise;
    static const Color gray;
    static const Color brown;
    static const Color light_gray;
    static const Color clear;
};

}
