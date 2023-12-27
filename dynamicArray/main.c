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

    //在指定位置插入
    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }

    //删除数组
    dynamicArrayDeleteData(&array);

    //删除指定位置的数据
    int pos = 1;
    dynamicArrayDeleteAppointPosData(&array,pos);

    //动态数组的容量
    int capacity = 0;
    dynamicArrayGetCapacity(&array,&capacity);
    printf("capacity %d\n",capacity);



    // 数组的大小
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size %d\n", size);






#if 0
    // 获取指定位置元素的值
    int *val = NULL;

    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val: %d\n", *val);
    }

#endif
    return 0;
}
