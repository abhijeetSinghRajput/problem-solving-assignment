#include<stdio.h>
struct Student
{
    char name[20];
    char course[10];
    int roll;
} typedef Student;

int main(){
    
    while(1){
        char choice = getch();
        switch (choice)
        {
            case '1': printf("1\n"); break;
            case '2': printf("2\n"); break;
            case '3': printf("3\n"); break;
            case '4': printf("4\n"); break;
            default : printf("default\n"); break;
        }
    }
    return 0;
}