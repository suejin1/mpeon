#include "header.h"

extern c_data data;
extern stIpcMsg msg;

void input()
{
    printf(" input : ");
    scanf("%1d %1d %1d %1d %1d", &data.opcode, &data.LedNum, &data.StartTime, &data.EndTime, &data.patter);
// %*d
    printf(" wait %d \n", data.StartTime*1);

    sleep(data.StartTime*1);
}