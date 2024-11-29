#include<stdio.h>
#include<string.h>
#define MAX_STUDENTS 100
struct Student
{
    char name[20];
    char course[10];
    int roll;
} typedef Student;

void insert(Student records[], int *n){
    if(*n >= MAX_STUDENTS){
        printf("Record is full can't add more students.\n");
        return;
    }

    printf("Enter roll no: ");
    scanf("%d", &records[*n].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", records[*n].name);

    printf("Enter Course: ");
    scanf(" %[^\n]", records[*n].course);

    (*n)++;
    printf("one record inserted successfully\n");
}

void display(Student records[], int n){
    for(int i = 0; i<n; ++i){
        printf("%d %s %s\n", records[i].roll, records[i].name, records[i].course);
    }
}

void delete(Student records[], int *n){
    int roll;
    printf("Enter roll no of student to delete: ");
    scanf("%d", &roll);

    int isFound = 0, i , j;
    for(i = 0; i<*n; ++i){
        if(records[i].roll == roll){
            isFound = 1;
            break;
        }
    }

    if(!isFound){
        printf("student with %d roll not no found\n");
        return;
    }

    for(j = i; j < (*n) - 1; j++){
        records[j] = records[j+1];
    }
    (*n)--;
    printf("student with %d roll no deleted.\n");
}

void search(Student records[], int n){
    int roll;
    printf("Enter roll no of student to delete: ");
    scanf("%d", &roll);

    int isFound = 0, i , j;
    for(i = 0; i<n; ++i){
        if(records[i].roll == roll){
            isFound = 1;
            break;
        }
    }

    if(!isFound){
        printf("student with %d roll not no found\n");
        return;
    }

    printf("%d %s %s\n", records[i].roll, records[i].name, records[i].course);
}

int main(){

    Student records[MAX_STUDENTS];
    int n = 0;
    int choice;

    do{
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(records, &n); break;
            case 2: display(records, n); break;
            case 3: delete(records, &n); break;
            case 4: search(records, n);  break;
            default: printf("Invalid choice\n"); break;
        }

    }while(choice != 5);
    
    return 0;
}