#include "header.h"

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];

    char op[0];
    char st[1];
    char et[2];
    char ln[3];
    char p[4];
} message1;


//연산 -> 결과 출력
// InputOp 에서 받은 op 값으로 각 연산 호출
void ShowResult(LED_DATA a_data)
{
    // if(a_data.op==LED && a_data.op==TEMP && a_data.op==GPS )
    // if(a_data.op>=1 && a_data.op<=3 )
    if(strncmp(message1.op, "1", 1) == 0)
    {
        int result;

        if(a_data.op==1) result=LED(a_data);
        // else if(a_data.op==2) result=Minus(a_data);
        // else result=GPS(a_data);

        printf("End \n"); //결과 출력
    }
    else{printf("no operator \n");} // 값이 1~4 사이가 아니면 나옴
}


int main()
{
    int run=1;
    LED_DATA data;

    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    

    while(run==1)
    {     
        InputOp(&data);
        msgrcv(msgid, &message1, sizeof(message1), 1, 0);

        InputValue();

        ShowResult(data);

        printf("\nrun more?(0:stop / 1: run): \n");
        //rewind(stdin);
        scanf("%d", &run);
        if(run==0) break;
    }
    return 0;
}