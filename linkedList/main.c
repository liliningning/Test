#include <stdio.h>
#include "linkList.h"
#include <string.h>

#define BUFFER_SIZE 3

int main()
{  
    linkList * list = NULL;
    linkListInit(&list);
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        //头插
        // linkListHeadInit(list, idx); 

        //尾插
        linkListTailInit(list, idx);
    }

    //头删
    linkListHeadPositionDel(list);

    //尾删
    linkListTailPositionDel(list);

    //指定数据删除
    linkListPositionDataDel(list,1);


   
    // 获得长度
    int size = 0;
    linkListGetSize(list, &size);
    printf("size %d\n",size);

    //遍历
    linkListGetDate(list);





    return 0;
}