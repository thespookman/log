#include "spk_log.hpp"

using namespace spk::log;
int main () {
    log ("Logging to default");
    init ("test.log");
    log ("Logging to test");
    return 0;
}
