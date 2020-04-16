/*
浙大数据结构课程学习
线性表的顺序存储
*/
#include <stdlib.h> //for malloc函数
#define MAXSIZE 100

//定义和声明
typedef struct Lnode *List;  //定义一个指针数据类型 PtrL
struct Lnode
{
    ElementType Data[MAXSIZE]; //定义数组来存放线性表中内容
    int Last;                 //last表示当前数组最后一个元素的位置
};
struct Lnode L;  //Lnode 只是结构体名称，声明是前面要有类型名 struct
/*也可以在结构体定义后面直接声明（附加变量初始化定义）：
struct Lnode
{
    ElementType Data[MAXSIZE]; //定义数组来存放线性表中内容
    int Last;                 //last表示当前数组最后一个元素的位置（下标）
} L;
*/
List PtrL;       //List 为typedef定义的类型，可以直接使用List声明变量
/* 访问表中元素 L.Data[i] 或 PtrL->Date[i]

/*线性表操作集
List MakeEmpty();
ElementType FindKth(int K, List L);
int Find(ElememtType X, List L);
void Insert(ElememtType X, int i, List L);
void Delete(int i, List L);
int Length(List L);
*/

//初始化空表
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct Lnode));//使用malloc为声明的新表分配空间
                                              // malloc则必须由我们计算字节数，
                                              //并且在返回的时候强转成实际指定类型的指针
    PtrL->Last = -1; //空表，Last只想0的前一位
    return PtrL;
}

//找出表中第K位的元素
ElementType FindKth(int K, List L)
{
    //若L为空表 or L中元素个数小于K
    if (L->Last < 0 || L->Last+1 > K)
        return NUL; //NUL为空字符，NULL为空指针
    else
        return L->Data[K-1];
}

//找出表L中首次出现元素X的位置
int Find(ElememtType X, List L)
{
    int i = 0;
    while (i < L->Last+1 )
    {
        if (L->Date[i] == X)
            return i;         //找到返回X的位置
        i++;
    }
    return -1; //没找到
    //等同于
    //while(i < L->Last+1 && L->Date[i] != X)
    //    i++;
    //if (i >L->Last) return -1;
    //else return i;
}

//在i（i在1和last+1之间）插入X
void Insert(ElememtType X, int i, List L)
{
    if (L->Last+1 == MAXSIZE)
    {
        printf("表已满\n",i);
        return;
    }
    if (i > L->Last+2 || i < 1)
    {
        printf("位置不合法\n",i);
        return;
    }
    int j;
    for (j = L->Last; j >= i-1; j--)
        L->Data[j+1] = L->Data[j];
    L->Data[i-] = X;
    L->Last++;
}

//删除第i位元素
void Delete(int i, List L)
{
    if (i > L->Last+1 || i < 1)  //若位空表，则满足i > L->Last+1
    {
        printf("位置不合法\n");
        return;
    }
    int j;
    for (j = i-1; j <= L->Last; j++ )
        L->Data[j-1] = L->Data[j];
    L->Last--;
    return ;
}
