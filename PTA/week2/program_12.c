#include <stdio.h>
#include <malloc.h>
#define minData -50000;
typedef int ElementType;
typedef struct HeapStruct *MinHeap;
struct HeapStruct{
    ElementType *Elements;
    int Size;
    int Capacity;
};


MinHeap Create(int MaxSize){
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType*)malloc(sizeof(ElementType)*(MaxSize+1));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = minData;  // 必须要写这一行，不然会报错
    return H;
}


void Insert(MinHeap H, int data){
    int i = ++H->Size;  // 从下标为1的地方存放元素
    for(;H->Elements[i/2]>data;i=i/2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = data;
}


int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    MinHeap H = Create(N);
    for(int i=0; i<N; i++){
        int data;
        scanf("%d", &data);
        Insert(H, data);
    }
    for(int i=0; i<M; i++){
        int end;
        scanf("%d", &end);
        for(int i=end; i>1; i/=2){
            printf("%d ", H->Elements[i]);
        }
        printf("%d\n", H->Elements[1]);
    }

    return 0;
}