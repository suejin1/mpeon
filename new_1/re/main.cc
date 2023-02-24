#include "header.h"
#include "tempfunc.h"
c_data data;
stIpcMsg msg;
stmq mq;
stmq2 mq2;
sttime timer;
temperature temp;
stIpcMsg2 msg2;
#define RECV_MSGQ_KEY 0x99999901
#define SEND_MSGQ_KEY 0x99999902

int counter=1;

void * receive_thread(void * param) // 받는 스레드
{
  int msize=0;
  int limit = *(int *) param;

  mq.key = ftok("progfile1", 65); // 키 번호
  mq.msgid = msgget(SEND_MSGQ_KEY, 0666 | IPC_CREAT); // 메시지 큐 id

  printf("%d %d\n", mq.msgid, mq2.msgid2);
  while (1)
  {
    //msgrcv(mq.msgid, &msg, sizeof(msg)-sizeof(long), 0, 0); // 메시지 큐 받기
    sleep(3);
    printf("3 sleep end \n");
     if((msize = msgrcv(mq.msgid, &msg, sizeof(msg)-sizeof(long), 0, 0)) < 0) {
            if(errno == EINTR)  
                continue;
            else {
                printf("Message receive err : %d %d\n", errno, mq.msgid);
                continue;
            }
        }

        sleep(4);
        printf("4 sleep end \n");

 printf(" OP: %x  LED Number: %x  StartTime: %d  EndTime: %d  pattern: %x \n", msg.opcode, msg.LN, msg.S, msg.E, msg.P);
      sleep(6);
        printf("6 sleep end \n");
 
  mq2.key2 = ftok("2", 64); // 키 번호
  mq2.msgid2 = msgget(RECV_MSGQ_KEY, 0666 | IPC_CREAT); // 메시지 큐 id
printf("%d %d\n", mq.msgid, mq2.msgid2);
    while(counter<=msg.E)
    {
      temp.Temp_Out();

      sleep(2);
      printf("2 sleep end");
      
      msg2.mtype = 1; // 메시지 타입(크기)
      msg2.Idata= (uint32_t)temp.value;

      printf("msg.Idata : %d \n", msg2.Idata);
      
      msgsnd(mq2.msgid2, &msg2, sizeof(msg2)-sizeof(long), IPC_CREAT); // 메시지 보내기
      counter+=msg.P;
      sleep(msg.E);
    }
    printf("afsdafsafsdfsafsdfasfasfsafsafddas \n");
    sleep(5);
    printf("5 sleep end\n");
  }
  return NULL;
}

int main()
{
  pthread_t add, sub; // 스레드 이름
  int param = 100;

  int sub_id = pthread_create(&sub, NULL, receive_thread, &param); // 보내는 스레드 끝나면 받는 스레드 생성
  if (sub_id < 0) // 받는 스레드 생성 안 됐을 경우 오류
  {
    perror("thread create error : ");
  }

  pthread_join(sub, NULL); //받는 스레드 끝날 때까지 대기

  // msgctl(mq.msgid, IPC_RMID, NULL); 
  
  return 0;
}