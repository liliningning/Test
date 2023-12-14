#include <stdio.h>
#include <string.h>
int main()
{
    /*数组的长度*/
    int len;
    printf("数组的长度：");
    scanf("%d", &len);
    /* 逆序后的数组*/
    char invert[len];
    /*消除标准输入缓冲区*/
    getc(stdin);
    /*初始的数组*/
    char array[len];
    printf("array:");
    fgets(array, len, stdin);
    /*遇见空格的次数*/
    int num = 0;
    for (int jdx = 0; jdx < len; jdx++)
    {
        /*判断数是否是空格*/
        if (array[jdx] == ' ')
        {
            /*将后面的值赋给前面*/
            array[jdx] = array[jdx + 1];
            /*次数每次加一*/
            num++;
        }
    }
    // printf("array= %s\n",array);
    /*长度减重复的次数*/
    len -= num;

    for (int idx = 0; idx < len; idx++)
    {
        /*将初始数组的最后一个指向逆序后的第一个*/
        invert[idx] = array[len - idx - 1];
        // printf("%c\t",array[len - idx -1]);
    }
    printf("%s", invert);
    printf("\n");
    return 0;
}
