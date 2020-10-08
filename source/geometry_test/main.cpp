
#include "Log.hpp"
#include "Matrix4.hpp"

int main() {

    auto spes  = gm::Vector4::transform::quaternion_rotating_x(1);
    auto spes2 = gm::Vector4::transform::quaternion_rotating_y(0.5);

    Log << spes;
    Log << spes.length();

    auto spes3 = spes * spes2;

    Log << spes3;
    Log << spes3.length();

    return 0;
}
