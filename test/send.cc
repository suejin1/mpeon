#include "header.h"

bool checkDate(OP op, LN ln, P p);

void send()
{
  c_data data;
  stIpcMsg msg;

  data.key = ftok("progfile", 65);
  data.msgid = msgget(data.key, 0666 | IPC_CREAT);

  enum OP op=(OP)data.a;
  enum LN ln=(LN)data.b;
  enum P p=(P)data.c;
  enum Time S=(Time)data.t1;
  enum Time E=(Time)data.t2;

  bool result = checkDate(op, ln, p);

  if(result==true) 
  {
    msg.mtype = 1;
    msg.opcode=(uint32_t) data.a;
    msg.LN=(uint32_t) data.b;
    msg.P=(uint32_t) data.c;
    msg.S=(uint32_t) data.t1;
    msg.E=(uint32_t) data.t2;

    msgsnd(data.msgid, &msg, sizeof(msg)-sizeof(long), 0);
  }
  else 
  {
    printf(" error \n");
    exit(0);
  }
}