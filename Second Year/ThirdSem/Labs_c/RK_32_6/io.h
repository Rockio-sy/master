#ifndef IO_H
#define IO_H
#include "err.h"

struct Student *createStudent(char lastName[], int admissionYear, char group[]);
struct Group *createGroup(char groupName[]);
void printList(struct Student *head);
void freeList(struct Student *head);
void printGroup(struct Group *group);
void freeGroup(struct Group *group);
void groupStudents(struct Student *head);
#endif