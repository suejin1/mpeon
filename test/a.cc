#include "header.h"

void * sned_thread(void * param)
{
  c_data data;
  int limit = *(int *) param;

  for (data.i=1; data.i<=limit; data.i++) 
  {
    exmaple();
    input();
    send();
    ++data.target;
    sleep(1);
  }
}

void * receive_thread(void * param)
{
  c_data data;
  int limit = *(int *) param;

  for (data.i=1; data.i<=limit; data.i++) 
  {
    receive();
  }
}
 
int main()
{
  c_data data;
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
  printf("target : %d\n", data.target);
 
  return 0;
}