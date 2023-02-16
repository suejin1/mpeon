#include "header.h"

extern c_data data;
extern stIpcMsg msg;

void exmaple()
{
    data.timer = time(NULL);
    data.t = localtime(&data.timer);

    printf("┌──────────────────────────────────────────────────────┐\n│");
    printf("현재 시간 : %d시 %d분 %d초                            │\n│", data.t->tm_hour, data.t->tm_min, data.t->tm_sec);

    printf("모든 시간은 1초 단위입니다.                           │\n│");
    printf("LED :  1  LedNum  StartTime  EndTime     patter       │\n│");
    printf("     ( 1   1~5      free      free        1~3       ) │\n│");
    printf("                                                      │\n│");
    printf("TEMP : 2    0     StartTime  EndTime    Interval      │\n│");
    printf("     ( 2    0       free      free        free      ) │\n│");
    printf("                                                      │\n│");
    printf("GPS :  3    0     StartTime  EndTime    Interval      │\n│");
    printf("     ( 3    0       free      free        free      ) │\n│");
    printf("                                                      │\n│");

    printf("띄어쓰기 없이 입력해주세요.                           │\n");
    printf("│10초 내에 입력되지 않을 경우 종료됩니다.              │\n");
    printf("└──────────────────────────────────────────────────────┘\n");
}
