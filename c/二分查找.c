#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};


Position BinarySearch( List L, ElementType X );

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X){
	int left = 0;
	int right = L->Last;
	while (left <= right){
		int mid = (left + right) / 2;
		if (L->Data[mid] == X){
			return mid;
		}
		else if (L->Data[mid] > X){
			right = mid;
		}
		else if (L->Data[mid] < X){
			left = mid + 1;
		}
	}
	return NotFound;
}


int main()
{
    List L;
    ElementType X;
    Position P;

	int i;
	for (i = 0; i < 10; i++){
		L->Data[i] = i;   // pointer!!!应该这样赋值 
//		printf("%d\n", L->Data[i]);
	}
	L->Last = 9;
//	printf("%d\n", L->Last);
	X = 5;
    P = BinarySearch( L, X );
    printf("%d\n", P);
	

    return 0;
}

