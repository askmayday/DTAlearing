#include <stdio.h>
#include <stdlib.h> //for malloc函数

#define MAXSIZE 100

typedef struct Lnode *List;  //定义一个指针数据类型 List
struct Lnode
{
    double Data[MAXSIZE]; //定义数组来存放线性表中内容
    int Last;                 //last表示当前数组最后一个元素的位置
};

List MakeEmpty();
double FindKth(int K, List L);
int Find(double  X, List L);
void Insert(double X, int i, List L);
void Delete(int i, List L);

int main()
{
    List PtrL;
    PtrL = MakeEmpty();

    //手动初始化list
    for (int i = 0; i < 10; i++)
    {
        PtrL->Data[i] = 0.1 * i;
        printf("PtrL->Data[%d] = %f \n",i,PtrL->Data[i]);
    }
    PtrL->Last = 9;

    //打印整个list
    for (int i = 1; i <= PtrL->Last+1; i++)
        printf("表中元素都有：%f\n",FindKth(i,PtrL));

    //查找元素1的位置
    printf("元素1的位置是：%d \n",Find(1,PtrL));

    //在list第5位插入1，然后打印整个新list
    Insert(1,12,PtrL);
    for (int i = 1; i <= PtrL->Last+1; i++)
        printf("表中元素都有：%f\n",FindKth(i,PtrL));

    Delete(5,PtrL);
    for (int i = 1; i <= PtrL->Last+1; i++)
        printf("表中元素都有：%f\n",FindKth(i,PtrL));

    return 0;
}

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
double FindKth(int K, List L)
{
    //若L为空表 or L中元素个数小于K
    if (L->Last < 0 || L->Last+1 < K)
        return 3307; //3307为异常标识
    else
        return L->Data[K-1];
}

//找出表L中首次出现元素X的位置
int Find(double X, List L)
{
    int i = 0;
    while (i < L->Last+1 )
    {
        if (L->Data[i] == X)
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

//在i（i在1和last+1之间）前插入X
void Insert(double X, int i, List L)
{
    if (L->Last+1 == MAXSIZE)
    {
        printf("表已满\n");
        return;
    }
    if (i > L->Last+2 || i < 1)
    {
        printf("位置不合法\n");
        return;
    }
    int j;
    for (j = L->Last; j >= i-1; j--)
        L->Data[j+1] = L->Data[j];
    L->Data[i-1] = X;
    L->Last++;
    return;
}

//删除第i位元素
void Delete(int i, List L)
{
/*    if (L->Last < 0)
    {
        printf("空表\n");
        return;
    }
*/
    if (i > L->Last+1 || i < 1) //若位空表，则满足i > L->Last+1
    {
        printf("位置不合法\n");
        return;
    }
    int j;
    for (j = i-1; j <= L->Last; j++ )
        L->Data[j] = L->Data[j+1];
    L->Last--;
    return ;
}
