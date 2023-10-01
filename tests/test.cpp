#include "spk_log.hpp"

using namespace spk::log;
int main () {
    Log test ("test.log");
    test.log ("Logging to test");
    return 0;
}
