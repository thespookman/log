#include "spk_log.hpp"

#include <ctime>
#include <format>

namespace spk {
namespace log {
using std::ofstream;
Log::Log () : ofstream (), file_name {""} {}
using std::string;
Log::Log (string file)
    : ofstream (file.c_str (), ofstream::app), file_name {file} {}
Log::Log (Log& log) : Log (log.file_name) {}

Log::~Log () {
    if (is_open ()) close ();
}

Log& Log::operator= (const Log& log) {
    if (is_open ()) close ();
    open (log.file_name, ofstream::app);
    file_name = log.file_name;
    return *this;
}

string Log::get_file_name () { return file_name; }
using std::endl;
using std::gmtime;
using std::strftime;
void Log::write (string message, char indent_change) {
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
}; // namespace log
}; // namespace spk
