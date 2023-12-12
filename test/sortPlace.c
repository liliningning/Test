/* 列出一个数组 并且删掉重复值 再进行排序*/

#include <stdio.h>
#define BUFFER_SIEZ 10

int main()
{
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

    return 0;
}