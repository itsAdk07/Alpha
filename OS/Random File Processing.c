#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define FILENAME "employee_records.txt"
struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
};

void addEmployee() {
    struct Employee employee;
    FILE *file = fopen(FILENAME, "ab");
    printf("Enter employee ID: ");
    scanf("%d", &employee.id);
    printf("Enter name: ");
    scanf(" %[^\n]", employee.name);
    printf("Enter salary: ");
    scanf("%f", &employee.salary);
    fwrite(&employee, sizeof(struct Employee), 1, file);
    fclose(file);
    printf("Employee record added successfully.\n");
}

void displayEmployees() {
    struct Employee employee;
    FILE *file = fopen(FILENAME, "rb");
    while (fread(&employee, sizeof(struct Employee), 1, file)) {
        printf("ID: %d\nName: %s\nSalary: %.2f\n\n", employee.id, employee.name, employee.salary);
    }
    fclose(file);
}

void updateEmployee() {
    int id;
    struct Employee employee;
    FILE *file = fopen(FILENAME, "rb+");
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    while (fread(&employee, sizeof(struct Employee), 1, file)) {
        if (employee.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", employee.name);
            printf("Enter new salary: ");
            scanf("%f", &employee.salary);
            fseek(file, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&employee, sizeof(struct Employee), 1, file);
            fclose(file);
            printf("Employee details updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
    fclose(file);
}

void searchEmployee() {
    int id;
    struct Employee employee;
    FILE *file = fopen(FILENAME, "rb");
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    while (fread(&employee, sizeof(struct Employee), 1, file)) {
        if (employee.id == id) {
            printf("Employee found!\nID: %d\nName: %s\nSalary: %.2f\n", employee.id, employee.name, employee.salary);
            fclose(file);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("----- OS LAB 6: C program for random access file  -----\n"
               "1. Add Employee\n"
               "2. Display Employees\n"
               "3. Update Employee\n"
               "4. Search Employee\n"
               "5. Exit\n"
               "--------------------------------------\n"
               "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
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

