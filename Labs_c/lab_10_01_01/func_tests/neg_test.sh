#!/bin/bash
../app.exe `cat neg_$1_args.txt` > out.txt
rc=$?

errors=("OK"
        "FILE_NOT_FOUND"
        "FILE_IS_EMPTY"
        "RESULT_FILE"
        "STRUCT_ERROR"
        "ACTION_ERROR"
        "ARGC_ERROR"
        "PARAMS_ERROR"
        "ERR_IO"
        "FIND_OVERFLOW"
        "FIND_ERROR"
        "MEMORY_ERROR"
        )

{
    FC out.txt neg_$1_con.txt
    rc_s=$?
} &> /dev/null
if [ $rc_s == 0 ] && [ $rc != 0 ]
then
    echo -e NEG_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[rc]} = $rc"
else
    FC out.txt neg_$1_con.txt
    echo -e NEG_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[rc]} = $rc"
fi