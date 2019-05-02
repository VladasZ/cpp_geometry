//
//  TexturedVertex.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vertex.hpp"

namespace gm {

class TexturedVertex : public Vertex {

public:

    using Array = std::vector<TexturedVertex>;

    Point texture_coordinate;

    TexturedVertex() = default;
    TexturedVertex(const Vector3& position, const Vector3& normal, const Point& texture_coordinate);

};

}
