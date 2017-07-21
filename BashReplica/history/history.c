#include "history.h"


History * history() {
	History * temp = malloc(sizeof(History));
	temp->num = 0;
	temp->command = NULL;
	return temp;
}

void printTypeH(void * passedIn) {
	if (passedIn == NULL) {
		exit(-99);
	}

	printf("%d %s", ((History *) passedIn)->num, ((History *) passedIn)->command);
}

void * buildTypeH(FILE * fin, int n) {
	char line[100];
	char * token;
	History * temp = history();

	fgets(line, 100, fin);
	token = strtok(line, " ");
	token = strtok(NULL, "");
	temp->command = malloc(sizeof(char) * strlen(token) + 1);
	strcpy(temp->command, token);

	temp->num = n;

	void * ptr = temp;

	return ptr;
}

void * buildType_PromptH(FILE * in) {
	if (in == NULL) {
		exit(-99);
	}

	char line[100];
	int n = 0;
	History * temp = history();

	printf("Enter the command to add to history: \n");
	fgets(line, 100, in);
	temp->command = malloc(sizeof(char) * strlen(line) + 1);
	strcpy(temp->command, line);

	printf("Enter the number at which to insert it: \n");
	fgets(line, 100, in);
	sscanf(line, "%d", &n);
	temp->num = n;

	void * ptr = temp;

	return ptr;
}

int compareH(const void * ptr1, const void * ptr2) {
	// only compares by num, return first minus second
	return ((((History *) ptr1)->num - ((History *) ptr2)->num));
}

void cleanTypeH(void * ptr) {
	if (ptr == NULL) {
		exit(-99);
	}

	free(((History *) ptr)->command);
	((History *) ptr)->command = NULL;
}
