#include <stdio.h>
int main(){
    // taking the input
    int sub1Marks, sub2Marks, sub3Marks;
    printf("enter the masks of all three subjects: ");
    scanf("%d %d %d", &sub1Marks, &sub2Marks, &sub3Marks);

    //calculating the percentage
    const int TOTAL_MARKS = 300;
    const long int SEM_FEE = 125000;

    int obtained = sub1Marks + sub2Marks + sub3Marks;
    float percentage = (float)obtained / TOTAL_MARKS * 100;
    int scholarship = 0;

    if(percentage < 50) scholarship = 0;
    else if(percentage < 61) scholarship = 5;
    else if(percentage < 75) scholarship = 20;
    else if(percentage < 85) scholarship = 30;
    else scholarship = 50;

    long int discount = SEM_FEE * scholarship / 100;
    long int payableAmount = SEM_FEE - discount;

    printf("Obtained Marks: %d\n", obtained);
    printf("Your Percentage %f%%\n", percentage);
    printf("Your Semester Fee is : %lld\n", SEM_FEE);
    printf("Your Scholarship is : %d%%\n", scholarship);
    printf("You Got Discount of : %lld%\n", discount);
    printf("Your Net Payable Ammount : %lld%\n", payableAmount);

    return 0;
}
