//������ݽṹ
//�������ı���
#include <stdio.h>
#include "LStack.h"


//�������Ķ�����BinTreeTraversal.h


//�ݹ�ʵ��
//ǰ����������ڵ�->������->������
void PreOrderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

//���������������->���ڵ�->������
void InOrderTraversal(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}

//���������������->������->���ڵ�
void PostOrderTraserval(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        InOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}
//�ǵݹ�ʵ��
//�������
void InOrderTraversal2(BinTree BT)
{
    BinTree T = BT;
    LStack S =  CreateLS();
    while (T || !IsEmptyLS(S)) //Tָ��սڵ� �� S ��Ҳ�� ����Ϊ��������
    {
        while (T) //��T��ʼ��һֱ����ѹջ��ֱ�������Ҷ�ӽڵ�,T->Left==NULL
        {
            PushLS(T, S); //���ڵ�ָ����ջ��
            T = T->Left;
        }
        if (!IsEmptyLS(S))) //LS�ǿգ���ʼPOP
        {
            T = PopLS(S);
            printf("%d"��T->Data);
            T = T->Right;
        }
    }
}

//ǰ�����
void PreOrderTraversal2(BinTree BT)
{
    BinTree T = BT;
    LStack S = CreateLS();
    while (T || !IsEmptyLS(S))
    {
        while (T)
        {
             printf("%d"��T->Data);
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

//����  ??���õĿռ�û��free��
void PostOrderTraserval2(BinTree BT)
{
    BinTree T = BT;
    //����һ���½ṹ�����洢�ڵ�����־
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

//����������������,�ֳơ�������ȱ�����
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

//������ȱ���֮ǰ�����
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
