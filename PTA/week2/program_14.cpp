//
// Created by zhang on 2018/10/4.
//
#include <iostream>
#include <vector>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string>
using namespace std;
#define MAXSIZE 64

int nodenum;
int c[64];
char f[64];

typedef struct TNode* HuffTree;
struct TNode
{
    HuffTree left;
    HuffTree right;
    int weight;
};

typedef struct Heap* MinHeap;
struct Heap
{
    HuffTree* data;
    int size;
    int capacity;
};



MinHeap CreateHeap(){
    MinHeap H = (MinHeap)malloc(sizeof(struct TNode));
    H->data = malloc(sizeof(int)*(MAXSIZE+1));
    H->size = 0;
    H->capacity = MAXSIZE;
    H->data[0] = malloc(sizeof(struct TNode));
    H->data[0]->weight = -1;
    return H;
}


bool Insert(MinHeap H, HuffTree f){
    if(H->size==H->capacity){
        return false;
    }
    int i = ++H->size;
    for(;H->data[i/2]->weight>f->weight; i/=2){
        H->data[i] = H->data[i/2];
    }
    H->data[i] = f;
    return true;
}


bool isEmpty(MinHeap H){
    return H->size == 0;
}


HuffTree DeleteMin(MinHeap H){
    int Parent, Child;
    HuffTree MinItem, LastItem;
    if (isEmpty(H)){
        printf("minHeap is empty");
    }
    MinItem = H->data[1];
    LastItem = H->data[H->size--];  // 最后一个元素
    // 寻找删除结点前堆中最后一个结点在新堆中插入位置
    for(Parent=1; Parent*2<=H->size; Parent=Child){
        Child = Parent * 2;
        if(Child!=H->size && H->data[Child]->weight>H->data[Child+1]->weight)
            Child++;
        if(LastItem->weight<=H->data[Child]->weight)
            break;
        else
            H->data[Parent] = H->data[Child];  // 向上覆盖
    }
    H->data[Parent] = LastItem;
    return MinItem;
}


HuffTree HuffmanTree(){
    MinHeap h = CreateHeap();
    for(int i=0; i<nodenum; i++){
        HuffTree f = malloc(sizeof(struct TNode));
        f->weight = c[i];
        f->left = NULL;
        f->right = NULL;
        if(!Insert(h, f))
            break;
    }
    for(;;){
        if(h->size == 1)
            break;
        HuffTree f = malloc(sizeof(struct TNode));
        f->left = DeleteMin(h);
        f->right = DeleteMin(h);
        f->weight = f->left->weight + f->right->weight;
        Insert(h, f);
    }
    return DeleteMin(h);
}


int WPL(HuffTree tree, int depth){
    if((!tree->left) && (!tree->right)){
        return depth*(tree->weight);
    }
    else{
        return WPL(tree->left, depth+1) + WPL(tree->right, depth+1);
    }
}


bool check(HuffTree tree, string s){
    bool flag = false;
    HuffTree p = tree;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            if(!p->left){
                p->left = malloc(sizeof(struct TNode));
                p->left->left = NULL;
                p->left->right = NULL;
                p = p->left;
                flag = true;
            }
            else{
                p = p->left;
            }
        }
        else if(s[i] == '1'){
            if(!p->right){
                p->right = malloc(sizeof(struct TNode));
                p->right->left = NULL;
                p->right->right = NULL;
                p = p->right;
                flag = true;
            }
            else{
                p = p->right;
            }
        }
    }
    return flag;
}


int main(){
    int case_;
    scanf("%d", &nodenum);
    for(int i=0; i<nodenum; i++){
        scanf("%d %d", &f[i], &c[i]);
    }
    HuffTree tree = HuffmanTree();
    int wpl = WPL(tree, 0);

    scanf("%d", &case_);
    for(int j=0; j<case_; j++){
        HuffTree root = malloc(sizeof(struct TNode));
        root->left = NULL;
        root->right = NULL;
        int s_wpl = 0;
        string judge = "";
        for(int i=0; i<nodenum; i++){
            char ch;
            string s;
            scanf("%c %c", &ch, &s);
            if(s.size()>nodenum-1){
                judge = "No";
                break;
            }
            s_wpl += s.size()*c[i];

            if(!check(root, s))
                judge = "No";
        }
        if(judge.empty() && s_wpl == wpl)
            judge = "Yes";
        else
            judge = "No";
        printf("%c", judge);
    }

    return 0;
}
