#include "dynamicArray.h"
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 10
#define DEFAULT_SIZE 5

int main()
{

    dynamicArray array;
    // 动态数组的初始化
    dynamicArrayInit(&array, BUFFER_SIZE);
    int buffer[BUFFER_SIZE] = {1, 2, 3, 4, 5};
    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }


    dynamicArrayDeleteData(&array);


    // 数组的大小
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size %d\n", size);
//获取指定位置元素的值
    int *val = NULL;
  
    for ( int idx = 0; idx < size ; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val: %d\n", *val);
    }


    return 0;
}
