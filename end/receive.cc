#include "header.h"

extern c_data data;
extern stIpcMsg msg;

void receive()
{
    data.key = ftok("progfile", 65);
    data.msgid = msgget(data.key, 0666 | IPC_CREAT);
    
    msgrcv(data.msgid, &msg, sizeof(msg)-sizeof(long), 0, 0);

    if(msg.opcode==1)
    {
        printf(" OP: %x  LN: %x  StartTime: %d  EndTime: %d  pattern: %x \n end \n", msg.opcode, msg.LN, msg.S, msg.E, msg.P);
        printf("-----------------------------------------------------\n\n");
    }
    else if(msg.opcode==2)
    {
        printf(" OP: %x  0  StartTime: %x  EndTime: %x  Interval: %x \n end \n", msg.opcode, msg.S, msg.E, msg.P);
        printf("-----------------------------------------------------\n\n");
    }
    else
    {
        printf(" OP: %x  0  StartTime: %x  EndTime: %x  Interval: %x \n end \n", msg.opcode, msg.S, msg.E, msg.P);
        printf("-----------------------------------------------------\n\n");
    }
}