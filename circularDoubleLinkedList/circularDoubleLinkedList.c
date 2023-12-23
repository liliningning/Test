#include "circularDoubleLinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 状态码
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    MALLOC_SUCCESS,

};

// 静态函数的声明 找到要删除元素的位置
static int linkedListAccordAppointVal(CircularDoubleLinkList *pList, ELEMENTTPYE val, int *pPos, int (*comparFunc)(ELEMENTTPYE, ELEMENTTPYE));

// 静态函数的声明  将结点封装为函数
static CircularDoubleLinkNode *createCircularDoubleNode(ELEMENTTPYE val);

// 链表初始化
int CircularDoubleLinkListInit(CircularDoubleLinkList **pList)
{
    int ret = 0;
    // 链表开辟空间
    CircularDoubleLinkList *list = (CircularDoubleLinkList *)malloc(sizeof(CircularDoubleLinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(list, 0, sizeof(CircularDoubleLinkList) * 1);
    // 头结点开辟空间
    CircularDoubleLinkNode *head = NULL;
    list->head = malloc(sizeof(CircularDoubleLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(list->head, 0, sizeof(CircularDoubleLinkNode) * 1);
    list->head->data = 0;

    list->head->prev =list->head;

    list->head->next = list->head;


    // 初始化时尾指针等于头指针
    list->tail = list->head;

    // 链表长度为0
    list->len = 0;

    // 二级指针
    *pList = list;
    return ret;
}

// 链表头插
int CircularDoubleLinkListHeadInsert(CircularDoubleLinkList *pList, ELEMENTTPYE val)
{
    return CircularDoubleLinkListAppointPosInsert(pList, 0, val);
}

// 链表尾插
int CircularDoubleLinkListTailInsert(CircularDoubleLinkList *pList, ELEMENTTPYE val)
{
    return CircularDoubleLinkListAppointPosInsert(pList, pList->len, val);
}

// 将结点封装为函数
static CircularDoubleLinkNode *createCircularDoubleNode(ELEMENTTPYE val)
{
    CircularDoubleLinkNode *newNode = NULL;
    newNode = (CircularDoubleLinkNode *)malloc(sizeof(CircularDoubleLinkNode) * 1);
    if (newNode == NULL)
    {
        return 0;
    }
    memset(newNode, 0, sizeof(CircularDoubleLinkNode) * 1);
    // 赋值
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->data = val;
    return newNode;
}

// 链表指定位置插入
int CircularDoubleLinkListAppointPosInsert(CircularDoubleLinkList *pList, int pos, ELEMENTTPYE val)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    // 新建新结点 封装为函数
    CircularDoubleLinkNode *newNode = createCircularDoubleNode(val);
#if 0
    // 封装结点
    CircularDoubleNode *newNode = (CircularDoubleNode *)malloc(sizeof(CircularDoubleNode) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(CircularDoubleNode) * 1);
    // 赋值
    newNode->data = val;
#endif
#if 1
    // 从虚拟头结点开始
    CircularDoubleLinkNode *travelNode = pList->head;
#else
    CircularDoubleNode *travelNode = pList->head->next;
#endif
    int flag = 0;
    /* 在头结点后面插入 头插*/
    if (pos == 0)
    {
        pList->tail->next = newNode;
        newNode->prev = pList->tail;
        newNode->next = travelNode->next;
        travelNode->next->prev = newNode;
    }
    /*尾插 */
    else if (pos == pList->len)
    {

        travelNode = pList->tail;
        newNode = pList->head->prev;
        newNode->next = pList->head->next;
        flag = 1;
    }

    else
    {
        while (pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
        travelNode->next->prev = newNode;
        newNode->next = travelNode->next;
    }

    newNode->prev = travelNode;
    travelNode->next = newNode;

    if (flag == 1)
    {

        pList->tail = newNode;
    }
    // 更新链表长度
    (pList->len)++;
    return ret;
}

// 链表的头删
int CircularDoubleLinkListHeadDel(CircularDoubleLinkList *pList)
{
    return CircularDoubleLinkListAppintPosDel(pList, 1);
}

// 链表的尾删
int CircularDoubleLinkListTailDel(CircularDoubleLinkList *pList)
{
    CircularDoubleLinkListAppintPosDel(pList, pList->len);
}

// 链表的指定位置删除
int CircularDoubleLinkListAppintPosDel(CircularDoubleLinkList *pList, int pos)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    CircularDoubleLinkNode *trvaelNode = pList->head;
    CircularDoubleLinkNode *needNode = NULL;
    /*删除第一个结点*/
    if(pos == 1)
    {
        needNode = trvaelNode->next;
        needNode->next->prev = pList->tail;
        pList->tail = needNode->next;
        trvaelNode->next = needNode->next;
        trvaelNode = needNode->next->prev;
    }
    /*删除最后一个结点*/
   else if (pos == pList->len)
    {
        CircularDoubleLinkNode *temNode = pList->tail;
        pList->tail = pList->tail->prev;
        pList->tail->next = trvaelNode;
        trvaelNode->prev = pList->tail;
        needNode = temNode;
    }
    /*删除指定位置的结点*/
    else
    {
        while (--pos)
        {
            // 后移
            trvaelNode = trvaelNode->next;
            // pos--;
        }
        // needNode 需要删除的结点
         needNode = trvaelNode->next; 
        trvaelNode->next = needNode->next;
        trvaelNode = needNode->next->prev;
    }
    
    // 释放内存
    if (needNode != NULL)
    {
        free(needNode);
        needNode = NULL;
    }
    (pList->len)--;
    return ON_SUCCESS;
}

// 静态函数只给本源文件自己使用 不需要判断合法性
static int linkedListAccordAppointVal(CircularDoubleLinkList *pList, ELEMENTTPYE val, int *pPos, int (*comparFunc)(ELEMENTTPYE, ELEMENTTPYE))
{
    int pos = 1;
#if 0
    CircularDoubleNode *trvaelNode = pList->head;
#else

    CircularDoubleLinkNode *trvaelNode = pList->head->next;
#endif
    int cmp = 0;
    while (trvaelNode != NULL)
    {
#if 0
        if (trvaelNode->data == val)
        {
            *pPos =pos;
            return pos;
        }
#else
        cmp = comparFunc(val, trvaelNode->data);
        if (cmp == 0)
        {
            *pPos = pos;
            return pos;
        }
#endif
        trvaelNode = trvaelNode->next;
        pos++;
    }
    *pPos = NOT_FIND;
    return NOT_FIND;
}

// 链表删除指定数据
int CircularDoubleLinkListDelAppointData(CircularDoubleLinkList *pList, ELEMENTTPYE val, int (*comparFunc)(ELEMENTTPYE, ELEMENTTPYE))
{
    int pos = 0;
    int ret = 0;
    int size = 0;
    while (CircularDoubleLinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        // 找到数据所在的位置
        linkedListAccordAppointVal(pList, val, &pos, comparFunc);
        // 指定位置删除
        CircularDoubleLinkListAppintPosDel(pList, pos);
    }
    return ret;
}

// 获取链表的长度
int CircularDoubleLinkListGetLength(CircularDoubleLinkList *pList, int *pSize)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pSize)
    {
        *pSize = pList->len;
    }
    return pList->len;
}

// 链表的销毁
int CircularDoubleLinkListDestroy(CircularDoubleLinkList *pList)
{ // 使用头删 释放链表
    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
        pList->tail = NULL;
    }

    if(pList != NULL)
    {
        free(pList);
        pList = NULL;
    }
    return  ON_SUCCESS;
}

