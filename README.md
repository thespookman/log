# libspklog.a
## Spookman's simple logging utility

Simply put, set the file to log to using

```c++
spk::log::init(std::string filename);
```

This function can be called at any time to change the file to log to.

Log to the file using

```c++
spk::log::log(std::string message, size_t indent_change=0);
```

If `indent_change` is greater than 0, any lines following will be indented by `indent_change` spaces. If `indent_change` is less than 0, the current line and any following will be unindented similarly.

```c++
spk::log::set_time_format(std::string format);
```

Sets the format of the time to a `std::strftime` compatible string. If this function is called, a default of `"%F %T"` (`YYYY-MM-DD hh:mm:ss`) is used. Note that if the formatted time is longer than 255 characters, it will be truncated.
