#!/bin/bash

make
./tests | sed "s/\[.*\]/\[19920104_091532\]/g" > tmp.log
diff -s 19920104_091532.log tmp.log
rm tmp.log
make fclean