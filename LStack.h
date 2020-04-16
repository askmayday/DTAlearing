#ifndef LSTACK_H
#define LSTACK_H
//LinkedStack 结构的相关声明

typedef struct LSNode LStack;
struct LSNode
{
    ElementType Data;
    LStack Next;
};

//创建空栈
LStack CreateLS();
//判断空
bool IsEmptyLS(LStack LS);
//链表入栈
void PushLS(ElementType item, LStack LS);
//链表出栈
ElementType PopLS(LSstack LS);

#endif // LSTACK_H
