//
//  Vector4.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

class Vector4 {
    
public:

    using Float = float;
    
    Float x = 0;
    Float y = 0;
    Float z = 0;
    Float w = 0;

    Vector4() = default;
    Vector4(Float x, Float y, Float z, Float w);

    Float length() const;

    const char* to_string() const;
};

