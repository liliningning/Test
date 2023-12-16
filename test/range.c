/* 买卖 求怎么获取最大的利润  就相当于用最大的值减去最小的值*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIEZE 7
#define BUFFER_SIEZE1 30

#if 0
int getMax(int * newary,int newarysize )
{  
    int max = newary[0];
    for(int idx = 0 ;idx < newarysize; idx++ )
  {
    if(max < newary[idx])
    {
        max = newary[idx];
    }
  }

    return max;
}

#endif

int main()
{

    int array[BUFFER_SIEZE] = {7,1,3,5,6,4,2};
    int newary[BUFFER_SIEZE1] = { 0 };
    // int jdx=0;
    int temp = 0;    // 最大利润
    int num1 = 0;   //卖
    int num2 = 0;   //买
    for(int idx = 0; idx < BUFFER_SIEZE - 1;idx++)
    {
        for(int sell = idx+1; sell < BUFFER_SIEZE; sell++ )
        {
            /*判断最大值 并且将最大值 和 买的卖的天数输出*/
            if(temp  < (array[sell] - array[idx]))
            {
                temp = (array[sell] - array[idx]);
                num1 = sell + 1;
                num2 = idx + 1;
            }

            // newary[jdx] = (array[sell] - array[idx]);
            // jdx++;
        }
    }

  /*输出最大值*/  
#if 0
    for(int idx =0; idx < BUFFER_SIEZE1; idx++)
    {
         printf("%d\n",newary[idx]);


    }
   
   int max = getMax(newary,BUFFER_SIEZE1);
   printf("max: %d\n",max);
#endif

printf("卖的天%d\t买的天%d\t, 最大的利润：%d\n",num1,num2,temp);


    return 0;

}