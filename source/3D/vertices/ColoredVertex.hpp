//
//  ColoredVertex.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "Vertex.hpp"

namespace gm {

class ColoredVertex : public Vertex {

public:

    using Array = std::vector<ColoredVertex>;

    Color color;

    ColoredVertex() = default;
    ColoredVertex(const Vector3& position, const Vector3& normal);
    ColoredVertex(const Vector3& position, const Vector3& normal, const Color& color);

};

}
