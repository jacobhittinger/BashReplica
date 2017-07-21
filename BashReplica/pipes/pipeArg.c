#include "pipeArg.h"


PipeArg * pipeArg() {
	PipeArg * temp = malloc(sizeof(PipeArg));
	temp->command = NULL;
	return temp;
}

void cleanTypePA(void * ptr) {
	if (ptr == NULL) {
		exit(-99);
	}

	int count, i;
	for (i = 0; ((PipeArg *) ptr)->command[i] != '\0'; i++)
		;
	count = i;

	for (i = 0; i < count; i++) {
		free(((PipeArg *) ptr)->command[i]);
	}

	free(((PipeArg *) ptr)->command);
	((PipeArg *) ptr)->command = NULL;
}
