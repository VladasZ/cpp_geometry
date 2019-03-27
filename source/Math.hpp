//
//  Math.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 2/15/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <limits>
#include <cstdint>

namespace math {

template <class T> constexpr T pi       = T { 3.14159265358979323846 };
template <class T> constexpr T tau      = T { 6.28318530717958647692 };
template <class T> constexpr T half_pi  = T { 1.57079632679489661923 };
template <class T> constexpr T quart_pi = half_pi<T> / T{2};

namespace _helpers {
template <class T>
T constexpr sqrt(T x, T curr, T prev) {
    return curr == prev ? curr : sqrt(x, (curr + x / curr) / T{2}, curr);
}
}

template <class T>
T constexpr sqrt(T x) {
    return x >= 0 && x < std::numeric_limits<T>::infinity() ? _helpers::sqrt<T>(x, x, T{0}) : std::numeric_limits<T>::quiet_NaN();
}

}
