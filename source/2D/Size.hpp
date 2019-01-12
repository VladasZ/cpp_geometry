//
//  Size.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

class Size {

public:

    float width  = 0;
    float height = 0;

    Size() = default;
    Size(float width, float height);

    Point center() const;
    float ratio()  const;

    bool is_negative() const;

    Size operator / (float value) const;
    Size operator * (float value) const;

    bool operator == (const Size& size) const;

    const char* to_string() const;
};
