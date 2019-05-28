//
//  Vertex.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"

namespace gm {

class Vertex {

public:

    using Index   = unsigned short;
    using Indices = std::vector<Index>;
    using Array   = std::vector<Vertex>;

    const Vector3 position;
    const Vector3 normal;
    const Point uv;

    Vertex() = default;
    Vertex(const Vector3& position, const Vector3& normal = { 0, 0, 1 }, const Point& uv = { });

    std::string to_string() const;
};

}