#if 0
// 链表的遍历
int linkedListForeach(CircularDoubleLinkList *pList, int (*printFunc)(ELEMENTTPYE))
// int linkedListForeach(CircularDoubleLinkList *pList)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    //从头结点开始 travelNode 指向头结点
    CircularDoubleNode *travelNode = pList->head;
    while (travelNode->next  != NULL)
    {
        travelNode = travelNode->next;
        prinf("travelNode->data %d\t",travelNode->data); 
    }

#else

    // 从头结点开始
    CircularDoubleLinkNode *travelNode = pList->head;

    // 从链表第一个结点开始（travelNode 指向第一个结点）
    // CircularDoubleNode *travelNode = pList->head->next;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
#if 0
        printf("travelNode->data %d\n", travelNode->data);
        // travelNode = travelNode->next;
#else
        // 包装器 回调函数
        //  调用这个函数
        printFunc(travelNode->data);
#endif
    }
#endif
    return ret;
}
#endif 
// 逆序打印
int CircularDoubleLinkListReverForeach(CircularDoubleLinkList *pList, int (*printFunc)(ELEMENTTPYE))
{
    // pList->tail = pList->len;
    CircularDoubleLinkNode *travelNode = pList->tail;

    while (travelNode != pList->head)
    {
        printFunc(travelNode->data);
        travelNode = travelNode->prev;
    }

    return ON_SUCCESS;
}



