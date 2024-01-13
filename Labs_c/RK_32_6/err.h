#ifndef ERR_H
#define ERR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 31
#define MAX_GROUP 11
/**
 * Structs student to list from file
 * Group to group students depends on their group
 */
struct Student {
    char *lastName;
    int admissionYear;
    char *group;
    struct Student *next;
};

struct Group {
    char *groupName;
    struct Student *students;
    struct Group *nextGroup;
};

#define ERR_OK 0
#define ERR_ALLOC 1
#define ERR_DATA 2
#define ERR_OPEN 3
#define ERR_EMPTY 4
#define ERR_ARG 5

#endif
