//
//  Ray.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "LineSegment.hpp"


namespace gm {

    class Ray : public LineSegment {

        Vector3 _direction;
        Vector3 _dirfrac;

    public:

        constexpr Ray(const Vector3& origin, const Vector3& end) : LineSegment(origin, end) {
            _direction = end - origin;
            _direction.normalize();
            _dirfrac.x = 1.0f / _direction.x;
            _dirfrac.y = 1.0f / _direction.y;
            _dirfrac.z = 1.0f / _direction.z;
        }

        constexpr Vector3 direction() const { return _direction; }
        constexpr Vector3 dirfrac()   const { return _dirfrac;   }

        std::pair<Vector3, Vector3> closest_points_with(const Ray&) const;

        bool intersects_plane(const LineSegment&) const;
        float distance_to_plane(const LineSegment&) const;
        Vector3 plane_intersection(const LineSegment&) const;

        std::string to_string() const override;

    };

}
