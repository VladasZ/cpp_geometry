//
//  Size.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

namespace gm {

class Size {

public:

    float width  = 0;
    float height = 0;

    Size() = default;
	template <class T> Size(T size);
	template <class T> Size(T width, T height);

    Point center() const;
    float ratio()  const;

    bool is_negative() const;

    Size  operator /  (float value) const;
    Size  operator *  (float value) const;
    Size& operator *= (float value);

    bool operator == (const Size& size) const;

    const char* to_string() const;
};

template <class T>
Size::Size(T size) {
	this->width = static_cast<float>(size);
	this->height = static_cast<float>(size);
}

template <class T>
Size::Size(T width, T height) {
	this->width = static_cast<float>(width);
	this->height = static_cast<float>(height);
}

}
