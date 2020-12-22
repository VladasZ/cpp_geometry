//
//  GmMapping.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 15/12/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "JsonMapper.hpp"


namespace gm {

    MAKE_CLASS_INFO(Point,
        MAKE_PROPERTY(Point, x),
        MAKE_PROPERTY(Point, y)
    );

    MAKE_CLASS_INFO(Size,
        MAKE_PROPERTY(Size, width),
        MAKE_PROPERTY(Size, height)
    );

    MAKE_CLASS_INFO(Rect,
        MAKE_PROPERTY(Rect, origin),
        MAKE_PROPERTY(Rect, size)
    );

    MAKE_MAPPER(mapper,
        InfoOfPoint,
        InfoOfSize,
        InfoOfRect);

    inline constexpr auto json_mapper = mapping::JSONMapper<mapper>();

}
