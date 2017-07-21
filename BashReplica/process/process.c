#include "process.h"


void forkIt(char ** argv) {
	int i;
	for (i = -1; argv[i] != '\0'; i++)
		;
	i = i - 1;

	if (strcmp(argv[i], "&") == 0) { // if last argv is '&' then send to background
		pid_t pid;

		pid = fork();
		if (pid < 0) {
			exit(-99);
		}

		if (pid == 0) {
			argv[i] = NULL;
			int res = 0;
			res = execvp(argv[0], argv);
			if (res == -1) {
				exit(-99);
			}
		}
	} else { // else, not to be sent to background
		int status, res;
		pid_t pid = fork();
		if (pid < 0) {
			exit(-99);
		}

		if (pid > 0) { // parent
			waitpid(pid, &status, 0);
			if (status != 0) {
				printf("Command not found: %s\n", argv[0]);
			}
		} else { // child
			res = 0;
			res = execvp(argv[0], argv);

			// The following lines only execute if execvp() fails

			if (res == -1) {
				exit(-99);
			}
		}
	}
}
