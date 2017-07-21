#include "myUtils.h"


int menu() {
	char temp[MAX];
	int choice;

	do {
		printf("1) Print the list\n");
		printf("2) Add First\n");
		printf("3) Add Last\n");
		printf("4) Sort\n");
		printf("5) Remove Item\n");
		printf("6) Quit\n");
		printf("Choice --> ");
		fgets(temp, MAX, stdin);
		choice = atoi(temp);
	} while (choice < 1 || choice > 6);

	return choice;
}

void strip(char *array) {
	if (array == NULL) {
		exit(-99);
	}

	int len = strlen(array), x = 0;

	while (array[x] != '\0' && x < len) {
		if (array[x] == '\r')
			array[x] = '\0';
		else if (array[x] == '\n')
			array[x] = '\0';

		x++;
	}
}

int readTotal(FILE * fin) {
	if (fin == NULL) {
		exit(-99);
	}

	int count = 0;
	char temp;

	while (!feof(fin)) {
		temp = fgetc(fin);
		if (temp == '\n') {
			count++;
		}
	}

	rewind(fin);
	return count;
}
