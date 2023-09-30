#pragma once
#include <fstream>
#include <string>

namespace spk {
namespace log {
class Log : public std::ofstream {
  public:
    Log ();
    Log (std::string file);
    Log (Log& log);
    ~Log ();

    Log& operator= (const Log& log);

    void write (std::string message, char indent_change);

  private:
    std::string file_name;
    std::string time_format = "%F %T";
    short       time_length = 20;
    short       indent      = 0;

    friend void set_time_format (std::string format, size_t length);
};

void       log (std::string message, char indent_change = 0);
void       init (std::string file_name);
void       set_time_format (std::string format, size_t length);
extern Log global_log;
}; // namespace log
}; // namespace spk
