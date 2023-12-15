/* 买卖 求最大的利润  就相当于用最大的值减去最小的值*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIEZE 7
#define BUFFER_SIEZE1 30

int main()
{

    int array[BUFFER_SIEZE] = {7,1,3,5,6,4,2};
    int new[BUFFER_SIEZE1] = { 0 };
    // int *ptr = NULL;
    int jdx=0;
    // memset(ptr, 0, sizeof(array)*3);

    for(int idx = 0; idx < BUFFER_SIEZE - 1;idx++)
    {
        for(int sell = idx+1; sell < BUFFER_SIEZE; sell++ )
        {
            new[kdx] = (array[sell] - array[idx]);
            jdx++;
        }
    }
    for(int idx =0; idx < BUFFER_SIEZE1; idx++)
    {
         printf("%d\n",new[idx]);

    }
   





    return 0;

}