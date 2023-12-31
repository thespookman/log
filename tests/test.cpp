#include "spk_log.hpp"

using namespace spk::log;
int main () {
    log ("Logging to log.log");
    get_log ("default.log").set_default ();
    log ("Logging to default.log");
    get_log ("not_default.log").log ("Logging to not_default.log");
    return 0;
}
