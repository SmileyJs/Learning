#ifndef LIST_H
#include "list.h"
#endif

// 3-1
void printList(List l)
{
	if (isEmpty(l)) {
		printf("%s\n", "list is empty");
		return;
	}

	Position p = first(l);

	while (p) {
		printf("%d ", p->element);
		p = p->next;
	}

	printf("\n");
}

// 3-2
ElementType getItemByIndex(List l, int n)
{
	if (0 >= n) {
		printf("argument error!\n");
		return -1;
	}

	Position p = first(l);

	for (int i = 1; i != n; ++i) {
		p = p->next;
	}

	return p->element;
}

void printLots(List l, List pos)
{
	Position p = first(pos);
	while (p) {
		ElementType index = p->element;
		ElementType i = getItemByIndex(l, index);
		printf("%d ", i);
		p = p->next;
	}

	printf("\n");
}

//3-3
void switchByPtr(Position p)
{
	if (!p || !p->next) {
		printf("%s\n", "element is null!");
		return;
	}
	
	Position p2, p3;
	p2 = p->next;
	p3 = p2->next;
	p->next = p3;
	p2->next = p3->next;
	p3->next = p2; 	
}

int
main(int argc, char const *argv[])
{
	List l;
	l = (List)malloc(sizeof(Node));
	l->element = 0;
	l->next = NULL;

	insert(1, l, l);

	Position f = first(l);

	insert(2, l, f);
	insert(3, l, f->next);
	insert(4, l, f->next->next);

	/*3-1*/
	printList(l);

	deleteElement(1, l);

	printList(l);

	/*3-2*/
	List pos;
	pos = (List)malloc(sizeof(Node));
	pos->element = 0;
	pos->next = NULL;

	insert(1, pos, pos);
	insert(3, pos, pos->next);

	printList(pos);
	printLots(l, pos);

	deleteList(pos);

	/*3-3*/
	switchByPtr(first(l));
	printList(l);

	deleteList(l);

	return 0;
}
