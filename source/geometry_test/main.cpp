
#include "Log.hpp"
#include "Matrix4.hpp"

int main() {
    auto mat = gm::Matrix4::transform::scale(10.0f);
    Logvar(mat.to_string());
    return 0;
}
