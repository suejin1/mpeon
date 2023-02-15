
// http://www.hipenpal.com/tool/binary-octal-decimal-hexadecimal-number-converter-in-korean.php
#include "header.h"

using namespace std;

    // struct mesg_buffer 
    // {
    // long mesg_type;
    // char mesg_text[100];
    // } message;  

void message::ALL()
{
    ALL_char();
    ALL_int();
    LED_buf();
    TEMP_buf();
    GPS_int();
    GPS_double();
}

//공통
void message::ALL_char()
{ 
    char buf [1024];

    buf [0]=0x01; //opcode

    buf [19]=0x1b; //interval

}

void message::void ALL_int()
{ 
    int buf [1024];

    //start time int 8 
    buf [1]=0x09;
    buf [2]=0xA; //10
    buf [3]=0xb;
    buf [4]=0xc;
    buf [5]=0xd;
    buf [6]=0xe;
    buf [7]=0xf; //정수 16진수 비트 연산
    buf [8]=0x10;

    //end time int 8 
    buf [9]=0x11; //17
    buf [10]=0x12;
    buf [11]=0x13;
    buf [12]=0x14;
    buf [14]=0x15;
    buf [15]=0x16;
    buf [16]=0x17;
    buf [17]=0x18;

    buf [18]=0x1a; //error code //26

}

//LED
void message::LED_buf()
{ 
    char buf [1024];

    //lednum 1-5
    buf [20]=0x04; 
    buf [21]=0x05;
    buf [22]=0x06;
    buf [23]=0x07;
    buf [24]=0x08;

    //pattern
    buf [25]=0x19; 
}

//temp
void message::TEMP_buf()
{
    int buf [1024];

    //now temp
    buf [26]=0x1c;
}

void message::GPS_int()
{
    int buf [1024];

    buf [27]=0x1f; //현재 시간 초
    buf [28]=0x20; //나노초
}

void message::GPS_double()
{
    double buf [1024];

    buf [29]=0x1d; //위도
    buf [30]=0x1e; //경도 //30
}