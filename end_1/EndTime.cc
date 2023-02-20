#include "header.h"

void EndTime()
{
    int a=0;

    while (1)
    {
        sleep(1);
        timer.EndTime-=1;
        a++;

        printf("%d  \n", a);

        if(timer.EndTime<=0)
        {
        printf("end Time \n");
        exit(1);
        }
    }
}

void end()
{

    clock_t start = clock();
    
    clock_t end = clock();

    //start=(clock_t)timer.StartTime;
    //end=(clock_t)timer.EndTime;

    int second = 0;
    // cout<<"초를 입력해 주세요: ";
    //timer.EndTime>>second;
    
    
    while (true) 
    {
        end = clock();
            
        if (int(end - start) / CLOCKS_PER_SEC == timer.EndTime) 
        {
        break;
        }
    }
    
    printf("끄읕!\n");
}