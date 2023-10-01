#include "spk_log.hpp"

namespace spk {
namespace log {
Log global_log;

using std::string;
void log (string message, char indent_change) {
    if (!global_log.is_open ()) init ("default.log");
    global_log.write (message, indent_change);
}

using std::ofstream;
void init (string file_name) {
    if (global_log.is_open ()) global_log.close ();
    global_log.open (file_name, ofstream::app);
    log ("Logger intialised");
}

void set_time_format (string format) { global_log.time_format = format; }
}; // namespace log
}; // namespace spk
