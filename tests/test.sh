#!/bin/bash

rm *.log
./test_prog
default_lines=`wc -l default.log | cut -d' ' -f1`
test_lines=`wc -l test.log | cut -d' ' -f1`
[ $default_lines -eq 2 ] || echo "Expected 2 lines in default.log. Got $default_lines."
[ $test_lines -eq 2 ] || echo "Expected 2 lines in test.log. Got $test_lines."
[ $default_lines -eq 2 ] && [ $test_lines -eq 2 ] && echo "Pass" && exit 0
exit 1;
