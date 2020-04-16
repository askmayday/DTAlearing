#include <stdlib.h>
#include "LStack.h"

//LinkedStack 结构的函数实现

//创建空栈
LStack CreateLS();
{
    LStack LS;
    LS = (LStack)malloc(sizeof(struct LSNode)); //栈底空节点
    LS->Next = NULL;
    return LS;
}

//判断空
bool IsEmptyLS(LStack LS)
{
    return (LS->Next == NULL)
}

//链表入栈
void PushLS(ElementType item, LStack LS)
{
    LStack Temp;
    Temp = (LStack)malloc(sizeof(struct LSNode));
    Temp->Data = item;
    Temp->Next = LS->Next;
    LS->Next = Temp;
}
//链表出栈
ElementType PopLS(LSstack LS)
{
    if (IsEmptyLS(LS))
    {
        printf("堆栈空！");
        return NULL;
    }
    LStack Temp;
    ElementType item;
    Temp = LS->Next;
    LS->Next = Temp->Next;
    item = Temp->Data;
    free(Temp);
    return item;
}
