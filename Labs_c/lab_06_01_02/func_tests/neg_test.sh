#!/bin/bash
../main.exe `cat neg_$1_args.txt` > "out.txt"
rc=$?

{
FC out.txt neg_00_out.txt
rc_s=$?
} &> /dev/null

if [ $rc_s == 0 ] && [ $rc != 0 ]
then
echo -e NEG_"$1": "\e[32mPASSED\e[0m" "Code error: $rc"
else
FC out.txt neg_00_out.txt
echo -e NEG_"$1": "\e[31mFAILED\e[0m"
fi
rm "out.txt"