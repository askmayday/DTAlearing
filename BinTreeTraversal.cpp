//浙大数据结构
//二叉树的遍历
#include <stdio.h>
#include "LStack.h"


//二叉树的定义在BinTreeTraversal.h


//递归实现
//前序遍历：根节点->左子树->右子树
void PreOrderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

//中序遍历：左子树->跟节点->右子树
void InOrderTraversal(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}

//后序遍历：左子树->右子树->根节点
void PostOrderTraserval(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        InOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}
//非递归实现
//中序遍历
void InOrderTraversal2(BinTree BT)
{
    BinTree T = BT;
    LStack S =  CreateLS();
    while (T || !IsEmptyLS(S)) //T指向空节点 且 S 中也空 则认为遍历结束
    {
        while (T) //从T开始，一直向左压栈，直到最左的叶子节点,T->Left==NULL
        {
            PushLS(T, S); //讲节点指针入栈，
            T = T->Left;
        }
        if (!IsEmptyLS(S))) //LS非空，开始POP
        {
            T = PopLS(S);
            printf("%d"，T->Data);
            T = T->Right;
        }
    }
}

//前序遍历
void PreOrderTraversal2(BinTree BT)
{
    BinTree T = BT;
    LStack S = CreateLS();
    while (T || !IsEmptyLS(S))
    {
        while (T)
        {
             printf("%d"，T->Data);
             PushLS(T,S);
             T = T->Left;
        }
        if (!IsEmptyLS(S))
        {
            T = PopLS(S);
            T = T->Right;
        }
    }
}

//后序  ??多用的空间没有free？
void PostOrderTraserval2(BinTree BT)
{
    BinTree T = BT;
    //构造一个新结构，来存储节点和其标志
    typedef struct LabelNode
    {
        BinTree BTnode;
        bool IsFirst;
    }*LN;
    LN Temp;
    S = CreateLS();
    while (T || !IsEmptyLS(S))
    {
        while (T)
        {
            LN LT = (LN)malloc(sizeof(struct LabelNode));
            LT->BTnode = T;
            LT->IsFirst = true;
            PushLS(LT,S);
            T = T->Left;
        }
        if (!IsEmptyLS(S))
        {
            Temp = PopLS(S);
            if (Temp->IsFirst = true)
            {
                PushLS(Temp,S);
                T = Temp->BTnode->Right;
            }
            else
            {
                printf("%d",Temp->BTnode->Data);
                T = NULL;
            }
        }
    }

}

//层序遍历：按层遍历,又称“广度优先遍历”
void LevelOrderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    BinTree T = BT;
    LQueue Q = CreateLQ();
    InLQ(T,Q);
    while (!IsEmptyLQ(Q))
    {
        T = OutLQ(Q);
        printf("%d",T->Data);
        if (T->Left) InLQ(T->Left,Q);
        if (T->Right) InLQ(T->Right,Q);
    }
}

//深度优先遍历之前序遍历
void PreOrderTraversal2(BinTree BT)
{
    if (BT == NULL)
        return;
    BinTree T = BT;
    LStack S = CreateLS();
    PushLS(T,S);
    while (!IsEmptyLS(S))
    {
        T = PopLS(S);
        printf("%d",T->Data);
        if (T->Right) PushLS(T->Right);
        if (T->Left) PushLS(T->Left);
    }
}
