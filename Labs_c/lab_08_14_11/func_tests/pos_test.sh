#!/bin/bash

../app.exe `cat pos_"$1"_args.txt` > "out.txt"
rc=$?

errors=("OK"
        "ARGC_ERROR"
        "PARAMS_ERROR"
        "ACTION_ERROR"
        "FILE_NOT_FOUND"
        "FILE_IS_EMPTY"
        "INVALID_ERROR"
        "SIZE_N_ERROR"
        "SIZE_M_ERROR"
        "MATRIX_DATA_EMPTY"
        "MATRIX_DATA_OVERFLOW"
        "SUM_ERROR"
        "MULTI_ERROR"
        "INVERSE_MATRIX_ERROR"
        "NON_DEG_ERROR"
        "MEMORY_ERROR")
{
  FC pos_out.txt pos_"$1"_out.txt
  rc_f=$?

  FC out.txt neg_00_out.txt
  rc_s=$?
} &> /dev/null
if [ $rc_s == 0 ] && [ $rc == 0 ] && [ $rc_f == 0 ]
then
    echo -e POS_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[rc]} = $rc"
else
    FC pos_out.txt pos_"$1"_out.txt
    echo -e POS_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[rc]} = $rc"
fi
rm out.txt pos_out.txt