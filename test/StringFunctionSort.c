/*合并两个递增的非连续的有序数组 开辟一个新的数组并且按照递增排序*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIEZ 5

#if 0
int bubbleSort(int *num1,int *BUFFER_SIEZ)
{
    int num = 0;
    for (int idx = 0; idx < *BUFFER_SIEZ; idx++)
    {
        /*控制前后交换*/
        for (int jdx = 0; jdx < *BUFFER_SIEZ - 1 - idx; jdx++)
        {
            if (num1[jdx] > num1[jdx + 1])
            {
                num = num1[jdx];
                num1[jdx] = num1[jdx + 1];
                num1[jdx + 1] = num;
            }
        }
    }
}
#endif

#if 0
int *mer_strcat(int *num1, int *num2, int num1size, int num2size, int *num3size)
{
  
    int *num3 = (int *)malloc(sizeof(int) * (*num3size));
    memset(num3, 0,sizeof(num3));
    int idx = 0;
    for (idx = 0; idx < *num3size; idx++)
    {
        if (idx < num1size)
        {
            num3[idx] = num1[idx];
        }
        else
        {
            num3[idx] = num2[idx - 5];
        }
    }
    bubbleSort(num3, num3size);
    for (int idx = 0; idx < 10; idx++)
    {
        printf("%d ", num3[idx]);
    }
    printf("\n");
}

#endif

int *mer_strcat(int *num1, int *num2, int num1size, int num2size, int *num3size)
{
    /*为mun3 动态开辟一个空间*/
    int *num3 = (int *)malloc(sizeof(int) * (*num3size));
    memset(num3, 0, sizeof(num3));
    int idx = 0; //num1的下标
    int jdx = 0; //num2的下标
    int sub = 0; //num3的下标

    while (idx < num1size && jdx < num2size)
    {
        if (num1[idx] < num2[jdx])
        {
            num3[sub] = num1[idx];
            sub++;
            idx++;
        }
        else
        {
            num3[sub] = num2[jdx];
            sub++;
            jdx++;
        }
    }
    while (idx == num1size && jdx < num2size)   //判断num2是否还有值没有输出到num3里面
    {
        num3[sub] = num2[jdx];
        sub++;
        jdx++;
    }

    while (jdx == num2size && idx < num1size)   //判断num2是否还有值没有输出到num3里面
    {
        num3[sub] = num1[idx];
        sub++;
        idx++;
    }

    for (int idx = 0; idx < 10; idx++)
    {
        printf("%d ", num3[idx]);
    }
    printf("\n");
    free(num3);
}

int main()
{
#if 1
    int num1[BUFFER_SIEZ] = {2, 3, 4, 5, 6};
    int num2[BUFFER_SIEZ] = {1, 1, 7, 8, 9};
    int num3size = (sizeof(num1) / 4) + (sizeof(num2) / 4);
    int *array = mer_strcat(num1, num2, sizeof(num1) / 4, sizeof(num2) / 4, &num3size);
#endif

    return 0;
}