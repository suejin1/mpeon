#include "header.h"

void Interval()
{
    int a=0;

    while (1)
    {
        sleep(data.patter*1);
        a+=1;

        printf("%d %d \n", data.patter, a);
    }
}

// 스레드 or 타이머
// 슬립으로 계속 보내기
// 시작 끝 시간도 있으니까 시간에 맞게 시작 끝으로 가능하게
// 끝 시간 지나가면 타이머 종료 시키기