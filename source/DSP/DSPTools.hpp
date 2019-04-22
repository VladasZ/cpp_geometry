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

    template<class Container>
    [[maybe_unused]]
    static auto find_peaks(const Container& data) {
        std::vector<uint64_t> result;

        for (size_t i = 1; i < data.size() - 1; i++) {
            const float a = data[i - 1];
            const float b = data[i    ];
            const float c = data[i + 1];

            const float threshold_value = b - 0.005f;

            if (threshold_value > a && threshold_value > c)
                result.push_back(i);
        }

        return result;
    }
};

}
