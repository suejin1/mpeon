#include "header.h"

extern c_data data;
extern stIpcMsg msg;

bool checkDate(OP op, LN ln, P p);

void send()
{
  data.key = ftok("progfile", 65);
  data.msgid = msgget(data.key, 0666 | IPC_CREAT);

  bool result = checkDate((OP)data.opcode, (LN)data.LedNum, (P)data.patter);
  
  if(result==true) 
  {
    msg.mtype = 1;
    msg.opcode=(uint32_t) data.opcode;
    msg.LN=(uint32_t) data.LedNum;
    msg.P=(uint32_t) data.patter;
    msg.S=(uint32_t) data.StartTime;
    msg.E=(uint32_t) data.EndTime;

    msgsnd(data.msgid, &msg, sizeof(msg)-sizeof(long), 0);
  }
  else 
  {
    printf(" error \n");
  }
}