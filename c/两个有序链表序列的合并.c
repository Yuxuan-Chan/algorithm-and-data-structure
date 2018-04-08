#include <stdio.h>
#include <stdlib.h>


struct entry{
	int value;
	struct entry *next;
} *LinkList;


void merge(LinkList &La, LinkList &Lb, LinkList &Lc){
	// La, Lb都是递增有序的
	struct entry pa, pb, pc;
	pa = La->next; pb = Lb->next;
	Lc = pc = pa;  
	while(pa&&pb){
		if(pa->value<=pb->value){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}

