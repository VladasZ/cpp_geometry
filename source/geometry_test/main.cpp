
#include "Log.hpp"
#include "GmMapping.hpp"

using namespace gm;

int main() {

    Log << json_mapper.to_json(Rect(345, 434, 17, 434));

    return 0;
}
