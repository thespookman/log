#pragma once
#include <fstream>
#include <map>
#include <string>

namespace spk {
namespace log {
class Logger;
class Log : public std::ofstream {
  public:
    // Dedent the log
    Log& dedent (unsigned char num = 1);
    // Indent the log
    Log& indent (unsigned char num = 1);
    // Write to the log
    Log& log (std::string message);
    // Set the default log to this one
    Log& set_default ();
    // Set the indent width of the log
    Log& set_indent (unsigned char width);
    // Set the time format of the log
    Log& set_time_format (std::string format);

  private:
    Log ();
    Log (std::string file_name);
    ~Log ();
    std::string   id;
    std::string   time_format  = "%F %T";
    unsigned char indent_count = 0;
    unsigned char indent_width = 4;
    friend class Logger;
};

// Dedent the default log
Log& dedent (unsigned char num = 1);
// Indent the default log
Log& indent (unsigned char num = 1);
// Get the requested log (or default if log not supplied or empty string)
Log& get_log (std::string log = "");
// Write to the default log
Log& log (std::string message);
// Set the indent width of all logs
void set_indent (unsigned char width);
// Set the time format of all logs
void set_time_format (std::string format);

class Logger : public std::map<std::string, Log*> {
  private:
    Logger () {}
    ~Logger ();
    static Logger* get_instance ();
    Log&           get_log (std::string log);
    void           set_default_log (std::string log);
    void           set_indent (unsigned char width);
    void           set_time_format (std::string format);
    std::string    default_log;
    friend Log&    get_log (std::string log);
    friend void    set_indent (unsigned char width);
    friend void    set_time_format (std::string format);
    friend class Log;
};
}; // namespace log
}; // namespace spk
