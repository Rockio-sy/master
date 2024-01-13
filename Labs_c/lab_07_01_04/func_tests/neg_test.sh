#!/bin/bash
../app.exe `cat neg_$1_args.txt` > out.txt
rc=$?

errors=("OK" "ARG_ERR" "MEMORY_ERR" "DATA_IS_EMPTY" "NOT_FOUND_FILE" "ARRAY_SRC_EMPTY" "ARRAY_DST_EMPTY" "FILE_IS_INCORRECT" "PARAMS_ERR")

{
FC out.txt neg_00_out.txt
  rc_s=$?
} &> /dev/null
if [ $rc_s == 0 ] && [ $rc != 0 ]
then
echo -e NEG_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[rc]} = $rc"
else
FC out.txt neg_00_out.txt
echo -e NEG_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[rc]} = $rc"
fi
rm "out.txt"
rm -rf "neg_out.txt"