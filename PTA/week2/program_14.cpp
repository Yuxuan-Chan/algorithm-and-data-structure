//
// Created by zhang on 2018/10/4.
// https://www.cnblogs.com/ranjiewen/p/6684264.html
//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <malloc.h>
//#include <stdbool.h>
//#include <string>
//using namespace std;
//#define MAXSIZE 64
//
//int nodenum;
//int c[64];
//char f[64];
//
//typedef struct TNode* HuffTree;
//struct TNode
//{
//    HuffTree left;
//    HuffTree right;
//    int weight;
//};
//
//typedef struct Heap* MinHeap;
//struct Heap
//{
//    HuffTree* data;
//    int size;
//    int capacity;
//};
//
//
//
//MinHeap CreateHeap(){
//    MinHeap H = (MinHeap)malloc(sizeof(struct TNode));
//    H->data = malloc(sizeof(int)*(MAXSIZE+1));
//    H->size = 0;
//    H->capacity = MAXSIZE;
//    H->data[0] = malloc(sizeof(struct TNode));
//    H->data[0]->weight = -1;
//    return H;
//}
//
//
//bool Insert(MinHeap H, HuffTree f){
//    if(H->size==H->capacity){
//        return false;
//    }
//    int i = ++H->size;
//    for(;H->data[i/2]->weight>f->weight; i/=2){
//        H->data[i] = H->data[i/2];
//    }
//    H->data[i] = f;
//    return true;
//}
//
//
//bool isEmpty(MinHeap H){
//    return H->size == 0;
//}
//
//
//HuffTree DeleteMin(MinHeap H){
//    int Parent, Child;
//    HuffTree MinItem, LastItem;
//    if (isEmpty(H)){
//        printf("minHeap is empty");
//    }
//    MinItem = H->data[1];
//    LastItem = H->data[H->size--];  // 最后一个元素
//    // 寻找删除结点前堆中最后一个结点在新堆中插入位置
//    for(Parent=1; Parent*2<=H->size; Parent=Child){
//        Child = Parent * 2;
//        if(Child!=H->size && H->data[Child]->weight>H->data[Child+1]->weight)
//            Child++;
//        if(LastItem->weight<=H->data[Child]->weight)
//            break;
//        else
//            H->data[Parent] = H->data[Child];  // 向上覆盖
//    }
//    H->data[Parent] = LastItem;
//    return MinItem;
//}
//
//
//HuffTree HuffmanTree(){
//    MinHeap h = CreateHeap();
//    for(int i=0; i<nodenum; i++){
//        HuffTree f = malloc(sizeof(struct TNode));
//        f->weight = c[i];
//        f->left = NULL;
//        f->right = NULL;
//        if(!Insert(h, f))
//            break;
//    }
//    for(;;){
//        if(h->size == 1)
//            break;
//        HuffTree f = malloc(sizeof(struct TNode));
//        f->left = DeleteMin(h);
//        f->right = DeleteMin(h);
//        f->weight = f->left->weight + f->right->weight;
//        Insert(h, f);
//    }
//    return DeleteMin(h);
//}
//
//
//int WPL(HuffTree tree, int depth){
//    if((!tree->left) && (!tree->right)){
//        return depth*(tree->weight);
//    }
//    else{
//        return WPL(tree->left, depth+1) + WPL(tree->right, depth+1);
//    }
//}
//
//
//bool check(HuffTree tree, string s){
//    bool flag = false;
//    HuffTree p = tree;
//    for(int i=0; i<s.size(); i++){
//        if(s[i] == '0'){
//            if(!p->left){
//                p->left = malloc(sizeof(struct TNode));
//                p->left->left = NULL;
//                p->left->right = NULL;
//                p = p->left;
//                flag = true;
//            }
//            else{
//                p = p->left;
//            }
//        }
//        else if(s[i] == '1'){
//            if(!p->right){
//                p->right = malloc(sizeof(struct TNode));
//                p->right->left = NULL;
//                p->right->right = NULL;
//                p = p->right;
//                flag = true;
//            }
//            else{
//                p = p->right;
//            }
//        }
//    }
//    return flag;
//}
//
//
//int main(){
//    int case_;
//    scanf("%d", &nodenum);
//    for(int i=0; i<nodenum; i++){
//        scanf("%d %d", &f[i], &c[i]);
//    }
//    HuffTree tree = HuffmanTree();
//    int wpl = WPL(tree, 0);
//
//    scanf("%d", &case_);
//    for(int j=0; j<case_; j++){
//        HuffTree root = malloc(sizeof(struct TNode));
//        root->left = NULL;
//        root->right = NULL;
//        int s_wpl = 0;
//        string judge = "";
//        for(int i=0; i<nodenum; i++){
//            char ch;
//            string s;
//            scanf("%c %c", &ch, &s);
//            if(s.size()>nodenum-1){
//                judge = "No";
//                break;
//            }
//            s_wpl += s.size()*c[i];
//
//            if(!check(root, s))
//                judge = "No";
//        }
//        if(judge.empty() && s_wpl == wpl)
//            judge = "Yes";
//        else
//            judge = "No";
//        printf("%c", judge);
//    }
//
//    return 0;
//}
// https://blog.csdn.net/wuhuagu_wuhuaguo/article/details/72822647
#include <iostream>
#define MAXSIZE 64
using namespace std;


