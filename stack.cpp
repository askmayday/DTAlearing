/*
������ݽṹ�γ�ѧϰ
��ջ��ʵ��
*/

//#define ElementType int //use typedef
typedef int ElementType
//1.��ջ������ʵ��
#define MAXSIZE 10
struct Snode
{
    ElementType Data[MAXSIZE];
    int top;
};
typedef struct Snode *Stack;



/*˫ͷ��ջ������ʵ��
struct DSnode
{
    ElementType Data[MAXSIZE];
    int Top1;  //��ʼֵ Top1 = -1,Top2 = MAXSIZE;
    int Top2;
};
typedef struct DSnode *DStack;
*/

//��ջ
void Push(ElementType e, Stack S)
{
    if (S->top == MAXSIZE-1;)
    {
        printf("��ջ����");
        return;
    }else
    {   S->Data[++(S->top)] = e;
        return;
    }
}

//��ջ
ElementType Pop(Stack S)
{
//    ElementType e;
    if (S->top == -1)
    {
        printf("��ջ�գ�");
        return ERROR;
    }else
    {
        return S->Data[--(S->top)];
//        e = S->Data[--(S->top)];
//        return e;
    }
}

/*
//2.��ջ������ʵ��
typedef struct Snode *Stack;
struct Snode
{
    ElementType Data;
    Stack Next;
};

//������ջ
Stack Create()
{
    Stack s;
    s = (Stack)malloc(sizeof(struct Snode)); //ջ�׿սڵ�
    s->Next = NULL;
    return s;
}

//�жϿ�
bool isEmpty(Stack S)
{
    return (S->Next == NULL)
}

//������ջ
void Push(ElementType item, Stack S)
{
    Stack Temp;
    Temp = (Stack)malloc(sizeof(struct Snode));
    Temp->Data = item;
    Temp->Next = S->Next;
    S->Next = Temp;
}
//�����ջ
ElementType Pop(Sstack S)
{
    if (isEmpty(S))
    {
        printf("��ջ�գ�");
        return NULL;
    }
    Stack Temp;
    ElementType item;
    Temp = S->Next;
    S->Next = Temp->Next;
    item = Temp->Data;
    free(Temp);
    return item;
}
*/
