//Calc.c
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
} message;


int LED(LED_DATA a_data)
{   
    key_t key;
    int msgid;

    int mesg_type;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);


    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Data Received is : %s \n",  message.ln);
    //msgctl(msgid, IPC_RMID, NULL);

    if(strncmp(message.ln, "1", 1) == 0)
    {
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("START TIME is: %s \n", message.mesg_text);
       
        if(strncmp(message.et, "1", 1) == 0)
        {
            int mesg_type = 1;

            msgrcv(msgid, &message, sizeof(message), 1, 0);
            printf("END TIME is: %s \n", message.mesg_text);

            #pragma region LED 1
            if(strncmp(message.ln, "1", 1) == 0)
            {
                msgrcv(msgid, &message, sizeof(message), -5, 0);
                printf("LED NUM is: %s \n", message.mesg_text);
                
                if(strncmp(message.ln, "1", 1) == 0)
                {
                    printf("Pattern 1 Start \n");
                }
                else if(strncmp(message.mesg_text, "2", 1) == 0)
                {
                    printf("Pattern 2 Start \n");
                }
                else if(strncmp(message.mesg_text, "3", 1) == 0)
                {
                    printf("Pattern 3 Start \n");
                }
                else{printf("Pattern Error \n");}
            }
     
        }
        else{printf("End Time Error \n");}
    }

    else{printf("Start Time Error \n");}

    return 0;

}
