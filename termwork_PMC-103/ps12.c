#include <stdio.h>

typedef struct {
    char name[50];
    char department[50];
    int eid;
    float salary;
    int age;
} Employee;

int main() {
    FILE *file;
    Employee emp = {"Gagandeep", "Engineering", 101, 60000.00, 30};

    // Write to the file
    file = fopen("C:\\users\\abhij\\desktop\\Emp.dat", "wb");
    if (file == NULL) {
        printf("Unable to open file in write mode\n");
        return 0;
    }
    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);

    // Read from the file
    file = fopen("C:\\users\\abhij\\desktop\\Emp.dat", "rb");
    if (file == NULL) {
        printf("Unable to open file in read mode\n");
        return 0;
    }
    fread(&emp, sizeof(Employee), 1, file);
    fclose(file);

    printf("Name: %s\nDepartment: %s\nEid: %d\nSalary: %.2f\nAge: %d\n",
           emp.name, emp.department, emp.eid, emp.salary, emp.age);

    return 0;
}
