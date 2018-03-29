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
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};


Position BinarySearch( List L, ElementType X );

/* ��Ĵ��뽫��Ƕ������ */
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
		L->Data[i] = i;   // pointer!!!Ӧ��������ֵ 
//		printf("%d\n", L->Data[i]);
	}
	L->Last = 9;
//	printf("%d\n", L->Last);
	X = 5;
    P = BinarySearch( L, X );
    printf("%d\n", P);
	

    return 0;
}

