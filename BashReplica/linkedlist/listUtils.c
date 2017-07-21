#include "listUtils.h"


Node * buildNode(FILE * fin, void *(*buildData)(FILE * in, int n), int num) {
	Node * temp = malloc(sizeof(Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = buildData(fin, num);
	return temp;
}

Node * buildNode_Type(void * passedIn) {
	Node * temp = malloc(sizeof(Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = passedIn;
	return temp;
}

void sort(LinkedList * theList, int (*compare)(const void *, const void *)) {
	Node *p, *q, *top;
	int changed = 1;

	top = theList->head;

	if (theList != NULL && theList->head->next != NULL) {
		while(changed) {
			changed = 0;
			q = top;
			p = top->next;
			while (p->next != NULL) {
				if (compare(p->data, p->next->data) > 0) {
					q->next = p->next;
					p->next->prev = q;
					if (p->next->next == NULL) {
						p->next = NULL;
					} else {
						p->next = p->next->next;
					}
					q->next->next = p;
					p->prev = q->next;
					if (p->next != NULL) {
						p->next->prev = p;
					}
					changed = 1;
				}
				q = p;
				if (p->next != NULL)
					p = p->next;
			}
		}
	}

	p = top->next;
}

void buildListH(LinkedList * myList, int total, FILE * fin, void * (*buildData)(FILE * in, int n)) {
	Node * temp = NULL;

	int i;
	for (i = 0; i < total; i++) {
		temp = buildNode(fin, buildData, (i + 1));
		addLast(myList, temp);
	}

	temp = NULL;
	free(temp);
}
