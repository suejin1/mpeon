#include "header.h"

void input()
{
    // clock_t start = clock();
    
    // clock_t end = clock();

    printf(" input : ");
    scanf("%1c %1c %d %d %1c", &data.opcode1, &data.LedNum1, &timer.StartTime, &timer.EndTime, &data.patter1);

    data.opcode=data.opcode1 - '0';
    data.LedNum=data.LedNum1 - '0';
    data.patter=data.patter1 - '0';

    // timer.StartTime=data.opcode1 - '0';
    // data.LedNum=data.LedNum1 - '0';
    // data.patter=data.patter1 - '0';

    printf(" wait %d \n", timer.StartTime*1);

    sleep(timer.StartTime*1);
}