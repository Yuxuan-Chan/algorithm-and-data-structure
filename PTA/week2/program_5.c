//
// Created by zhang on 2018/9/15.
// https://blog.csdn.net/whzyb1991/article/details/46663867
//#include <stdbool.h>
//#include <stdio.h>
//#include <malloc.h>
//
//#define MaxSize 1000
//typedef struct node{
//    int Data[MaxSize];
//    int cap;
//    int top;
//}Stack;
//int M, N, K;
//
//
//Stack *createStack(int M){
//    Stack *PtrS = (Stack*)malloc(sizeof(struct node));
//    PtrS->cap = M;
//    PtrS->top = -1;
//    return PtrS;
//}
//
//
//void push(Stack *PtrS, int ele){
//    if (PtrS->top == PtrS->cap-1){
//        printf("FULL");
//        return;
//    }
//    PtrS->top++;
//    PtrS->Data[PtrS->top] = ele;
//}
//
//
//int top(Stack *PtrS){
//    return PtrS->Data[PtrS->top];
//}
//
//
//int pop(Stack *PtrS){
//    if (PtrS->top==-1){
//        printf("Empty");
//        return -1;
//    }else{
//        int ele = PtrS->Data[PtrS->top];
//        PtrS->top--;
//        return ele;
//    }
//}
//
//
//int check_stack(const int v[]){
//    int new_cap = M+1;  // 因为多了一个头结点
//    Stack *ps = createStack(new_cap);  // 由于多了一个头结点，所以容量要扩充一个
//    push(ps, 0);  // dummy element
//    int idx = 0;  // index of v
//    int num = 1;  // push to stack
//    while(idx!=N){
//        while(top(ps)<v[idx]&&idx!=N&&ps->top+1<new_cap)  // 因为top起始是-1, 所以当top为5的时候，其实已经是满了，这时还是小于new_cap的，所以要加个1
//            push(ps, num++);
//        if(top(ps)==v[idx]){
//            pop(ps);
//            idx++;
//        }else{
//            return 0;  // false
//        }
//    }
//    return 1;
//}
//
//
//int main(){
//    scanf("%d %d %d", &M, &N, &K);
//    int *v = (int *)malloc(sizeof(int)*N);
//    int i;
//    for(;K!=0;--K){
//        for(i=0; i!=N; ++i)
//            scanf("%d", v+i);
//        if(check_stack(v))
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

