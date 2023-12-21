#include < stdio.h>
#include "linkList.h"
#include <string.h>
#include <stdlib.h>


// 状态码
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,

};

// 链表的初始化
int linkListInit(linkList **pList)
{
    //给链表开辟一个空间
 linkList * List =(linkList *)malloc(sizeof(linkList));

}

// 链表的头插
int linkListHeadInit(linkList *pList, int val)
{

}

// 链表的尾插
int linkListTailInit(linkList *pList, int val);

// 链表的指定位置插入
int linkListPositionInit(linkList *pList, int pos, ELEMENTTYPDE val);

// 链表的指定位置删除
int linkListPositionDel(linkList *pList, int pos);

// 链表的指定数据删除
int linkListPositionDataDel(linkList *pList, int pos, ELEMENTTYPDE val);

// 链表的头删
int linkListHeadPositionDel(linkList *pList);

// 链表的尾删
int linkListTailPositionDel(linkList *pList);

// 获取链表的长度
int linkListGetSize(linkList *pList, int *Size);

// 链表的遍历
int linkListGetDate(linkList *pList);

// 链表的销毁
int linkListDestroy(linkList *pList);

