//
//  Rect.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <array>

#include "Size.hpp"
#include "Point.hpp"


namespace gm {

    enum class Edge {
        Top         = 0b00000001,
        Bottom      = 0b00000010,
        Left        = 0b00000100,
        Right       = 0b00001000,
        CenterV     = 0b00010000,
        CenterH     = 0b00100000,
        Center      = CenterV | CenterH,
        TopLeft     = Top     | Left,
        TopRight    = Top     | Right,
        BottomLeft  = Bottom  | Left,
        BottomRight = Bottom  | Right,
        None        = 0
    };

    class Rect {

    public:

        Point origin;
        Size  size;

        Rect() = default;
        Rect(const Size&);
        Rect(Float size);
        Rect(Float width, Float height);

        constexpr Rect(Float x, Float y, Float width, Float height) : origin({ x, y }), size({ width, height }) { }

        void set_edge(Edge, Point);

        Float min_x() const;
        Float min_y() const;
        Float max_x() const;
        Float max_y() const;

        Point center() const;
        void set_center(const Point&);

        bool contains(const Point&) const;
        bool contains_with_edge(const Point&, Float) const;

        Size fit_size(const Size&) const;

        Rect with_zero_origin() const;

        std::array<Rect, 4> edges() const;

        std::string to_string() const;
    };

}
