#!/bin/bash

rm *.log
./test_prog
test_lines=`wc -l test.log | cut -d' ' -f1`
[ $test_lines -eq 1 ] || echo "Expected 1 lines in test.log. Got $test_lines."
[ $test_lines -eq 1 ] && echo "Pass" && exit 0
exit 1;
