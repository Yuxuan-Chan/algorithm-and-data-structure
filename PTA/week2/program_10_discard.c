//
// Created by zhang on 2018/9/25.
// https://zhuanlan.zhihu.com/p/34899732
#include <stdio.h>
#include <malloc.h>


struct node{
    int data;
    int height;  // 高度定义为其左右子树的高度的最大值
    struct node *left;
    struct node *right;
};
typedef struct node node_t;
typedef struct node* nodeptr_t;


int maxValue(int a, int b){
    return a > b ? a : b;
}


int treeHeight(nodeptr_t root){
    if(root == NULL){
        return 0;
    }else{
        return maxValue(treeHeight(root->left), treeHeight(root->right))+1;
    }
}


int treeGetBalanceFactor(nodeptr_t root){
    if(root == NULL)
        return 0;
    else
        return root->left->height - root->right->height;
}


// 树的平衡化操作，两大基础操作，左旋和右旋，左旋，即是逆时针旋转，右旋，即是顺时针旋转。
// 这种旋转在整个平衡化过程中可能进行一次或多次，这两种操作都是从失去平衡的最小子树根结点开始的(即离插入结点最近且平衡因子超过1的祖结点)。
nodeptr_t treeRotateRight(nodeptr_t root){
    nodeptr_t left = root->left;

    root->left = left->right;  // 将将要被抛弃的结点连接为旋转后的root的左孩子
    left->right = root;  // 重新定义根结点

    left->height = maxValue(treeHeight(left->left), treeHeight(left->right))+1;

    return left;  // 返回新的根结点
}


nodeptr_t treeRotateLeft(nodeptr_t root){
    nodeptr_t right = root->right;

    root->right = right->left;
    right->left = root;

    right->height = maxValue(treeHeight(right->left), treeHeight(right->right))+1;
    return right;
}


nodeptr_t treeRebalance(nodeptr_t root){
    int factor = treeGetBalanceFactor(root);
    if(factor > 1 && treeGetBalanceFactor(root->left) > 0)  // LL
        return treeRotateRight(root);
    else if(factor > 1 && treeGetBalanceFactor(root->left) <= 0){  // LR
        root->left = treeRotateLeft(root->left);
        return treeRotateRight(root);
    }
    else if(factor < -1 && treeGetBalanceFactor(root->right) <= 0)  // RR
        return treeRotateLeft(root);
    else if(factor < -1 && treeGetBalanceFactor(root->right) > 0){  // RL
        root->right = treeRotateRight(root->right);
        return treeRotateLeft(root);
    }
    else
        return root;
}


void treeInsert(nodeptr_t root_ptr, int value){
    nodeptr_t newNode;
    nodeptr_t root = root_ptr;

    if(root == NULL){
        newNode = malloc(sizeof(node_t));

        newNode->data = value;
        newNode->left = newNode->right = NULL;

        root_ptr = newNode;
    }
    else if(root->data == value)
        return;
    else{
        if(root->data < value)
            treeInsert(root->right, value);
        else
            treeInsert(root->left, value);
    }
    treeRebalance(root);
}


void treeDelete(nodeptr_t root_ptr, int value){
    nodeptr_t to_free;  // 待删除
    nodeptr_t root = root_ptr;
    // todo

}


int main(){
    int N, value;
    scanf("%d\n", &N);
    nodeptr_t root_ptr = NULL;
    for(int i=0; i<N; i++){
        scanf("%d", &value);
        treeInsert(root_ptr, value);
    }
    printf("%d\n", root_ptr->data);

    return 0;
}



