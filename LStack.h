#ifndef LSTACK_H
#define LSTACK_H
//LinkedStack �ṹ���������

typedef struct LSNode LStack;
struct LSNode
{
    ElementType Data;
    LStack Next;
};

//������ջ
LStack CreateLS();
//�жϿ�
bool IsEmptyLS(LStack LS);
//������ջ
void PushLS(ElementType item, LStack LS);
//�����ջ
ElementType PopLS(LSstack LS);

#endif // LSTACK_H
