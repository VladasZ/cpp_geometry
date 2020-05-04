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

        Float width  = 0;
        Float height = 0;

        Size() = default;

        template <class T>
        constexpr Size(T width, T height) : width(static_cast<Float>(width)), height(static_cast<Float>(height)) { }

        Point center() const;
        Float ratio()  const;

        bool is_negative() const;

        Size  operator /  (Float value) const;
        Size  operator *  (Float value) const;
        Size& operator *= (Float value);

        std::string to_string() const;
    };

}
