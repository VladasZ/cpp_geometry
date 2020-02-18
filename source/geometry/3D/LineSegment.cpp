//
//  LineSegment.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "LineSegment.hpp"

using namespace gm;

std::string LineSegment::to_string() const {
    return std::string() + "\n" + begin.to_string() + "\n" + end.to_string();
}
