#include <stdio.h>

int Time(int h, int m, int s);

int main(){
    int hour, minute, second, left;
    printf("Enter the time\n");
    scanf("%d%*c%d%*c%d", &hour, &minute, &second);
    left=Time(hour,minute,second);
    printf("There are %d seconds left until 12 o'clock\n", left);
    return 0;
}

int Time(int h, int m, int s){ // h is used for the hour, m for the minutes, s for the seconds
    int seconds=0;
    if(h<11)
        seconds+=(11-h)*3600;
    if(m<59)
        seconds+=(59-m)*60;
    seconds+=(60-s);
    return seconds;
}
