#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//
// Created by zhang on 2018/9/23.
//https://www.cnblogs.com/ranjiewen/p/6654173.html
typedef int Status;  // 函数类型
typedef int ElementType;
typedef struct TreeNode* BSTree;
struct TreeNode{
    ElementType Data;
    BSTree Left;
    BSTree Right;
    int Flag;  // 被访问为1，否则0
};


BSTree NewNode(ElementType data){
    BSTree root = (BSTree)malloc(sizeof(struct TreeNode));
    root->Data = data;
    root->Left = NULL;
    root->Right = NULL;
    root->Flag = 0;
    return root;
}


BSTree Insert(BSTree root, ElementType data){
    if (root==NULL){
        root = NewNode(data);
    }else{
        if(root->Data<data){
            root->Right = Insert(root->Right, data);
        }else{
            root->Left = Insert(root->Left, data);
        }
    }
    return root;
}


BSTree MakeTree(int N){
    BSTree T;
    ElementType data;
    scanf("%d", &data);
    T = NewNode(data);
    for (int i=1; i<N; i++){
        scanf("%d", &data);
        T = Insert(T, data);
    }
    return T;
}


//将另一棵树的结点依次在一颗二叉树上搜索，找到后标记；当搜索过程中有未被标记的结点，说明两棵树不一样
bool Check(BSTree T, ElementType data){
    if(T->Flag){  // Flag == 1
        if(data<T->Data){
            return Check(T->Left, data);
        }else{
            return Check(T->Right, data);
        }
    }else{
        if(data==T->Data){
            T->Flag = 1;
            return true;
        }else{
            return false; // 结点不一样
        }
    }
}


int Judge(BSTree T, int N){
    ElementType data;
    int flag = 0; //注意这是小flag, 0代表目前乃一致，1代表已经不一致
    scanf("%d", &data);
    if (data!=T->Data)  //判断根结点是否一致
    {
        flag = 1;  //不一致的情况下也要把后面的结点输入后才做判断
    }else{
        T->Flag = 1;
    }
    for(int i=1; i<N; i++){
        scanf("%d", &data);
        if((!flag)&&(!Check(T, data))){  // flag == 0的时候，!flag == 1， Check(T, data) == false的时候，!Check(T, data) == true  也就是说目前一致，同时出现了结点不一样的情况
            flag = 1;  // 所以此时把flag置为1
        }
    }
    if (flag){
        return 0;
    }else{
        return 1;
    }
}


void ResetT(BSTree T){  //清除T中各结点的flag标记
    if(T->Left){
        ResetT(T->Left);
    }
    if(T->Right){
        ResetT(T->Right);
    }
    T->Flag = 0;
}


void FreeT(BSTree T){  //释放T的空间
    if(T->Left){
        FreeT(T->Left);
    }
    if(T->Right){
        FreeT(T->Right);
    }
    free(T);
}


int main(){
    int N;
    int L;
    BSTree T;
    scanf("%d", &N);
    while(N)  // 可以多次输入测试
    {
        scanf("%d", &L);  // 需要检查的序列个数
        T = MakeTree(N);  // 输入N个元素创建树
        for(int i=0; i<L; i++){
            if(Judge(T, N))  // 依次输入N个元素，每个元素都进行标记判断
            {
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
            ResetT(T);
        }
        FreeT(T);
        scanf("%d", &N);
    }
}