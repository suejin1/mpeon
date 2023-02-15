#include "header.h"

extern c_data data;
extern stIpcMsg msg;

void input()
{
    data.key = ftok("progfile", 65);
    data.msgid = msgget(data.key, 0666 | IPC_CREAT);

    printf(" input : ");
    scanf("%1d %1d %1d %1d %1d %*d", &data.opcode, &data.LedNum, &data.StartTime, &data.EndTime, &data.patter);

    printf(" wait %d \n", data.StartTime*1);

    sleep(data.StartTime*1);
    printf("input end");
}