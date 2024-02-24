#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define FILENAME "employee.dat"

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
};

void addEmployee() {
    FILE *fp;
    struct Employee emp;

    fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error opening file for appending\n");
        return;
    }

    printf("Enter employee id: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, fp);

    fclose(fp);

    printf("Employee added successfully\n");
}

void displayAllEmployees() {
    FILE *fp;
    struct Employee emp;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return;
    }

    printf("Employee details:\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(fp);
}

void updateEmployee() {
    FILE *fp;
    struct Employee emp;
    int id, found = 0;

    fp = fopen(FILENAME, "r+b");
    if (fp == NULL) {
        printf("Error opening file for updating\n");
        return;
    }

    printf("Enter employee id to update: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == id) {
            printf("Enter new name: ");
            scanf("%s", emp.name);
            printf("Enter new salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&emp, sizeof(struct Employee), 1, fp);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with id %d not found\n", id);
    } else {
        printf("Employee details updated successfully\n");
    }

    fclose(fp);
}

void deleteEmployee() {
    FILE *fp, *temp;
    struct Employee emp;
    int id, found = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temp file\n");
        fclose(fp);
        return;
    }

    printf("Enter employee id to delete: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id != id) {
            fwrite(&emp, sizeof(struct Employee), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (!found) {
        printf("Employee with id %d not found\n", id);
    } else {
        printf("Employee deleted successfully\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nEmployee Database Management\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
