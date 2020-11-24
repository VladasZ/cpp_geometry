//
//  Vertex.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Vertex.hpp"

using namespace gm;


Vertex::Vertex(const Vector3& position, const Vector3& normal, const Point& uv)
    : position(position), normal(normal), uv(uv) { }

const float*Vertex::data() const {
    return &position.x;
}

std::string Vertex::to_string() const {
    return position.to_string();
}
