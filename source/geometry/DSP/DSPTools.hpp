//
//  DSPTools.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 4/10/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

namespace gm {

class DSP {

public:

    template<class Container, class Value = typename Container::value_type>
    static auto find_peaks(const Container& data, float threshold = 0.005f) {
        std::vector<Value> result;

        for (size_t i = 1; i < data.size() - 1; i++) {
            const float a = data[i - 1];
            const float b = data[i    ];
            const float c = data[i + 1];

            const float threshold_value = b - threshold;

            if (threshold_value > a && threshold_value > c) {
                result.push_back(i);
            }
        }

        return result;
    }
};

}
