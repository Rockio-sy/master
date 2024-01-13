#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
/**
 * createStudent Function to create and allocate memory for nod of student in the linked list
 * createGroup Function to create group adn allocate memory for the node
 * both print(group||list) to print the list or group depends on the argument
 * both free (group||list) to free the memory of the linkedlist of lists or groups
 * groupStudents Function to group the students depends on their group
 */

struct Student *createStudent(char lastName[], int admissionYear, char group[]) {
    struct Student *newStudent = (struct Student *) malloc(sizeof(struct Student));
    if (!newStudent){
        printf("Error allocating memory\n");
        return NULL;
    }

    // Allocate memory for dynamic arrays and copy data
    newStudent->lastName = strdup(lastName);
    newStudent->group = strdup(group);

    newStudent->admissionYear = admissionYear;
    newStudent->next = NULL;
    return newStudent;
}


struct Group *createGroup(char groupName[]) {
    struct Group *newGroup = malloc(sizeof(struct Group));
    if (!newGroup){
        printf("Error allocating memory\n");
        return NULL;
    }

    newGroup->groupName = strdup(groupName);
    newGroup->students = NULL;
    newGroup->nextGroup = NULL;
    return newGroup;
}


void printList(struct Student *head) {
    if (head == NULL){
        printf("EMPTY! %d\n", ERR_EMPTY);
        return;
    }
    printf("------------------------LIST-----------------------\n");
    struct Student *current = head;
    while (current != NULL) {
        printf("\nLast Name: %s\nAdmission Year: %d\nGroup: %s\n",
               current->lastName, current->admissionYear, current->group);
        current = current->next;
    }
}


void printGroup(struct Group *group) {
    printf("Group %s:\n", group->groupName);
    struct Student *current = group->students;
    while (current != NULL) {
        printf("Last Name: %s, Admission Year: %d, Group: %s\n",
               current->lastName, current->admissionYear, current->group);
        current = current->next;
    }
    printf("\n");
}


void freeList(struct Student *head) {
    struct Student *current = head;
    struct Student *next;
    while (current != NULL) {
        next = current->next;
        free(current->lastName);
        free(current->group);
        free(current);
        current = next;
    }
}


void freeGroup(struct Group *group) {
    struct Student *current = group->students;
    struct Student *next;
    while (current != NULL) {
        next = current->next;
        free(current->lastName);
        free(current->group);
        free(current);
        current = next;
    }
    free(group->groupName); // Free the memory for groupName
    free(group);
}



void groupStudents(struct Student *head) {
    struct Group *groupList = createGroup("Dummy");

    struct Student *current = head;
    while (current != NULL) {
        struct Group *group = groupList->nextGroup;
        struct Group *prevGroup = groupList;

        while (group != NULL && strcmp(group->groupName, current->group) != 0) {
            prevGroup = group;
            group = group->nextGroup;
        }

        if (group == NULL) {
            struct Group *newGroup = createGroup(current->group);
            prevGroup->nextGroup = newGroup;
            group = newGroup;
        }

        struct Student *newStudent = createStudent(current->lastName, current->admissionYear, current->group);
        newStudent->next = group->students;
        group->students = newStudent;

        current = current->next;
    }

    struct Group *currentGroup = groupList->nextGroup;
    while (currentGroup != NULL) {
        printGroup(currentGroup);
        struct Group *nextGroup = currentGroup->nextGroup;
        freeGroup(currentGroup);
        currentGroup = nextGroup;
    }

    free(groupList);
}
