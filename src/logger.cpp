#include "spk_log.hpp"

#include <stdexcept>

namespace spk {
namespace log {
Logger* Logger::get_instance () {
    static Logger instance;
    return &instance;
}
using std::string;
typedef Logger::iterator logit;
Logger::~Logger () {
    for (logit i = begin (); i != end (); ++i) delete i->second;
};
using std::out_of_range;
Log& Logger::get_log (string log) {
    if (log == "") {
        if (default_log == "")
            log = "log.log";
        else
            log = default_log;
    }
    try {
        return *at (log);
    } catch (out_of_range e) {
        return *(*emplace (log, new Log (log)).first).second;
    }
}

void Logger::set_default_log (string log) { default_log = log; }
void Logger::set_indent (unsigned char width) {
    for (logit i = begin (); i != end (); ++i)
        i->second->set_indent (width);
}
void Logger::set_time_format (std::string format) {
    for (logit i = begin (); i != end (); ++i)
        i->second->set_time_format (format);
}
}; // namespace log
}; // namespace spk

