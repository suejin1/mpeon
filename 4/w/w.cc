#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS // 혹은 localtime_s를 사용
#include <iostream>
#include <memory.h>
#include <time.h>

#define MAX 10

using namespace std;

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
    char perID[7]; //6 + NULL = 7;
    char name[10];
} message1;

int main(void)
{
    char buf[1024];

    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("progfile", 65);
  
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    message1.mesg_type = 1;

    // char perID[7]; //6 + NULL = 7;
    // char name[10];

    printf("주민번호 앞 6 자리를 입력하세요.");
    // fgets(perID, sizeof(perID), stdin);
    fgets(message1.perID,MAX,stdin);
    msgsnd(msgid, &message1, sizeof(message1), 0);
 
    // fflush(stdin);
 
    printf("이름을 입력하세요.");
    // fgets(name, sizeof(name), stdin);
    fgets(message1.name,MAX,stdin);

    msgsnd(msgid, &message1, sizeof(message1), 0);

}