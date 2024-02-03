#ifndef MY_TIME_H
#define MY_TIME_H

typedef unsigned long long microsecond_t;
#define MSC "llu" // Спецификатор для типа microsecond_t

microsecond_t microseconds_now(void);

#endif