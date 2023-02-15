#include "header.h"

#define MAX 20

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];

    char op[0];
    char st[1];
    char et[2];
    char ln[3];
    char p[4];
} message2;

//정수값 2개 입력 받기
void InputValue()
{
    key_t key;
    int msgid;

    msgctl(msgid, IPC_RMID, NULL);

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    message2.mesg_type = 1;

    printf("input data (Starttime Endtime Lednum Pattern) : ");
    fgets(message2.mesg_text,MAX,stdin);

    msgsnd(msgid, &message2, sizeof(message2), 0);
    msgsnd(msgid, &message2, sizeof(message2), 0);
    msgsnd(msgid, &message2, sizeof(message2), 0);
    msgsnd(msgid, &message2, sizeof(message2), 0);
    //msgctl(msgid, IPC_RMID, NULL);
}

//연산자 입력 받기 -> ShowResult 로 연결
void InputOp(LED_DATA *ap_data)
{
    key_t key;
    int msgid;

    msgctl(msgid, IPC_RMID, NULL);

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    message2.mesg_type = 1;

    printf("(1: LED / 2: TEMP / 3: GPS)\n");
    printf("choose(ex 1): ");
    // scanf("%d", &ap_data->op);

    fgets(message2.op,MAX,stdin);
    
    msgsnd(msgid, &message2, sizeof(message2), 0);
}