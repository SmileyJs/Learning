#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node;
typedef Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List makeEmpty(List l);
bool isEmpty(List l);
bool isLast(List l, Position p);
Position find(ElementType x, List l);
void deleteElement(ElementType x, List l);
Position findPrevious(ElementType x, List l);
void insert(ElementType x, List l, Position p);
void deleteList(List l);
Position header(List l);
Position first(List l);
Position advance(List l);
ElementType retrieve(Position p);

struct Node
{
	ElementType element;
	Position next;
};

List makeEmpty(List l)
{
	Position head = l;
	head->next = NULL;
	return head;
}

bool isEmpty(List l)
{
	return !(l->next);
}

bool isLast(List l, Position p)
{
	return !(p->next);
}

Position find(ElementType x, List l)
{
	Position tmp = first(l);
	while (tmp && tmp->element != x) {
		tmp = tmp->next;
	}

	return tmp;
}

void deleteElement(ElementType x, List l)
{
	Position tmp = findPrevious(x, l);

	if (!isLast(l, tmp)) {
		Position p = tmp->next;
		tmp->next = p->next;
		free(p);
	}
}

Position findPrevious(ElementType x, List l)
{
	Position tmp = l;
	while(tmp->next && x != tmp->next->element) {
		tmp = tmp->next;
	}

	return tmp;
}

void insert(ElementType x, List l, Position p)
{
	Position tmp;
	tmp = (Position)malloc(sizeof(Node));

	if(!tmp) {
		printf("%s\n", "new node error!");
		return;
	}

	tmp->element = x;
	tmp->next = p->next;
	p->next = tmp;
}

void deleteList(List l)
{
	Position p, tmp;

	p = l;

	while(p) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}

Position header(List l)
{
	return l;
}

Position first(List l)
{
	return l->next;
}

#endif