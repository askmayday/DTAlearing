/*
浙大数据结构课程学习
堆栈的实现
*/

//#define ElementType int //use typedef
typedef int ElementType
//1.堆栈的数组实现
#define MAXSIZE 10
struct Snode
{
    ElementType Data[MAXSIZE];
    int top;
};
typedef struct Snode *Stack;



/*双头堆栈的数组实现
struct DSnode
{
    ElementType Data[MAXSIZE];
    int Top1;  //初始值 Top1 = -1,Top2 = MAXSIZE;
    int Top2;
};
typedef struct DSnode *DStack;
*/

//入栈
void Push(ElementType e, Stack S)
{
    if (S->top == MAXSIZE-1;)
    {
        printf("堆栈满！");
        return;
    }else
    {   S->Data[++(S->top)] = e;
        return;
    }
}

//出栈
ElementType Pop(Stack S)
{
//    ElementType e;
    if (S->top == -1)
    {
        printf("堆栈空！");
        return ERROR;
    }else
    {
        return S->Data[--(S->top)];
//        e = S->Data[--(S->top)];
//        return e;
    }
}

/*
//2.堆栈的链表实现
typedef struct Snode *Stack;
struct Snode
{
    ElementType Data;
    Stack Next;
};

//创建空栈
Stack Create()
{
    Stack s;
    s = (Stack)malloc(sizeof(struct Snode)); //栈底空节点
    s->Next = NULL;
    return s;
}

//判断空
bool isEmpty(Stack S)
{
    return (S->Next == NULL)
}

//链表入栈
void Push(ElementType item, Stack S)
{
    Stack Temp;
    Temp = (Stack)malloc(sizeof(struct Snode));
    Temp->Data = item;
    Temp->Next = S->Next;
    S->Next = Temp;
}
//链表出栈
ElementType Pop(Sstack S)
{
    if (isEmpty(S))
    {
        printf("堆栈空！");
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
