#include "spk_log.hpp"

namespace spk {
namespace log {
using std::string;
Log& dedent (unsigned char num) { return get_log ().dedent (num); }

Log& indent (unsigned char num) { return get_log ().indent (num); }

Log& get_log (string log) {
    return Logger::get_instance ()->get_log (log);
}

Log& log (string message) { return get_log ().log (message); }

void set_indent (unsigned char width) {
    Logger::get_instance ()->set_indent (width);
}

void set_time_format (string format) {
    Logger::get_instance ()->set_time_format (format);
}
}; // namespace log
}; // namespace spk
