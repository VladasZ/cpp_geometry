//
//  TexturedVertex.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TexturedVertex.hpp"

using namespace gm;

TexturedVertex::TexturedVertex(const Vector3& position, const Vector3& normal, const Point& texture_coordinate)
    : Vertex (position, normal), texture_coordinate(texture_coordinate) { }
