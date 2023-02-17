#include "header.h"

bool checkDate(OP op, LN ln, P p);

void send()
{
  mq.key = ftok("progfile", 65);
  mq.msgid = msgget(mq.key, 0666 | IPC_CREAT);

  bool result = checkDate((OP)data.opcode, (LN)data.LedNum, (P)data.patter);
  
  if(result==true) 
  {
    msg.mtype = 1;
    msg.opcode=(uint32_t) data.opcode;
    msg.LN=(uint32_t) data.LedNum;
    msg.P=(uint32_t) data.patter;
    msg.S=(uint32_t) timer.StartTime;
    msg.E=(uint32_t) timer.EndTime;

    msgsnd(mq.msgid, &msg, sizeof(msg)-sizeof(long), 0);
  }
  else 
  {
    printf(" error \n");
    exit(1);
  }
}