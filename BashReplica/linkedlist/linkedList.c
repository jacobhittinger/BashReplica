#include "linkedList.h"


LinkedList * linkedList() {
	LinkedList * temp = malloc(sizeof(LinkedList));
	temp->head = malloc(sizeof(Node));
	temp->size = 0;
	return temp;
}

void addLast(LinkedList * theList, Node * nn) {
	if (theList->size == 0) {
		theList->head->next = nn;
		theList->head->next->prev = theList->head;
	} else {
		int i;
		Node * tempCur = theList->head;
		for (i = 0; i < theList->size; i++) {
			tempCur = tempCur->next;
		}
		tempCur->next = nn;
		tempCur->next->prev = tempCur;
	}
	theList->size = theList->size + 1;
}

void addFirst(LinkedList * theList, Node * nn) {
	if (theList->size == 0) {
		theList->head->next = nn;
		theList->head->next->prev = theList->head;
		nn = NULL;
	} else {
		nn->next = theList->head->next;
		nn->prev = theList->head;
		theList->head->next->prev = nn;
		theList->head->next = nn;
		nn = NULL;
	}
	theList->size = theList->size + 1;
}

void removeItem(LinkedList * theList, Node * nn, void (*removeData)(void *),
		int (*compare)(const void *, const void *)) {
	if (theList == NULL) {
		return;
	}

	int check = 0;
	int i;
	Node * tempCur = theList->head;

	for (i = 0; i < theList->size; i++) {
		if (check == 1)
			break;

		tempCur = tempCur->next;

		if (compare(tempCur->data, nn->data) == 0) {
			check = 1;

			if (tempCur->next != NULL) {
				tempCur->prev->next = tempCur->next;
				tempCur->next->prev = tempCur->prev;
			} else {
				tempCur->prev->next = NULL;
			}

			removeData(tempCur->data);
			free(tempCur->data);
			free(tempCur);

			theList->size = theList->size - 1;
		}
	}

	removeData(nn->data);
	free(nn->data);
	free(nn);

}

void clearList(LinkedList * theList, void (*removeData)(void *)) {
	if (theList == NULL) {
		return;
	}

	Node * tempCur;
	while (theList->head->next != NULL) {
		tempCur = theList->head->next;

		if (tempCur->next != NULL) {
			theList->head->next = tempCur->next;
			tempCur->next->prev = theList->head;
		} else {
			theList->head->next = NULL;
		}

		removeData(tempCur->data);
		free(tempCur->data);
		free(tempCur);
	}

	free(theList->head);

	theList->size = 0;
}

void printList(const LinkedList * theList, void (*convertData)(void *)) {
	if (theList == NULL || theList->size == 0) {
		printf("%s\n", "Empty List");
	}
	Node * tempCur = theList->head;
	int i;
	for (i = 0; i < theList->size; i++) {
		tempCur = tempCur->next;
		convertData(tempCur->data);
	}
	tempCur = NULL;
	free(tempCur);
}

void removeFirst(LinkedList * theList, void (*removeData)(void *)) {
	if (theList == NULL || theList->size == 0) {
		return;
	}

	Node * cur = theList->head->next;

	if (cur->next != NULL) {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	} else {
		cur->prev->next = NULL;
	}

	removeData(cur->data);
	free(cur->data);
	free(cur);

	theList->size = theList->size - 1;
}
