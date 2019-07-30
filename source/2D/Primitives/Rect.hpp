//
//  Rect.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "Size.hpp"

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
    Rect(float size);
    Rect(float width, float height);
    Rect(float x, float y, float width, float height);

    void set_edge(Edge, Point);

	float min_x() const;
	float min_y() const;
    float max_x() const;
    float max_y() const;

    Point center() const;
    void set_center(const Point&);

    bool contains(const Point&) const;
    bool contains_with_edge(const Point&, float) const;

    Size fit_size(const Size&) const;

    Rect with_zero_origin() const;

    Rect& operator = (const Rect&);

    const char* to_string() const;
};

}
