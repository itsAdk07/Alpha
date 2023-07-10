#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define FILENAME "studentfile.txt"

struct Student {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
};

void addStudent() {
    struct Student student;
    FILE *file;

    file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", student.name);
    fwrite(&student, sizeof(struct Student), 1, file);
    fclose(file);
    printf("Student record added successfully.\n");
}

void displayStudents() {
    struct Student student;
    FILE *file;
    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(struct Student), 1, file)) {
        printf("Roll Number: %d\n", student.rollNumber);
        printf("Name: %s\n\n", student.name);
    }
    fclose(file);
}

void searchStudent() {
    int rollNumber;
    struct Student student;
    FILE *file;
    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Roll Number: %d\n", student.rollNumber);
            printf("Name: %s\n", student.name);
            fclose(file);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNumber);
    fclose(file);
}
int main() {
    int choice;
    while (1) {
        printf("----- OS LAB 6: SEQUENTIAL FILE PROCESSING  -----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}
