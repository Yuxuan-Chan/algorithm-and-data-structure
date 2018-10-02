//
// Created by zhang on 2018/9/26.
// https://zhuanlan.zhihu.com/p/34899732
// http://www.cnblogs.com/llhthinker/p/4770099.html
// https://blog.csdn.net/lpp0900320123/article/details/39367451
#include <stdio.h>
#include <malloc.h>


typedef struct TreeNode *AvlTree;
typedef struct TreeNode *Position;
struct TreeNode{
    int Data;
    AvlTree Left;
    AvlTree Right;
    int Height;
};


AvlTree Insert(int x, AvlTree T);  // 插入新节点，必要时调整
Position SingleRotateWithLeft(Position a);  // 左单旋
Position SingleRotateWithRight(Position b);  // 右单旋
Position DoubleRotateWithLeft(Position a);  // 左右旋
Position DoubleRotateWithRight(Position b);  // 右左旋


int Max(int x1, int x2);  // 返回两个int中较大的
int Height(Position P);  // 返回一个节点的高度


int main(){
    int n, x;
    AvlTree T = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        T = Insert(x, T);
    }
    printf("%d\n", T->Data);  // 打印根节点的值

    return 0;
}


AvlTree Insert(int x, AvlTree T){
    if (T == NULL){
        T = (AvlTree)malloc(sizeof(struct TreeNode));
        T->Data = x;
        T->Left = T->Right = NULL;
        T->Height = 0;
    }
    else if(x < T->Data){  // 向左子树插入
        T->Left = Insert(x, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2){  // 需调整
            if (x < T->Left->Data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(x > T->Data){  // 向右子树插入
        T->Right = Insert(x, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2){  // 需调整
            if (x > T->Right->Data)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    // else值为x的节点已经存在树中，无需插入

    // 更新节点高度
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}


Position SingleRotateWithLeft(Position a){  // 这里a相当于原来的根节点
    Position b = a->Left;
    a->Left = b->Right;
    b->Right = a;
    // 更新a, b节点高度
    a->Height = Max(Height(a->Left), Height(a->Right)) + 1;
    b->Height = Max(Height(b->Left), Height(b->Right)) + 1;

    return b;  // 新的根节点
}


Position SingleRotateWithRight(Position b){  // 同理，这里b相当于原来的根节点
    Position a = b->Right;
    b->Right = a->Left;
    a->Left = b;
    // 更新a, b节点高度
    a->Height = Max(Height(a->Left), Height(a->Right)) + 1;
    b->Height = Max(Height(b->Left), Height(b->Right)) + 1;

    return a;  // 新的根节点
}


Position DoubleRotateWithLeft(Position a){
    a->Left = SingleRotateWithRight(a->Left);
    return SingleRotateWithLeft(a);
}


Position DoubleRotateWithRight(Position b){
    b->Right = SingleRotateWithLeft(b->Right);
    return SingleRotateWithRight(b);
}


int Max(int x1, int x2){
    return (x1 > x2) ? x1 : x2;
}


int Height(Position P){
    if (P == NULL)  // 空节点高度为-1
        return -1;
    return P->Height;
}


Position Find(int x, AvlTree T){
    // 与BST查找方式没有区别
    if (T == NULL)
        return NULL;
    else if(x < T->Data)
        return Find(x, T->Left);
    else if(x > T->Data)
        return Find(x, T->Right);
    else
        return T;
}


void Delete(int x, AvlTree T){
    // 要分情况，可能删除元素的时候会导致树的不平衡
    /*
     * else if(x < T->Data){  // 向左子树插入
        T->Left = Insert(x, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2){  // 需调整
            if (x < T->Left->Data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(x > T->Data){  // 向右子树插入
        T->Right = Insert(x, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2){  // 需调整
            if (x > T->Right->Data)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
     * */
    if (T == NULL)
        return;
    if (x < T->Data){  // 往左子树走
        Delete(x, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2){  // 需调整
            if (x < T->Left->Data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (x > T->Data){  // 往右子树走
        Delete(x, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2){  // 需调整
            if (x > T->Right->Data)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    else{  // 找到要删除的元素节点
        if (T->Left==NULL){  //  左子树为空
            Position temp = T;
            T = T->Right; // 用右孩子代替此节点
            free(temp);  // 释放内存
        }
        else if (T->Right==NULL){  // 右子树为空
            Position temp = T;
            T = T->Left;  // 用左孩子代替此节点
            free(temp);
        }
        else{  // 左右子树都不为空
            // 一般的删除的策略是左子树的最大数据或右子树的最小数据代替该节点
            Position temp = T->Left;  // 从左子树中查找
            while (temp->Right!=NULL)
                temp = temp->Right;
            // 此时的temp指向左子树中的最大元素
            T->Data = temp->Data;
            Delete(temp->Data, T->Left);
        }
    }
    // 更新节点的高度
    if (T)
        T->Height = Max(Height(T->Left), Height(T->Right));
}


void InOrder(AvlTree T){
    if (T == NULL)
        return;
    InOrder(T->Left);
    printf("%d ", T->Data);
    InOrder(T->Right);
}
