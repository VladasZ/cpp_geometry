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
#include "NonCopyable.hpp"


namespace gm {

    class PointsPath : cu::NonCopyable {

    public:

        enum DrawMode {
            Lines,
            LineStrip,
        };

    private:

        std::vector<Point> _points;

    public:

        DrawMode draw_mode = LineStrip;

        PointsPath() = default;

        explicit PointsPath(const Rect&);

        void add_point(const Point& point);

        size_t size() const;
        const std::vector<Point>& points();

        void clear();

    public:

        static PointsPath *circle_with(const Point &center, float radius, int precision = 50);

        std::string to_string() const;

    };

}
