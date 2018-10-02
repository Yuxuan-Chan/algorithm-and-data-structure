//
// Created by zhang on 2018/9/27.
//
//#include <iostream>
//#include <queue>
//#include <stdio.h>
//#include <malloc.h>
//
//
//typedef struct TreeNode *Position;
//struct TreeNode{
//    int Data;
//    Position Left;
//    Position Right;
//};
//
//
//Position Insert(Position T, int data){
//    if (T == NULL){
//        T = (Position)malloc(sizeof(struct TreeNode));
//        T->Left = T->Right = NULL;
//        T->Data = data;
//    }else{
//        if (data < T->Data){
//            T->Left = Insert(T->Left, data);
//        }
//        else if (data > T->Data){
//            T->Right = Insert(T->Right, data);
//        }
//    }
//    return T;
//}
//
//
//void LevelOrder(Position Root){
//    if (Root != NULL){
//        queue<TreeNode> q;
//        q.push(Root);
//        while(!q.empty()){
//            TreeNode element = q.front();
//            printf("%d ", element.Data);
//            q.pop();
//            if (element.Left != NULL){
//                q.add(element.Left);
//            }
//            if (element.Right != NULL){
//                q.add(element.Right);
//            }
//        }
//    }
//}
//
//
//int main(){
//    int N, number;
//    scanf("%d\n", &N);
//    Position Root = NULL;
//    for (int i=0; i<N; i++){
//        scanf("%d ", &number);
//        Root = Insert(Root, number);
//    }
//    LevelOrder(Root);
//}
// 上面的想法有错误，因为无法确定跟结点，所以虽然建树，层次遍历都是对的，但结果确实 1 0 2 3 4 5 6 7 8 9
// 同理，也不能用avl树去解决，因为调整后的树根结点是4
// https://www.cnblogs.com/kuotian/p/5323189.html
#include <iostream>
#include <algorithm>
using namespace std;

#define MaxSize 1000
int sortNum[MaxSize] = {0};
int CBTreeNode[MaxSize] = {0};
int countNum = 0;


void CreateCBT(int root, int N){
    if(root > N)
        return;
    int left = root * 2;
    int right = root * 2 + 1;
    CreateCBT(left, N);
    CBTreeNode[root] = sortNum[countNum++];
    CreateCBT(right, N);
}


int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &sortNum[i]);
    sort(sortNum, sortNum+N);  // 从小到大排序
    CreateCBT(1, N);  // 将1作为根结点开始创建?
    for(int i=1; i<=N; i++)
        if(i != N)
            printf("%d ", CBTreeNode[i]);
        else
            printf("%d", CBTreeNode[i]);

    return 0;
}

// https://blog.csdn.net/Roland_WuZF/article/details/49389995
#include <stdio.h>
#include <stdlib.h>


int b[1005]={0};
int j=0;

int compare(const void *a, const void *b);
void mid_tre(int root, int N, int a[]);


int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

void mid_tre(int root, int N, int a[]){
    if (root <= N){
        mid_tre(2*root, N, a);
        b[root] = a[j++];
        mid_tre(2*root+1, N, a);
    }
}


int main(){
    int N;
    int i=0;
    scanf("%d", &N);
    int a[N];
    for(i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    qsort(a, N, sizeof(int), compare);
    mid_tre(1, N, a);
    printf("%d", b[1]);
    for(i=2; i<=N; i++){
        printf(" %d", b[i]);
    }
}