#include "spk_log.hpp"

namespace spk {
namespace log {
Log global_log;

using std::string;
void log (string message, char indent_change) {
    if (global_log.get_file_name ().empty ()) init ("default.log");
    global_log.write (message, indent_change);
}

void init (string file_name) {
    global_log = Log (file_name);
    log ("Logger intialised");
}

void set_time_format (string format) { global_log.time_format = format; }
}; // namespace log
}; // namespace spk
