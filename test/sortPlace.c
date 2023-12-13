/* 列出一个数组 并且删掉重复值 再进行排序*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// #define BUFFER_SIEZ 10

int main()
{
#if 0
    /*与targent相同的次数*/
    int num = 0;
    int len = BUFFER_SIEZ;
    int array[BUFFER_SIEZ] = {1, 3, 4, 5, 3, 6, 7, 8, 6, 6};
    int targent = 6;
    for (int idx = 0; idx < len; idx++)
    {

        /*判断两个数是否相等*/
        if (array[idx] == targent)
        {
            /*次数每次加一*/
            num++;
        }
        /*将后面的值赋给前面*/
        array[idx + 1 - num] = array[idx + 1];
    }
    /*长度减重复的次数*/
    len -= num;

    for (int idx = 0; idx < len; idx++)
    {
        printf("%d\n", array[idx]);
    }
#endif

#if 1
    /*数组的大小*/
    int len;
    printf("输入数组元素的个数: \n");
    scanf("%d", &len);

    int array[len];
    /*随机数初始化*/
    int idx = 0;
    /*数组里面的数与targent相同的次数*/
    int num = 0;

    /* 输入targent的值*/
    int targent = 0;
    printf("targent: \n");
    scanf("%d", &targent);
    printf("\n");

    srand(time(NULL));
    for (idx = 0; idx < len; idx++)
    {
        array[idx] = rand() % 10 + 1;
    }
    for (int jdx = 0; jdx < len; jdx++)
    {
        /*判断两个数是否相等*/
        if (array[jdx] == targent)
        {
            /*次数每次加一*/
            num++;
        }
        /*将后面的值赋给前面*/
        array[jdx + 1 - num] = array[jdx + 1];
    }
    /*长度减重复的次数*/
    len -= num;
    for (idx = 0; idx < len; idx++)
    {
        printf("%d\n ", array[idx]);
    }
#endif
    return 0;
}