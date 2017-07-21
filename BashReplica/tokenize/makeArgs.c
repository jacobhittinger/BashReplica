#include "makeArgs.h"


int makeargs(char *s, char *** argv) {
	if (strlen(s) <= 0) {
		return -1;
	}

	int num = 1;
	int i;
	char * temp;
	char * saveptr;
	char end = '\0';

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ')
			num++;
	}

	temp = strtok_r(s, " ", &saveptr);
	strip(temp);

	*argv = malloc((num + 1) * sizeof(char *));
	(*argv)[0] = malloc((strlen(temp) + 1) * sizeof(char));
	strcpy((*argv)[0], temp);

	if (num > 1) {
		i = 1;

		temp = strtok_r(NULL, " ", &saveptr);
		strip(temp);

		while (temp != NULL) {
			(*argv)[i] = malloc((strlen(temp) + 1) * sizeof(char));
			strcpy((*argv)[i], temp);
			i++;
			temp = strtok_r(NULL, " ", &saveptr);
			if (temp != NULL)
				strip(temp);
		}
	}

	(*argv)[num] = NULL;

	if (num < 1) {
		return -1;
	}
	return num;
}

void printargs(int argc, char **argv) {
	int x;
	for (x = 0; x < argc; x++)
		printf("%s\n", argv[x]);
}

void clean(int argc, char **argv) {
	int i;
	for (i = 0; i <= argc; i++) {
		free(argv[i]);
		argv[i] = NULL;
	}

	free(argv);
	argv = NULL;
}
