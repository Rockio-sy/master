#ifndef MY_FILE_H
#define MY_FILE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STREET_MAX 20
#define SURNAME_MAX 20
#define NAME_MAX 7
#define STUDENT_MAX 1000
#define FILE_MAX 40
#define EXIT -1

//enumerated type that determines the gender of the student
enum gender
{
    female,
    male
};

//enumerated type that defines the type of dwelling
enum type_house
{
    house,
    dorm,
    rent
};

//structure containing the date of receipt
typedef struct
{
    int day;
    int month;
    int year;
}data;

//structure containing the address of the house
typedef struct
{
    char street[STREET_MAX + 1];
    int build_number;
    int flat_number;
}building;

//structure containing the address of the hostel
typedef struct
{
    int host_number;
    int room_number;
}hostel;

//structure containing the address of a rented dwelling
typedef struct
{
    char street[STREET_MAX + 1];
    int build_number;
    int flat_number;
    int cost;
}rental;

//structure containing student data
typedef struct
{
    char surname[SURNAME_MAX + 1];
    char name[NAME_MAX + 1];
    int group;
    enum gender gnd;
    int age;
    double average_mark;
    data data;
    enum type_house type;
    union
    {
        building bld;
        hostel hst;
        rental rnt;
    }choice;
}student;

//structure- table by keys
typedef struct
{
    size_t index;
    double average;
}key;

int process(student st[STUDENT_MAX], size_t *size);

#endif
