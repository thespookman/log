#pragma once
#include <fstream>
#include <string>

namespace spk {
namespace log {

void init (std::string file_name);
void log (std::string message, char indent_change = 0);
void set_time_format (std::string format, size_t length);

class Log : public std::ofstream {
  public:
    Log ();
    Log (std::string file_name);
    ~Log ();

    void write (std::string message, char indent_change);

  private:
    std::string time_format = "%F %T";
    short       indent      = 0;

    friend void set_time_format (std::string format);
};

extern Log global_log;
}; // namespace log
}; // namespace spk
