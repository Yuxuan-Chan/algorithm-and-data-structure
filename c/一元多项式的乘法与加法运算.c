# include <stdio.h>
# include <stdlib.h>

struct polynomial {
	int factor;
	int exponent;
	struct polynomial *next;
};

struct list{
	struct polynomial *start;
};
/* 
�ӷ� 
���������������ָ��ϵ����ͬ������� 
*/ 
void initlist(struct list *sList){
	sList->start = NULL;
}

void push(struct list *sList, int factor, int exponent){
	struct polynomial *p;  // �²���Ľ�� 
	p = malloc(sizeof(struct polynomial));
	p->factor = factor;
	p->exponent = exponent;
	p->next = sList->start;  // �ȼ���poly->next =NULL? 
	sList->start = p; 
}

int main(){
	struct list MyList;
	initlist(&MyList);
	
	int x;
	for(x=0; x<100; x++){
		push(&MyList, x, x+1);		
	}
	printf("%d\n", &MyList);
	
	return 0;
} 
