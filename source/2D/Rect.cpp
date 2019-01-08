//
//  Rect.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <iostream> // REMOVE
using namespace  std;

#include "stdint.h"

#include "Rect.hpp"

using namespace ui;

Rect::Rect(const Size& _size) : size(_size) {

}

Rect::Rect(float width, float height) : size({ width, height }) { 

}

Rect::Rect(float x, float y, float width, float height) : origin({ x, y }), size({ width, height }) {

}

void Rect::set_edge(Edge edge, Point point) {

    if (edge == Edge::None)
        return;

    auto value = static_cast<uint64_t>(edge);

    if (value & static_cast<uint64_t>(Edge::Bottom))
        size.height = point.y - origin.y;

    if (value & static_cast<uint64_t>(Edge::Right))
        size.width = point.x - origin.x;

    if (value & static_cast<uint64_t>(Edge::Top)) {
        size.height += origin.y - point.y;
        origin.y = point.y;
    }

    if (value & static_cast<uint64_t>(Edge::Left)) {
        size.width += origin.x - point.x;
        origin.x = point.x;
    }
}

float Rect::max_x() const { 
    return origin.x + size.width;
}

float Rect::max_y() const { 
    return origin.y + size.height;
}

Point Rect::center() const {
    return {
        origin.x + size.width  / 2,
        origin.y + size.height / 2
    };
}

bool Rect::contains(const Point& point) const {
    return point.x >= origin.x              &&
           point.y >= origin.y              &&
           point.x <= origin.x + size.width &&
           point.y <= origin.y + size.height;
}

bool Rect::contains_with_edge(const Point& point, float edge) const {
    return point.x >= origin.x               - edge &&
           point.y >= origin.y               - edge &&
           point.x <= origin.x + size.width  + edge &&
           point.y <= origin.y + size.height + edge;
}

Size Rect::fit_size(const Size& size) const {

    float ratio = this->size.width / size.width;

    if (size.width > size.height)
        ratio = this->size.width / size.width;
    else
        ratio = this->size.height / size.height;

    return { size * ratio };
}

Rect Rect::with_zero_origin() const {
    return { size };
}

Rect& Rect::operator = (const Rect& r2) {
    origin = r2.origin;
    size   = r2.size;
    return *this;
}

const char* Rect::to_string() const {
    static std::string value;
    value = std::string() + origin.to_string() + " " + size.to_string();
    return value.c_str();
}
