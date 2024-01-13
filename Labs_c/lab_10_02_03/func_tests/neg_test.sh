#!/bin/bash
../app.exe < "neg_$1_in.txt" > "out.txt"
rc=$?

{
  FC out.txt neg_$1_out.txt
  rc_s=$?
} &> /dev/null
if [ $rc_s == 0 ] && [ $rc != 0 ]
then
    echo -e NEG_"$1": "\e[32mPASSED\e[0m"
else
    FC out.txt neg_$1_out.txt
    echo -e NEG_"$1": "\e[31mFAILED\e[0m"
fi
rm out.txt