struct TreeNode{  // Huffman二叉树
    int weight=0;
    TreeNode *lchild=NULL;
    TreeNode *rchild=NULL;
};


struct FlagNode{  // 前缀码二叉树
    int flag=0;  // 0表示未访问过，1表示访问过
    FlagNode *lchild=NULL;
    FlagNode *rchild=NULL;
};


struct Heap{  // 堆
    TreeNode data[MAXSIZE];  // 二叉节点数组
    int size=0;
};


void Insert(Heap *H, TreeNode *T){
    int i=++H->size;
    for(;T->weight<H->data[i/2].weight;i/=2){
        H->data[i] = H->data[i/2]  //若失衡（使之不是小根堆）,则从下往上覆盖，注意,H->size必须要自增后再赋给i
    }
    H->data[i] = *T;  // 为何不是T?不能，因为T是指针，*T才是节点
}


Heap* ReadInsert(int n, Heap *H, int a[]){
    char c = '\0';  // 字母，不能"\0"
    int w = 0;  //字母的权重
    for(int i=0; i<n; i++){
        cin>>c>>w;
        a[i] = w;
        TreeNode *T = new TreeNode;
        T->weight = w;
        Insert(H, T);
    }
    return H;
}


TreeNode* DeleteMin(Heap *H){
    TreeNode* min = new TreeNode;
    *min = H->data[1];  // //本来是TreeNode xx=H->data[yy];但是因为最终要返回指针，所以..
    TreeNode last = H->data[H->size--]  //size--非常重要,注意
    int parent, child; // 下标
    // 寻找删除结点前堆中最后一个结点在新堆中的插入位置
    for(parent=1; parent<=(H->size)/2; parent=child){
        child = parent*2;
        if((child!=H->size) && (H->data[child].weight > H->data[child+1].weight))
            child++;
        if(last.weight<=H->data[child].weight)
            break;
        else
            H->data[parent] = H->data[child];  // 往上覆盖
    }
    H->data[parent] = last;
    return min;  // 删除最小堆的最小元素，最小堆的根节点的值比左子树和右子树的值都要小
}


//  核心是针对原有堆，进行“删2个，插1个”操作n-1次，即H->size-2次
TreeNode* Huffman(Heap *H){
   TreeNode *T;
   int n = H->size;
   for(int i=0; i<n-1; i++){  // 做H->size-1次合并，循环判断不能写i<H->size,因为H->size不断在变
       T = new TreeNode;
       T->lchild = DeleteMin(H);
       T->rchild = DeleteMin(H);
       T->weight = T->lchild->weight + T->rchild->weight;
       Insert(H, T);
   }
   T = DeleteMin(H);
   return T;
}


int WPL(TreeNode *T, int depth){
    if(!(T->lchild)&&!(T->rchild))
        return depth*(T->weight);
    else
        return WPL(T->lchild, depth+1) + WPL(T->rchild, depth+1);
}


bool Judge(string s, FlagNode *f){  // 根据A~G构建FlagNode 二叉树
    for(int i=0; i<s.length(); i++){
        if(s[i]=='0'){
            if(!(f->lchild)){
                FlagNode *lf = new FlagNode;
                f->lchild = lf;
            }
            else{
                if(f->lchild->flag==1)
                    return false;
            }
            f = f->lchild;
        }
        else{
            if(!(f->rchild)){
                FlagNode *rf = new FlagNode;
                f->rchild = rf;
            }
            else{
                if(f->rchild->flag==1)
                    return false;
            }
            f = f->rchild;
        }
    }
    f->flag = 1;
    return !(f->lchild) && !(f->rchild);
    /* if(!(f->lchild) && !(f->rchild)){
     *    return true;
     * }
     * else{
     *    return false;
     * }
     * */
}


int main(){
    // 创建一个堆
    int n1;
    cin >> n1;
    Heap *H = new Heap;
    H->data[0].weight = -1;  // 下标为0的节点不用，设置为岗哨
    // 读入各个节点的权值，并插入小根堆
    int a[MAXSIZE];
    H = ReadInsert(n1, H, a);
    TreeNode *T = Huffman(H);  // 构建Huffman树，返回最终合成的二叉树
    int len = WPL(T, 0);

    char c = '\0';  // 不能是"\0"
    string s = "\0";  // 必须是"\0"
    int n2;
    cin >> n2;
    bool result = false;

    for(int i=0; i<n2; i++){
        bool flag = true;  // true表示到目前为止，都满足“非前缀码”（任一编码都不是是其他编码的前缀）
        int count = 0;
        FlagNode *f = new FlagNode;
        for(int j=0; j<n1; j++){
            cin>>c>>s;
            count+=s.length()*a[j];  // 求权重和
            if(flag){  // 目前为止，都满足"非前缀码"
                result = Judge(s, f);
                if(!result)
                    flag = false;
            }
        }
        delete(f);
        if((count==len)&&result)
            cout<<"Yes"<<endl;  // //改成flag可以吗？可以，一样的效果
        else
            cout<<"No"<<endl;
    }

    return 0;
}