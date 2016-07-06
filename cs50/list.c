
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "list.h"

node *head = NULL;

void insert(void);
void delete(void);
void find(void);

int
main(void) {

	int cmd = 0;

	do {
		printf("please input your command!\n");
		printf("\t1 -- insert\n");
		printf("\t2 -- delete\n");
		printf("\t3 -- find\n");

		scanf("%d", &cmd);

		switch (cmd) {
			case 0:
				break;
			case 1: 
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				find();
				break;
			default:
				printf("input error\n");
				break;
		}	
	} 
	while (cmd != 0);

	node *ptr = head;

	while (NULL != ptr) {
		node *bakPtr = ptr->next;
		free(ptr);
		ptr = bakPtr;
	}

	return 0;
}

void insert(void) {
	node *newNode = malloc(sizeof(node));

	if (NULL == newNode) {
		return;
	}

	printf("Number to input:\n");

	scanf("%d", &newNode->N);
	newNode->next = NULL;

	if (NULL == head) {
		head = newNode;
	}
	else if (head->N > newNode->N) {
		newNode->next = head;
		head = newNode;
	}
	else {
		node *tmpPtr = head;
		while (1) {
			if (tmpPtr->N == newNode->N) {
				free(newNode);
				break;
			}
			else if (NULL == tmpPtr->next) {
				tmpPtr->next = newNode;
				break;
			}
			else if (tmpPtr->next->N > newNode->N) {
				newNode->next = tmpPtr->next;
				tmpPtr->next = newNode;
				break;
			}
			else {
				tmpPtr = tmpPtr->next;
			}
		}
	}

	printf("The list now is ");

	node *tmp = head;
	while (NULL != tmp) {
		printf("%d  ", tmp->N);
		tmp = tmp->next;
	}

	printf("\n");

	return;
}

void delete(void) {
	printf("fuction delete\n");

	return;
}

void find(void) {
	printf("functon find\n");

	return;
}