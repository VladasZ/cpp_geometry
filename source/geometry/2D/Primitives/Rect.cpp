//
//  Rect.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <string>

#include "Rect.hpp"

using namespace gm;


Rect::Rect(const Size& _size) : size(_size) {

}

Rect::Rect(Float size) : size({ size, size }) {

}

Rect::Rect(Float width, Float height) : size({ width, height }) {

}

void Rect::set_edge(Edge edge, Point point) {

    if (edge == Edge::None) {
        return;
    }

    auto value = static_cast<uint64_t>(edge);

    if (value & static_cast<uint64_t>(Edge::Bottom)) {
        size.height = point.y - origin.y;
    }

    if (value & static_cast<uint64_t>(Edge::Right)) {
        size.width = point.x - origin.x;
    }

    if (value & static_cast<uint64_t>(Edge::Top)) {
        size.height += origin.y - point.y;
        origin.y = point.y;
    }

    if (value & static_cast<uint64_t>(Edge::Left)) {
        size.width += origin.x - point.x;
        origin.x = point.x;
    }
}

Float Rect::min_x() const {
	return origin.x;
}

Float Rect::min_y() const {
	return origin.y;
}

Float Rect::max_x() const {
    return origin.x + size.width;
}

Float Rect::max_y() const {
    return origin.y + size.height;
}

Rect Rect::with_x(Float x) const {
    Rect copy = *this;
    copy.origin.x = x;
    return copy;
}

Rect Rect::with_y(Float y) const {
    Rect copy = *this;
    copy.origin.y = y;
    return copy;
}

Point Rect::center() const {
    return {
        origin.x + size.width  / 2,
        origin.y + size.height / 2
    };
}

void Rect::set_center(const Point& center) {
    origin.x = center.x - size.width  / 2;
    origin.y = center.y - size.height / 2;
}

bool Rect::contains(const Point& point) const {
    return point.x >= origin.x              &&
           point.y >= origin.y              &&
           point.x <= origin.x + size.width &&
           point.y <= origin.y + size.height;
}

bool Rect::contains_with_edge(const Point& point, Float edge) const {

    bool contains = point.x >= origin.x               - edge &&
                    point.y >= origin.y               - edge &&
                    point.x <= origin.x + size.width  + edge &&
                    point.y <= origin.y + size.height + edge;

    if (!contains) return false;

    Rect inside =
            { origin.x + edge,
              origin.y + edge,
              size.width - edge * 2,
              size.height - edge * 2
            };

    return !inside.contains(point);
}

Size Rect::fit_size(const Size& _size) const {

    Float ratio;

    if (_size.width > _size.height) {
        ratio = this->size.width / _size.width;
    }
    else {
        ratio = this->size.height / _size.height;
    }

    return { _size * ratio };
}

Rect Rect::with_zero_origin() const {
    return { size };
}

std::array<Rect, 4> Rect::edges() const {
    return std::array<Rect, 4> {
            Rect { origin.x                 , origin.y                  , size.width, 1           },
            Rect { origin.x + size.width - 1, origin.y                  , 1         , size.height },
            Rect { origin.x                 , origin.y + size.height - 1, size.width, 1           },
            Rect { origin.x                 , origin.y                  ,          1, size.height }
    };
}

std::string Rect::to_string() const {
    return std::string() + origin.to_string() + " " + size.to_string();
}
