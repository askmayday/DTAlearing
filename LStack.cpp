#include <stdlib.h>
#include "LStack.h"

//LinkedStack �ṹ�ĺ���ʵ��

//������ջ
LStack CreateLS();
{
    LStack LS;
    LS = (LStack)malloc(sizeof(struct LSNode)); //ջ�׿սڵ�
    LS->Next = NULL;
    return LS;
}

//�жϿ�
bool IsEmptyLS(LStack LS)
{
    return (LS->Next == NULL)
}

//������ջ
void PushLS(ElementType item, LStack LS)
{
    LStack Temp;
    Temp = (LStack)malloc(sizeof(struct LSNode));
    Temp->Data = item;
    Temp->Next = LS->Next;
    LS->Next = Temp;
}
//�����ջ
ElementType PopLS(LSstack LS)
{
    if (IsEmptyLS(LS))
    {
        printf("��ջ�գ�");
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
