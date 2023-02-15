#include "header.h"

void input()
{
    c_data data;
    stIpcMsg msg;

    data.key = ftok("progfile", 65);
    data.msgid = msgget(data.key, 0666 | IPC_CREAT);

    printf(" input : ");
    scanf("%1d %1d %1d %1d %1d %*d", &data.a, &data.b, &data.t1, &data.t2, &data.c);

    printf(" wait %d \n", data.t1*1);

    sleep(data.t1*1);
}
// msgctl >>삭제 비우는거 찾기
// 현재 차있는 큐 수를 받아서 다 비우기