#include<stdio.h>
struct Employee{
    char name[50];
    char department[50];
    int id;
    long int salary;
} typedef Employee;

void printRecord(Employee record[], int n){
    for(int i = 0; i<n; ++i){
        printf("%d %10s %10s %10ld\n", 
        record[i].id, record[i].name, record[i].department, record[i].salary);
    }
}

void inputRecord(Employee record[], int n){
    for(int i = 0; i<n; ++i){
        printf("enter the id, name, department, salary: ");
        scanf("%d %s %s %ld", 
        &record[i].id, &record[i].name, &record[i].department, &record[i].salary);
    }
}

int main(){
    int n;
    printf("enter the size of record: ");
    scanf("%d", &n);
    Employee record[n];
    inputRecord(record, n);
    printRecord(record, n);
    return 0;
}