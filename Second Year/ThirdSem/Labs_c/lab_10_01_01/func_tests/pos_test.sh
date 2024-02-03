#!/bin/bash

../app.exe `cat pos_"$1"_args.txt` > "out.txt"
rc=$?

errors=("OK"
        "FILE_NOT_FOUND"
        "FILE_IS_EMPTY"
        "RESULT_FILE"
        "STRUCT_ERROR"
        "ACTION_ERROR"
        "ARGC_ERROR"
        "PARAMS_ERROR"
        "MEMORY_ERROR"
        "ERR_IO"
        "FIND_OVERFLOW"
        "FIND_ERROR")
{
  FC pos_out.txt pos_"$1"_out.txt
  rc_f=$?

  FC out.txt pos_$1_con.txt
  rc_s=$?
} &> /dev/null
if [ $rc_s == 0 ] && [ $rc == 0 ] && [ $rc_f == 0 ]
then
    echo -e POS_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[rc]} = $rc"
else
    FC pos_out.txt pos_"$1"_out.txt
    FC out.txt pos_"$1"_con.txt
    echo -e POS_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[rc]} = $rc"
fi