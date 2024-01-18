#include <stdio.h>
#include <stdlib.h>

int findTargntFrequencyMost(int * nums, int numsSize, int *frequentNum, int *frequentVal)
{

    /* 记录每个数出现的次数 */
    int array[100] = { 0 };

    /* 记录出现最多的那个数的次数  */
    int max = 0;
    for(int idx = 0; idx < numsSize; idx++)
    {
        array[nums[idx]]++;
    }
    for(int idx = 0; idx < 100; idx++)
    {
        if(idx > max)
        {
            idx = max;
        }
    }

    if(frequentNum != NULL)
    {
        *frequentNum = max;
    }
    if(frequentVal != NULL)
    {
        *frequentVal = array[max];
    }
    

}

