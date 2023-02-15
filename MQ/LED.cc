// //Calc.c
// #include "header.h"
// //Starttime Endtime Lednum Pattern

// // class LED{
// //     public:



// // };

// #define MAX 20


// // struct kid_buffer {
// //     key_t key;
// //     int msgid;

// // };

// struct mesg_buffer {
//     long mesg_type;
//     char mesg_text[100];
// } message;


// // void read_buffer3()
// // {
// //     msgrcv(msgid, &message, sizeof(message), 1, 0);
// //     printf("START TIME: %s \n", message.mesg_text);
// // }


// int LED(LED_DATA a_data)
// {   
//     key_t key;
//     int msgid;

//     int mesg_type;

//     key = ftok("progfile", 65);
//     msgid = msgget(key, 0666 | IPC_CREAT);

//     msgrcv(msgid, &message, sizeof(message), 1, 0);
//     printf("Data Received is : %s \n", message.mesg_text);
//     //msgctl(msgid, IPC_RMID, NULL);

//     if(strncmp(message.mesg_text, "1", 1) == 0)
//     {
//         msgrcv(msgid, &message, sizeof(message), 1, 0);
//         printf("START TIME is: %s \n", message.mesg_text);
       
//         if(strncmp(message.mesg_text, "1", 1) == 0)
//         {
//             int mesg_type = 1;

//             msgrcv(msgid, &message, sizeof(message), 1, 0);
//             printf("END TIME is: %s \n", message.mesg_text);

//             #pragma region LED 1
//             if(strncmp(message.mesg_text, "1", 1) == 0)
//             {
//                 msgrcv(msgid, &message, sizeof(message), -5, 0);
//                 printf("LED NUM is: %s \n", message.mesg_text);
                
//                 if(strncmp(message.mesg_text, "1", 1) == 0)
//                 {
//                     printf("Pattern 1 Start \n");
//                 }
//                 else if(strncmp(message.mesg_text, "2", 1) == 0)
//                 {
//                     printf("Pattern 2 Start \n");
//                 }
//                 else if(strncmp(message.mesg_text, "3", 1) == 0)
//                 {
//                     printf("Pattern 3 Start \n");
//                 }
//                 else{printf("Pattern Error \n");}
//             }
//             // #pragma endregion
//             // #pragma region LED 2
//             // else if(a_data.c==2)
//             // {
//             //     printf("LED NUM is: 2 \n");
//             //     if(a_data.d==1)
//             //     {
//             //         printf("Pattern 1 Start \n");
//             //     }
//             //     else if(a_data.d==2)
//             //     {
//             //         printf("Pattern 2 Start \n");
//             //     }
//             //     else if(a_data.d==3)
//             //     {
//             //         printf("Pattern 3 Start \n");
//             //     }
//             //     else{printf("Pattern Error \n");}
//             // }
//             // #pragma endregion
//             // #pragma region LED 3
//             // else if(a_data.c==3)
//             // {
//             //     printf("LED NUM is: 2 \n");
//             //     if(a_data.d==1)
//             //     {
//             //         printf("Pattern 1 Start \n");
//             //     }
//             //     else if(a_data.d==2)
//             //     {
//             //         printf("Pattern 2 Start \n");
//             //     }
//             //     else if(a_data.d==3)
//             //     {
//             //         printf("Pattern 3 Start \n");
//             //     }
//             //     else{printf("Pattern Error \n");}
//             // }
//             // #pragma endregion
//             // #pragma region LED 4
//             // else if(a_data.c==4)
//             // {
//             //     printf("LED NUM is: 2 \n");
//             //     if(a_data.d==1)
//             //     {
//             //         printf("Pattern 1 Start \n");
//             //     }
//             //     else if(a_data.d==2)
//             //     {
//             //         printf("Pattern 2 Start \n");
//             //     }
//             //     else if(a_data.d==3)
//             //     {
//             //         printf("Pattern 3 Start \n");
//             //     }
//             //     else{printf("Pattern Error \n");}
//             // }
//             // #pragma endregion
//             // #pragma region LED 5
//             // else if(a_data.c==5)
//             // {
//             //     printf("LED NUM is: 2 \n");
//             //     if(a_data.d==1)
//             //     {
//             //         printf("Pattern 1 Start \n");
//             //     else if(a_data.d==3)
//             //     {
//             //         printf("Pattern 3 Start \n");
//             //     }
//             //     else{printf("Pattern Error \n");}
//             // }
//             // #pragma endregion       //     }
//             //     else if(a_data.d==2)
//             //     {
//             //         printf("Pattern 2 Start \n");
//             //     }
     


//             // else{("Led Num Error \n");}
//         }
//         else{printf("End Time Error \n");}
//     }

//     else{printf("Start Time Error \n");}

//     return 0;

// }
