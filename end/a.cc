#include "header.h"

c_data data;
stIpcMsg msg;
stmq mq;
sttime timer;

void * sned_thread(void * param)
{
  memset(&data, 0, sizeof(c_data));
  exmaple();
  input();
  send();
}

void * receive_thread(void * param)
{
  receive();
  exit(1);
}
 
int main()
{
  pthread_t add, sub;
  int param = 1;
  
  int add_id = pthread_create(&add, NULL, sned_thread, &param);
  if (add_id < 0)
  {
    perror("thread create error : ");
  }
  pthread_join(add, NULL);

  int sub_id = pthread_create(&sub, NULL, receive_thread, &param);
  if (sub_id < 0)
  {
    perror("thread create error : ");
  }
  pthread_join(sub, NULL);

  return 0;
}