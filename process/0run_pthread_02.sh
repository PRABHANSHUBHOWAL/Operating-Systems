#!/bin/bash
#gcc -g -lpthread -o pthread_02 pthread_02.c

#find avg run time of pthread_02 for 1000 runs
echo 'scale=8; (' $(for i in {1..1000}; do ./pthread_02 | tail -1 | cut -d ':' -f2; done | paste -s -d '+') ')/1000.0' | bc

