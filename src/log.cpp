#include "spk_log.hpp"

#include <ctime>
#include <format>

namespace spk {
namespace log {
using std::ofstream;
Log::Log () : ofstream () {}
using std::string;
Log::Log (string file_name)
    : ofstream (file_name.c_str (), ofstream::app) {}

Log::~Log () {
    if (is_open ()) close ();
}

using std::endl;
using std::gmtime;
using std::strftime;
void Log::log (string message, char indent_change) {
    if (!is_open ()) return;
    struct timespec ts;
    timespec_get (&ts, TIME_UTC);
    char date_time[256];
    strftime (date_time, 256, time_format.c_str (), gmtime (&ts.tv_sec));
    double nanos = (double) ts.tv_nsec / 1000000000;
    if (indent_change < 0) indent += indent_change;
    *this << date_time << "." << std::format ("{:09d}", ts.tv_nsec) << ": "
          << string (indent, ' ') << message << endl;
    if (indent_change >= 0) indent += indent_change;
    flush ();
}

void Log::set_time_format (string format) { time_format = format; }
}; // namespace log
}; // namespace spk
