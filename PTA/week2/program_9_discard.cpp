//
// Created by zhang on 2018/9/24.
//
#include <iostream>
#include <queue>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
using namespace std;


typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BST = (struct TNode *)malloc(sizeof(struct TNode));  // 这里一开始的时候写错了
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }else{
        if(X>BST->Data){
            BST->Right = Insert(BST->Right, X);
        }else if(X<BST->Data){
            BST->Left = Insert(BST->Left, X);
        }
    }
    return BST;
}


BinTree buildBinTree(int N){
    BinTree Root = (struct TNode *)malloc(sizeof(struct TNode));
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    Root->Data = arr[0];
    Root->Left = NULL;
    Root->Right = NULL;
    for(int i=1; i<N; i++){
        Insert(Root, arr[i]);
    }
    return Root;
}


bool check(BinTree T1, BinTree T2, int N){
    int arr1[N];  //  利用数组去存储读取顺序
    int count1 = 0;
    int arr2[N];  //
    int count2 = 0;

    queue<BinTree> queue1;
    queue1.push(T1);  // 先把根节点push进去
    while(!queue1.empty()){
        BinTree item = queue1.front();
        queue1.pop();  // 删除最前面的节点
        arr1[count1] = item->Data;
        count1++;
        if (item->Left != NULL){
            queue1.push(item->Left);
        }
        if (item->Right != NULL){
            queue1.push(item->Right);
        }
    }

    queue<BinTree> queue2;
    queue2.push(T2);  // 先把根节点push进去
    while(!queue2.empty()){
        BinTree item = queue2.front();
        queue2.pop();  // 删除最前面的节点
        arr2[count2] = item->Data;
        count2++;
        if(item->Left != NULL){
            queue2.push(item->Left);
        }
        if(item->Right != NULL){
            queue2.push(item->Right);
        }
    }

    for(int i=0; i<N; i++){
        if (arr1[i] != arr2[i]){
            printf("No\n");
            return false;
        }
    }
    printf("Yes\n");
    return true;
}


void reset(BinTree T){
    if(T->Left){
        reset(T->Left);
    }
    if(T->Right){
        reset(T->Right);
    }
    T->Data = NULL;
}

int main(){
    int N, L;
    scanf("%d %d\n", &N, &L);
    BinTree origin = buildBinTree(N);
    for (int i=0; i<L; i++){
        BinTree contrast = buildBinTree(N);
        check(origin, contrast, N);
        reset(contrast);
    }
}

// 我的想法是：1. 建树 2. 层次遍历 3. 比较异同
// 但有个测试点无法通过 sample 换顺序。有Yes，有No：根不同，子树根不同。树有单边、有双子树
// 虽然没通过，但也学习了queue的用法，特别要注意的是queue.pop()是没有返回值的，但pop()操作是从左端最前面删除，所以要先通过front去取