//
//  PointsPath.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>
#include <string>

#include "Rect.hpp"

namespace gm {

class PointsPath {

public:

    using Points = std::vector<Point>;

    enum DrawMode {
        Lines,
        LineStrip,
    };

private:

    Points _points;

public:

    DrawMode draw_mode = LineStrip;

    PointsPath() = default;
    PointsPath(Points&&);
    PointsPath(const Rect&);

    void add_point(float x, float y);
    void add_point(const Point& point);

    size_t size() const;
    Points& points();
    const float* data() const;
    const std::vector<float> floats_vector() const;

    void clear();

public:

    static PointsPath *circle_with(const Point &center, float radius, int precision = 50);

    std::string to_string() const;

};

}
