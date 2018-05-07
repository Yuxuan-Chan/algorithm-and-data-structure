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
加法 
遍历两个链表，如果指数系数相同，就相加 
*/ 
void initlist(struct list *sList){
	sList->start = NULL;
}

void push(struct list *sList, int factor, int exponent){
	struct polynomial *p;  // 新插入的结点 
	p = malloc(sizeof(struct polynomial));
	p->factor = factor;
	p->exponent = exponent;
	p->next = sList->start;  // 等价于poly->next =NULL? 
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
