#!/bin/bash

make
./tests | sed "s/\[.*\]/\[19920104_091532\]/g" > tmp.log
diff -sc 19920104_091532.log tmp.log
make fclean