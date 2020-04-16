//二叉搜索树（BST，Binary Search Tree）
 //非空BST的性质
 //1. 非空左子树所有键值均小于其根节点的键值
 //2. 非空左子树所有键值均小于其根节点的键值
 //3. 左右子树都是BST

//元素查找函数--递归方法
Position Find（ElementType X,BinTree BST)
{
    if (BST == NULL) return NULL;
    if (X < BST->Data)
            return Find(X,BST->Left); //尾递归
        else if (X > BST->Data)
            return Find(X,BST->Right); //尾递归
        else
            return BST;
}

//元素查找函数--迭代方法
Position Find（ElementType X,BinTree BST)
{
//   if (BST == NULL) return NULL; //跟while循环重复判定
    while (BST != NULL)
    {
        if (X < BST->Data)
            BST = BST->Left;
        else if (X > BST->Data)
            BST = BST->Right;
        else
            return BST;
    }
    return NULL;
}
