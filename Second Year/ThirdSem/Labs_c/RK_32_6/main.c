#include "io.h"

int main(int argc, char* argv[]) {
    if (argc != 2){
        return ERR_ARG;
    }
    struct Student *head = NULL;
    FILE *file = fopen("in", "r");

    if (file == NULL) {
        perror("Error opening file");
        return ERR_OPEN;
    }

    char lastName[MAX_LENGTH];
    int admissionYear;
    char group[MAX_GROUP];

    // Read student info
    while (fscanf(file, "%30s %d %10s", lastName, &admissionYear, group) == 3) {
        if (admissionYear < 0){
            printf("vInvalid data\n");
            return ERR_DATA;
        }
        struct Student *newStudent = createStudent(lastName, admissionYear, group);
        if (!newStudent){
            printf("Error allocating memory!\n");
            return ERR_ALLOC;
        }
        if (head == NULL) {
            head = newStudent;
        } else {
            struct Student *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    fclose(file);

    if (strcmp(argv[1], "LIST") == 0) {
        // list
        printList(head);
        freeList(head);
    }else if (strcmp(argv[1], "GROUP") == 0) {
        // Group
        printf("------------------GROUPS-----------------------\n");
        groupStudents(head);
        freeList(head);
    }else{
        printf("USAGE: ./app (LIST || GROUP)");
        return ERR_ARG;
    }
    return ERR_OK;
}
