#pragma once
#include <fstream>
#include <string>

namespace spk {
namespace log {
class Log : public std::ofstream {
  public:
    Log ();
    Log (std::string file_name);
    ~Log ();

    void log (std::string message, char indent_change = 0);
    void set_time_format (std::string format);

  private:
    std::string time_format = "%F %T";
    short       indent      = 0;
};
}; // namespace log
}; // namespace spk
