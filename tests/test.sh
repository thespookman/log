#!/bin/bash

rm *.log
./test_prog
log_lines=`wc -l log.log | cut -d' ' -f1`
[ $log_lines -eq 1 ] || echo "Expected 1 lines in log.log. Got $log_lines."
[ $log_lines -eq 1 ] && echo "Pass" 
default_lines=`wc -l default.log | cut -d' ' -f1`
[ $default_lines -eq 1 ] || echo "Expected 1 lines in default.log. Got $default_lines."
[ $default_lines -eq 1 ] && echo "Pass" 
not_default_lines=`wc -l not_default.log | cut -d' ' -f1`
[ $not_default_lines -eq 1 ] || echo "Expected 1 lines in not_default.log. Got $not_default_lines."
[ $not_default_lines -eq 1 ] && echo "Pass" 
