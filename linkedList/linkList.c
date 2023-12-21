#include <stdio.h>
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

// 静态函数的声明  为了获取要删除数据的位置
static int getAppointPos(linkList *pList, int *pPos, ELEMENTTYPDE val);

// 链表的初始化
int linkListInit(linkList **pList)
{
    // 给链表开辟一个空间
    linkList *list = (linkList *)malloc(sizeof(linkList));
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(linkList));

    // 给头结点开辟空间
    linkNode *head = (linkNode *)malloc(sizeof(linkNode));
    list->head = head;
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(linkNode));
    // 初始化
    list->head->data = 0;
    list->head->next = NULL;
    list->len = 0;
    *pList = list;
    // 将定义的尾指针 初始化在头结点处
    list->tail = list->head;
    return ON_SUCCESS;
}

// 链表的头插
int linkListHeadInit(linkList *pList, ELEMENTTYPDE val)
{
    return linkListPositionInit(pList, 0, val);
}

// 链表的尾插
int linkListTailInit(linkList *pList, ELEMENTTYPDE val)
{
    return linkListPositionInit(pList, pList->len, val);
}

// 链表的指定位置插入
int linkListPositionInit(linkList *pList, int pos, ELEMENTTYPDE val)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    // 新建一个新的结点
    linkNode *newNode = (linkNode *)malloc(sizeof(linkNode));
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(linkNode));

    // 将val的值赋给newNode
    newNode->data = val;

    // 从头结点开始
    linkNode *trvalNode = pList->head;
    //定义一个标志进行判断
    int flag = 0;
    if (pos == pList->len)
    {
        trvalNode = pList->tail;
        flag = 1;
    }

    else
    {
        while (pos)
        {
            trvalNode = trvalNode->next;
            pos--;
        }
    }
    if (flag == 1)
    {
        pList->tail = newNode;
    }

    newNode->next = trvalNode->next;
    trvalNode->next = newNode;

    // 更新链表长度
    (pList->len)++;
    return ON_SUCCESS;
}

// 为了获取要删除数据的位置
static int getAppointPos(linkList *pList, int *pPos, ELEMENTTYPDE val)
{
    int pos = 0;
    linkNode *trvalNode = pList->head;
    while (trvalNode->next != NULL)
    {
       if (trvalNode->next->data == val)
        {
            pos++;
            *pPos = pos;
            return pos;
        }
        trvalNode = trvalNode->next;
        pos++;
    }
    *pPos = NOT_FIND;
     return NOT_FIND;

}

// 链表的指定位置删除
int linkListPositionDel(linkList *pList, int pos)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    linkNode *trvalNode = pList->head;
    linkNode *delNode = NULL;

    int flag = 0;
    if(pos == pList->len)
    {
        flag = 1;
    }

        while (--pos)
        {
                //后移
            trvalNode = trvalNode->next;    
        }
        
    delNode = trvalNode->next;
    trvalNode->next = delNode->next;

    if(flag == 1)
    {
        pList->tail = trvalNode;
    }
    free(delNode);
    delNode = NULL;
    (pList->len)--;
    return ON_SUCCESS;
}

// 链表的指定数据删除
int linkListPositionDataDel(linkList *pList, ELEMENTTYPDE val)
{
    int pos = 0;
    while (pos != NOT_FIND)
    {

        getAppointPos(pList, &pos, val);

        linkListPositionDel(pList, pos);
    }

    return ON_SUCCESS;
}

// 链表的头删
int linkListHeadPositionDel(linkList *pList)
{
    linkListPositionDel(pList, 1);
}

// 链表的尾删
int linkListTailPositionDel(linkList *pList)
{
    linkListPositionDel(pList, pList->len);
}

// 获取链表的长度
int linkListGetSize(linkList *pList, int *Size)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (Size)
    {
        *Size = pList->len;
    }
    return pList->len;
}

// 链表的遍历
int linkListGetDate(linkList *pList)
{

    if (pList == NULL)
    {
        return NULL_PTR;
    }
    linkNode *trvalNode = pList->head;
    while (trvalNode->next != NULL)
    {
        trvalNode = trvalNode->next;
        printf("trvalNode->data %d\n", trvalNode->data);
    }
   
}

// 链表的销毁
int linkListDestroy(linkList *pList)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
    }

   if (pList != NULL)
    {
        free(pList);
        pList = NULL;
    }

return ON_SUCCESS;
}
