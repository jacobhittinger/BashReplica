#include "pipes.h"


int countPipes(char *s) {
	int i, count = 0;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '|') {
			count++;
		}
	}
	return count;
}

void pipeIt(char ** prePipe, char ** postPipe) {
	pid_t pid, pid1;
	int fd[2], res, execvpRes, status, status1;

	pid1 = fork();
	if (pid1 != 0) {
		waitpid(pid1, &status1, 0);
	} else {
		res = pipe(fd);
		if (res < 0) {
			printf("Pipe Failure\n");
			exit(-1);
		}

		pid = fork();
		if (pid != 0) { // parent
			waitpid(pid, &status, 0);
			if (status != 0) {
				printf("Command not found: %s\n", prePipe[0]);
			}

			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);

			execvpRes = 0;
			execvpRes = execvp(postPipe[0], postPipe);

			// The following lines only execute if execvp() fails

			printf("Command not found: %s\n", postPipe[0]);
			if(execvpRes == -1) {
				exit(-99);
			}
		} else { // child
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);

			execvpRes = 0;
			execvpRes = execvp(prePipe[0], prePipe);

			// The following lines only execute if execvp() fails

			if(execvpRes == -1) {
				exit(-99);
			}
		}
	}
}

char ** parsePrePipe(char *s, int * preCount) {
	int i, res;
	char * temp = malloc(strlen(s) * sizeof(char) + 1);
	strcpy(temp, s);

	char * space = " |";
	char * isSpace = strstr(temp, space);

	char * token;
	token = strtok(temp, "|");

	if (isSpace != NULL) {
		token[strlen(token) - 1] = '\0';
	}

	char ** args = NULL;
	res = makeargs(token, &args);
	*preCount = res;

	free(temp);
	temp = NULL;

	return args;
}

char ** parsePostPipe(char *s, int * postCount) {
	int i, res;
	char * saveptr;

	char * temp = malloc(strlen(s) * sizeof(char) + 1);
	strcpy(temp, s);

	char ** args = NULL;

	char * space = "| ";
	char * isSpace = strstr(temp, space);

	char * token;
	token = strtok_r(temp, "|", &saveptr);
	token = strtok_r(NULL, "|", &saveptr);

	if (isSpace != NULL) {
		char * spaceToken = token + 1;
		res = makeargs(spaceToken, &args);
	} else {
		res = makeargs(token, &args);
	}

	*postCount = res;

	free(temp);
	temp = NULL;

	return args;
}

void doublePipeIt(char *** args) {
	pid_t pid;
	int fd[2];
	int read = 0, status = 0, res, execvpRes;

	while (*args != NULL) {
		res = pipe(fd);

		if (res < 0) {
			printf("Pipe Failure\n");
			exit(-1);
		}

		pid = fork();
		if (pid != 0) { // parent
			waitpid(pid, &status, 0);
			if (status != 0) {
				printf("Command not found: %s\n", (*args)[0]);
			}

			close(fd[1]);
			read = fd[0];

			args++;
		} else { // child
			dup2(read, 0);
			if (*(args + 1) != NULL) {
				dup2(fd[1], 1);
			}
			close(fd[0]);

			execvpRes = 0;
			execvpRes = execvp((*args)[0], *args);

			// The following lines only execute if execvp() fails

			if(execvpRes == -1) {
				exit(-99);
			}
		}
	}
}

char *** parseDoublePipe(char * s, int * cmd1, int * cmd2, int * cmd3) {
	char ** arg1 = NULL;
	char ** arg2 = NULL;
	char ** arg3 = NULL;

	char * temp = malloc(strlen(s) * sizeof(char) + 1);
	strcpy(temp, s);

	char * token = NULL;
	char * spaceToken = NULL;
	int res;

	// First command.
	token = strtok(temp, "|");
	if (token[strlen(token) - 1] == ' ') {
		token[strlen(token) - 1] = '\0';
	}
	res = makeargs(token, &arg1);
	*cmd1 = res;

	// Second command.
	token = strtok(NULL, "|");
	if (token[0] == ' ') {
		spaceToken = token + 1;
		if (spaceToken[strlen(spaceToken) - 1] == ' ') {
			spaceToken[strlen(spaceToken) - 1] = '\0';
		}
	} else if (token[strlen(token) - 1] == ' ') {
		token[strlen(token) - 1] = '\0';
	}
	if (spaceToken == NULL) {
		res = makeargs(token, &arg2);
	} else {
		res = makeargs(spaceToken, &arg2);
	}
	*cmd2 = res;

	// Third command.
	token = strtok(NULL, "|");
	if (token[0] == ' ') {
		spaceToken = NULL;
		spaceToken = token + 1;
		res = makeargs(spaceToken, &arg3);
	} else {
		res = makeargs(token, &arg3);
	}
	*cmd3 = res;

	// Create return object.
	char *** ret = malloc(sizeof(arg1) + sizeof(arg2) + sizeof(arg3) + sizeof(char *));
	ret[0] = arg1;
	ret[1] = arg2;
	ret[2] = arg3;
	ret[3] = NULL;

	free(temp);
	temp = NULL;

	return ret;
}
