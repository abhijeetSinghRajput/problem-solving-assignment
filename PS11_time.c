#include <stdio.h>
struct Time{
    int hour;
    int minut;
    int second;
};

void input(struct Time *time){
    printf("enter hh:mm:ss ");
    scanf("%d %d %d", &time->hour, &time->minut, &time->second);
}

void output(struct Time *time){
    printf("%02d:%02d:%02d\n", time->hour, time->minut, time->second);
}

struct Time sum(struct Time *t1, struct Time *t2){
    struct Time result;

    result.second = (t1->second + t2->second);
    result.minut = (t1->minut + t2->minut)  + (result.second / 60);
    result.hour = (t1->hour + t2->hour) + (result.minut / 60);

    result.second %= 60;
    result.minut %= 60;
    result.hour %= 60;

    return result;
}
// 12:45:30 
// 03:20:45
// --------
// 16:06:15

int main(){
    struct Time t1, t2, t3;
    input(&t1);
    input(&t2);
    t3 = sum(&t1, &t2);

    output(&t1);
    output(&t2);
    output(&t3);
}