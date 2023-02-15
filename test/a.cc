#include "header.h"

c_data data;
stIpcMsg msg;

void * sned_thread(void * param)
{
  int limit = *(int *) param;

  exmaple();
  input();
  send();
  sleep(1);
}

void * receive_thread(void * param)
{
  int limit = *(int *) param;

  receive();
}
 
int main()
{
  pthread_t add, sub;
  int param = 100;
  
  int add_id = pthread_create(&add, NULL, sned_thread, &param);
  if (add_id < 0)
  {
    perror("thread create error : ");
    exit(0);
  }
  
  int sub_id = pthread_create(&sub, NULL, receive_thread, &param);
  if (sub_id < 0)
  {
    perror("thread create error : ");
    exit(0);
  }
 
  sleep(3000);
 
  return 0;
}