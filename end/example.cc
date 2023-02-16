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
    printf("StartTime : 입력한 만큼 대기 후 동작을 시작합니다.    │\n│");
    printf("EndTime : 입력한 만큼 대기 후 동작을 종료합니다.      │\n│");
    printf("Interval : 입력한 주기로 정보를 받아옵니다.           │\n│");
    printf("띄어쓰기 없이 입력해주세요.                           │\n");
    printf("└──────────────────────────────────────────────────────┘\n");
}
