#ifndef BTTRAVERSAL_H
#define BTTRAVERSAL_H

//二叉树的定义
typedef struct TreeNode *BinTree;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

//递归实现
//前序遍历：根节点->左子树->右子树
void PreOrderTraversal(BinTree BT);
//中序遍历：左子树->跟节点->右子树
void InOrderTraversal(BinTree BT);
//后序遍历：左子树->右子树->根节点
void PostOrderTraserval(BinTree BT);
//非递归实现
//中序遍历
void InOrderTraversal2(BinTree BT);
//前序遍历
void PreOrderTraversal2(BinTree BT);

#endif // BTTRAVERSAL_H
