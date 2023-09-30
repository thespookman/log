#include "spklog.hpp"

namespace spk {
namespace log {
Log global_log;

using std::string;
void log(string message, char indent_change) {
    global_log.write(message, indent_change);
}

void init(string file_name) { global_log = Log(file_name); }

void set_time_format(string format, size_t length) {
    global_log.time_format = format;
    global_log.time_length = length;
}
};  // namespace log
};  // namespace spk
