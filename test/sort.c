/* 输入一个乱序的数组 然后将其进行递增排序后输出*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIEZ 6

int main()
{
    int num = 0;
    int array[BUFFER_SIEZ] = {1, 4, 3, 2, 5, 6};
    
    /*控制交换的轮数*/
    for (int idx = 0; idx < BUFFER_SIEZ; idx++) 
    {
        /*控制前后交换*/
        for (int jdx = 0; jdx < BUFFER_SIEZ - 1 - idx; jdx++) 
        {
            if (array[jdx] > array[jdx + 1])
            {
                num = array[jdx];
                array[jdx] = array[jdx + 1];
                array[jdx + 1] = num;
            }
        }
    }

    for (int idx = 0; idx < BUFFER_SIEZ; idx++)
    {
        printf("%d\n", array[idx]);
    }
    return 0;
    
}