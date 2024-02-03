#!/bin/bash

../main.exe `cat pos_"$1"_args.txt` > "out.txt"
rc=$?
{
FC out.txt pos_"$1"_out.txt
rc_s=$?
} &> /dev/null

if [ $rc_s == 0 ] && [ $rc == 0 ]
then
echo -e POS_"$1": "\e[32mPASSED\e[0m"
else
FC out.txt pos_"$1"_out.txt
echo -e POS_"$1": "\e[31mFAILED\e[0m"
fi
rm "out.txt"