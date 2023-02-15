#include "header.h"

void exmaple()
{
    c_data data;

    data.timer = time(NULL);
    data.t = localtime(&data.timer);

    // printf("-----------------------------------------------------\n\n");
    printf("┌──────────────────────────────────────────────────────┐\n│");
    printf("현재 시간 : %d시 %d분 %d초                             │\n│", data.t->tm_hour, data.t->tm_min, data.t->tm_sec);

    printf("모든 시간은 1초 단위입니다.                           │\n│");
    printf("LED :  1  LedNum  StartTime  EndTime     patter    0  │\n│");
    printf("     ( 1   1~5      free      free        1~3      0) │\n│");
    printf("                                                      │\n│");
    printf("TEMP : 2    0     StartTime  EndTime    Intervla   0  │\n│");
    printf("     ( 2    0       free      free        free     0) │\n│");
    printf("                                                      │\n│");
    printf("GPS :  3    0     StartTime  EndTime    Intervla   0  │\n│");
    printf("     ( 3    0       free      free        free     0) │\n│");
    printf("                                                      │\n│");

    printf("띄어쓰기 없이 입력해주세요.                           │\n");
    //printf("                                                      │\n");
    printf("└──────────────────────────────────────────────────────┘\n");
}

//  ─   │  ┌  ┐  └  ┘ 