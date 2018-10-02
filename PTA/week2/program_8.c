//
// Created by zhang on 2018/9/16.
// https://blog.csdn.net/drdairen/article/details/71338066
//#include <stdio.h>
//#include <malloc.h>
//
//#define N 30
//typedef struct node{
//    int Data[N];
//    int Top;
//    int Cap;
//}Stack;
//
//
//Stack *createStack(int cap){
//    Stack *ptrS = (Stack*)malloc(sizeof(struct node));
//    ptrS->Top = -1;
//    ptrS->Cap = cap;
//    return ptrS;
//}
//
//void push(Stack *ptrS, int data){
//    if (ptrS->Top == ptrS->Cap-1){
//        printf("Full\n");
//        return;
//    }else{
//        ptrS->Top++;
//        ptrS->Data[ptrS->Top] = data;
//    }
//}
//
//
//int pop(Stack *ptrS){
//    if (ptrS->Top==-1){
//        printf("Empty\n");
//        return -1;
//    }else{
//        int ele = ptrS->Data[ptrS->Top];
//        ptrS->Top--;
//        return ele;
//    }
//}

// 先序遍历: 根左右
// 中序遍历: 左根右
// 后序遍历: 左右根
// preOrder 1, 2, 3, 4, 5, 6
// inOrder  3, 2, 4, 1, 6, 5
// 求后序
//int preOrder[N];
//int inOrder[N];
/*
int pre[] = {1, 2, 3, 4, 5, 6};
int mid[] = {3, 2, 4, 1, 6, 5};


void post(int root, int start, int end){
    if (start > end)
        return;
    int i = start;
    while(i < end && mid[i] != pre[root])
        i++;
    printf("%d %d %d %d\n", root, start, end, i);  // root==0, start==0, end==5, i==3
    post(root+1, start, i-1);  // root+1==1, start==0, i-1==2
    post(root+1+i-start, i+1, end);  // root+1+i-start==0+1+3-0==4 i+1==4, end==5
    printf("%d\n", mid[i]);
}

int main(){
    post(0, 0, 5);

    return 0;
}

int post[] = {3, 4, 2, 6, 5, 1};
int mid[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end)
{
    if(start > end)
        return ;
    int i = start;
    while(i < end && mid[i] != post[root]) i++;  //定位根在中序的位置
    cout<<mid[i];  //访问当前处理的树的根
    pre(root-1-(end-i), start, i - 1);  //递归处理左子树
    pre(root-1, i + 1, end);  //递归处理右子树
}

int main()
 {
    pre(5, 0, 5);
    return 0;
}
*/
// http://www.cnblogs.com/llhthinker/p/4748792.html
// https://cloud.tencent.com/developer/article/1028655
// 上面这两个网址下面这种解法的相同思路，先建树
#include <stdio.h>
#include <stdbool.h>
#include <mem.h>
#include <malloc.h>


#define STR_LEN 5
#define MAX_SIZE 30


typedef struct Node{
    int data;
    struct Node *left, *right;
}*treeNode;

treeNode Stack[MAX_SIZE];
int values[MAX_SIZE];

int num = 0;
int top = -1;

void Push(treeNode tn);
treeNode Pop();
treeNode Top();
bool isEmpty();

void PostOrderTraversal(treeNode root);


int main(){
    int n;
    char operation[STR_LEN];
    treeNode father, root;
    bool findRoot = 0, Poped = 0;

    scanf("%d", &n);
    for (int i=0; i<2*n; i++){
        scanf("%s", operation);
        if (strcmp(operation, "Push") == 0){
            int value;
            scanf("%d", &value);
            treeNode newNode;
            newNode = (treeNode)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            if (!findRoot){
                root = newNode;  // 根节点
                Push(newNode);
                findRoot = 1;
            }else{
                if (!Poped)  // 如果前一个操作不是pop, 则父节点为栈顶元素
                    father = Top();
                if (father->left == NULL)
                    father->left = newNode;
                else
                    father->right = newNode;
                Push(newNode);
            }
            Poped = 0;
        }else{
            father = Pop();
            Poped = 1;
        }
    }
    PostOrderTraversal(root);
    for(int i=0; i<num-1; i++)
        printf("%d ", values[i]);
    printf("%d\n", values[num-1]);

    return 0;
}


void PostOrderTraversal(treeNode root){
    treeNode tn = root;
    if(tn){
        PostOrderTraversal(tn->left);
        PostOrderTraversal(tn->right);
        values[num++] = tn->data;  //将后序遍历出的节点值存入数组便于格式化打印
    }
}


void Push(treeNode tn)
{
    Stack[++top] = tn;
}

treeNode Pop()
{
    return Stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

treeNode Top()
{
    return Stack[top];
}


// https://blog.csdn.net/yeternity/article/details/72804055
// https://blog.csdn.net/pilipilipan/article/details/79875101
// https://blog.csdn.net/drdairen/article/details/71338066
// 另外一种递归的思路
