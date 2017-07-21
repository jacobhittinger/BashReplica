#include "path.h"


Path * path() {
	Path * temp = malloc(sizeof(Path));
	temp->val = NULL;
	return temp;
}

void printTypeP(void * passedIn) {
	if (passedIn == NULL) {
		exit(-99);
	}
	printf("%s:", ((Path *) passedIn)->val);
}

void * buildTypeP(FILE * fin) {
	char line[100];
	char * token;
	Path * temp = path();

	fgets(line, 100, fin);
	token = strtok(line, ":");
	token = strtok(NULL, ":");
	temp->val = malloc(sizeof(char) * strlen(token) + 1);
	strcpy(temp->val, token);

	void * ptr = temp;

	return ptr;
}

void * buildType_PromptP(FILE * in) {
	if (in == NULL) {
		exit(-99);
	}

	char line[100];
	int n = 0;
	Path * temp = path();

	printf("Enter the PATH to add: \n");
	fgets(line, 100, in);
	temp->val = malloc(sizeof(char) * strlen(line) + 1);
	strcpy(temp->val, line);

	void * ptr = temp;

	return ptr;
}

int compareP(const void * ptr1, const void * ptr2) {
	// No need to compare paths.
	return 0;
}

void cleanTypeP(void * ptr) {
	if (ptr == NULL) {
		exit(-99);
	}

	free(((Path *) ptr)->val);
	((Path *) ptr)->val = NULL;
}
