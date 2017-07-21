#include "cd.h"


void cd(char * path) {
	int res;
	char p[100], cwd[100];
	strcpy(p, path);

	if (path[0] != '/') { // add "/new/directory" onto the cwd
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, p);

		res = chdir(cwd);
		if (res != 0) {
			printf("No such directory: %s\n", cwd);
		}
	} else { // it's already a full path
		res = chdir(path);
		if (res != 0) {
			printf("No such directory: %s\n", path);
		}
	}
}
