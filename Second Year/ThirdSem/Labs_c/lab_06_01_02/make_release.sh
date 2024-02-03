#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c main.c
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c struct_stdio.c
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c struct_task.c
gcc -o main.exe main.o struct_stdio.o struct_task.o