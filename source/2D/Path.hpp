//
//  Path.hpp
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

class Path {

public:

    using Points = std::vector<Point>;
    using Ptr = std::shared_ptr<Path>;

private:

    Points _points;

public:

    Path() = default;
    Path(Points&&);
    Path(const Rect&);

    void add_point(float x, float y);
    void add_point(const Point& point);

    size_t size() const;
    const Points points() const;
    const float*   data() const;
    const std::vector<float> floats_vector() const;

public:

    static Path *circle_with(const Point &center, float radius, int precision = 50);

    std::string to_string() const;

};

}
