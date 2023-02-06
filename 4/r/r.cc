#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS // 혹은 localtime_s를 사용
#include <iostream>
#include <memory.h>
#include <time.h>

using namespace std;

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
    char perID[7]; //6 + NULL = 7;
    char name[10];
} message;

int main(void)
{
    
    char buf[1024];

    //memset(buf, 0x00, 1024);

    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("progfile", 65);
  
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // char perID[7]; //6 + NULL = 7;
    // char name[10];

    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("ID: %s \n", message.perID); //st

    if(strncmp(message.perID, "11111", 5) == 0)
    {
        printf(" perID ok \n");
    }

    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("name: %s \n", message.name); //st

    if(strncmp(message.name, "1", 1) == 0)
    {
        printf(" name ok \n");
    }
       
}