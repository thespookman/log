#include "spk_log.hpp"

#include <ctime>
#include <format>
#include <iostream>

namespace spk {
namespace log {
using std::ofstream;
Log::Log () : ofstream () {}
using std::cerr;
using std::endl;
using std::string;
Log::Log (string file_name)
    : ofstream (file_name.c_str (), ofstream::app), id {file_name} {
    if (!is_open ()) cerr << file_name << " FAILED TO OPEN" << endl;
}

Log::~Log () {
    if (is_open ()) close ();
}

Log& Log::dedent (unsigned char num) {
    if (num < indent_count)
        indent_count -= num;
    else
        indent_count = 0;
    return *this;
}

Log& Log::indent (unsigned char num) {
    indent_count += num;
    return *this;
}

using std::gmtime;
using std::strftime;
Log& Log::log (string message) {
    if (!is_open ()) {
        cerr << message << ": LOG DISCARDED" << endl;
        return *this;
    }
    struct timespec ts;
    timespec_get (&ts, TIME_UTC);
    char date_time[256];
    strftime (date_time, 256, time_format.c_str (), gmtime (&ts.tv_sec));
    double nanos = (double) ts.tv_nsec / 1000000000;
    *this << date_time << "." << std::format ("{:09d}", ts.tv_nsec) << ": "
          << string (indent_count * indent_width, ' ') << message << endl;
    flush ();
    return *this;
}

Log& Log::set_default () {
    Logger::get_instance ()->set_default_log (id);
    return *this;
}

Log& Log::set_indent (unsigned char width) {
    indent_width = width;
    return *this;
}

Log& Log::set_time_format (string format) {
    time_format = format;
    return *this;
}
}; // namespace log
}; // namespace spk
