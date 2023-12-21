#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPDE int

// 定义结点
typedef struct linkNode
{
    ELEMENTTYPDE data;
    struct  linkNode *next;

} linkNode;

typedef struct linkList
{
    int len;
    linkNode *head;
    linkNode *tail;

} linkList;

// 链表的初始化
int linkListInit(linkList **pList);

// 链表的头插
int linkListHeadInit(linkList *pList, ELEMENTTYPDE val);

// 链表的尾插
int linkListTailInit(linkList *pList,ELEMENTTYPDE val );

// 链表的指定位置插入
int linkListPositionInit(linkList *pList, int pos, ELEMENTTYPDE val);

// 链表的指定位置删除
int linkListPositionDel(linkList *pList, int pos);

// 链表的指定数据删除
int linkListPositionDataDel(linkList *pList, ELEMENTTYPDE val);

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

#endif
