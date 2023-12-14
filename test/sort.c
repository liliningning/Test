/* 输入一个乱序的数组 然后将其进行递增排序后输出   冒泡排序*/ 

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// #define BUFFER_SIEZ 6

int main()
{
#if 0
    /*前后交换中间值*/
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


#endif

#if 1

    int num = 0;
    int len;
    printf("数组的长度：");
    scanf("%d", &len);

    int array[len];
    printf("输入的数组：");
    for (int idx = 0; idx < len; idx++)
    {
        scanf("%d", array + idx);
    }
    for (int idx = 0; idx < len; idx++)
    {
        /*控制前后交换*/
        for (int jdx = 0; jdx < len - 1 - idx; jdx++)
        {
           
            if (array[jdx] > array[jdx + 1])
            {
                num = array[jdx];
                array[jdx] = array[jdx + 1];
                array[jdx + 1] = num;
            }
        }
    }

    for (int idx = 0; idx < len; idx++)
    {
        printf("%d\n", array[idx]);
    }

#endif
    return 0;

}