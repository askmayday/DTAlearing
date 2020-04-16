/*
浙大数据结构课程学习
线性表的链式存储
*/

//定义
typedef struct Lnode *List;  //一个结构体只是链表的一个节点
struct Lnode
{
    ElementType Data;
    List Next;
};

struct Lnode L;
List PtrL;

//main operatons

//求表长
int Length(List L)
{
    List p = L; //p指向第一个节点
    int i = 0;
    while (p)
    {
        p = p->Next;
        i++；   //此时p指向第i个节点
    }
    return i;
}

//按序号K查找节点
List FindKth(int K, List L)
{
    List p = L;
    int i = 1;
    while (i < K && p!= NULL) //p != NULL 与 p 等效？
    {
        p = p->Next;
        i++；
    }
    if (K == i)
        return p;
    else
        return NULL; //K > Length(L)
}

//按内容查找节点
int Find(ElementType X, List L)
{
    List p = L;
    while (p->Data != X && p != NULL)
        p = p->Next;
    return p; //若找到，返回内容所在节点，否则返回NULL
}

//i节点'前'插入x值新节点,返回新链表
List Insert(ElementType X, int i, List L)
{
    List s;
 //   s = (List)malloc(sizeof(struct Lnode)); 放在此处可能会用不到，造成内存泄漏？
 //   s->Data = X;

    //i为1时，直接在第一位插入
    if (i == 1)
    {
        s = (List)malloc(sizeof(struct Lnode));
        s->Data = X;
        s->Next = L;
        return s;
    }

    /*
    List p = L;
    int j =1;
    while (j < i-1 && p != NULL) //若i为1,则不可能用j==i-1,即无法在第一位插入元素
    {
        p = p->Next;
        j++;
    }
    //
    if (j == i-1)
    {
        s = (List)malloc(sizeof(struct Lnode));
        s->Data = X;
        s->Next = p ->Next;
        p ->Next = s;
        return L;
    }
    else
    {
        printf("参数错误\n");
        return NULL;
    }
    */
    //可调用FindKth()简化程序
    List p;
    p = FindKth(i-1,L); //p返回位置指针或NULL
    if ( p = NULL)
    {
        printf("参数i错误");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct Lnode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return L;
    }
}

//删除i处的节点
List Delete(int i, List L)
{
    List p,s;
    if (i == 1)
    {
        if (L == NULL)
            return NULL;
        p = L->Next;
        free(L);
        return p;
    }

    p = FindKth(i-1,L);
    if (p == NULL)
    {
        printf("第%d位不存在\n",i-1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("第%d位不存在\n",i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return L;
    }
}
