# libspklog.a
## Spookman's simple logging utility

### Basic Use
At its simplest, just log using

```c++
Log& spk::log::log(std::string message)
```

This will append message to a file `log.log`.

### Multiple files

To log to multiple files, or change the file name, use the get_log function, that returns a reference to a Log.

```c++
Log& spk::log::get_log(std::string file_name)
```

To log a message to a file `game.log` I can use 

```c++
Log& spk::log::Log::log(std::string message);
```

like

```c++
using namespace spk::log;
get_log("game.log").log("A message");
```

The default can also be changed, and the same file written to like so:

```c++
using namespace spk::log;
get_log("game.log").set_default();
log("A message");
```

### Indenting messages

Messages can be indented within the file, using the following three functions:

```
using namespace spk::log;
Log& Log::indent(unsigned char num = 1);
Log& Log::dedent(unsigned char num = 1);
Log& Log::set_indent(unsigned char width);
```

So I can log at different indents like this:

```c++
using namespace spk::log;
get_log("wide_indents.log").log("unindented").set_indent(8).indent().log("indented").dedent().log("unindented again");
get_log("narrow_indents.log").log("unindented").set_indent(2).indent().log("indented").dedent().log("unindented again");
```

The default indent width is 4. The indent can never become negative, so to reset the indent something like `dedent(UCHAR_MAX)` can be used.

### Timestamps

Each message will be prepended by a timestamp. The format of the timestamp can be set with

```c++
Log& spk::log::set_time_format(std::string format);
```

which sets the format of the time to a `std::strftime` compatible string. If this function is not called, a default of `"%F %T"` (`YYYY-MM-DD hh:mm:ss`) is used. Note that if the formatted time is longer than 255 characters, it will be truncated.

### API Reference

```c++
// Dedent the log
Log& Log::dedent (unsigned char num = 1);
// Indent the log
Log& Log::indent (unsigned char num = 1);
// Write to the log
Log& Log::log (std::string message);
// Set the default log to this one
Log& Log::set_default ();
// Set the indent width of the log
Log& Log::set_indent (unsigned char width);
// Set the time format of the log
Log& Log::set_time_format (std::string format);

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
```

Any functions returning a `Log&` will only operate on the `Log` returned, and will return the `Log` operated on.
