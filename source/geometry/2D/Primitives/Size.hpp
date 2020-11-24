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

        template <class X, class Y>
        constexpr Size(X width, Y height) : width(static_cast<float>(width)), height(static_cast<float>(height)) { }

        Point center() const;
        float ratio()  const;

        bool is_negative() const;

        float diagonal() const;

        Size  operator /  (float value) const;
        Size  operator *  (float value) const;
        Size& operator *= (float value);

        std::string to_string() const;
    };

}
