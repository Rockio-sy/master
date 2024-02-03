#ifndef _MY_SNPRINTF_H
#define _MY_SNPRINTF_H

#include <stdio.h>
#include <stdarg.h>

#define MAX_OC_NUM 37777777778

size_t get_rank(long long num);
long long conventing_to_number_system(int number, int system);
void add_char_in_str(char *str, char c, int *count, size_t n);
void add_str_in_str(char *str, const char *add_str, int *count, size_t n);
void add_num_in_str(char *str, long long num, int *count, size_t n);

int my_snprintf(char *restrict str, size_t n, const char *restrict format, ...);

#endif //_MY_SNPRINTF_H
