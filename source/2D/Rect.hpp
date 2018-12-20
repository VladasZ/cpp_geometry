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

namespace ui {

	class Rect {

    public:

        enum class Edge {
            Top         = 0b00000001,
            Bottom      = 0b00000010,
            Left        = 0b00000100,
            Right       = 0b00001000,
            TopLeft     = Top    | Left,
            TopRight    = Top    | Right,
            BottomLeft  = Bottom | Left,
            BottomRight = Bottom | Right,
            None        = 0
        };

	public:

		Point origin;
		Size  size;

		Rect() = default;
		Rect(const Size& size);
		Rect(float width, float height);
		Rect(float x, float y, float width, float height);

        void set_edge(Edge edge, Point point);

		float max_x() const;
		float max_y() const;

		Point center() const;

		bool contains(const Point& point) const;
		bool contains_with_edge(const Point& point, float edge) const;

		Size fit_size(const Size& size) const;

		Rect with_zero_origin() const;

        Rect& operator = (const Rect& r2);

        const char* to_string() const;
	};

}
