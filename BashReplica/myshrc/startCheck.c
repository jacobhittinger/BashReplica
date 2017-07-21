#include "startCheck.h"


void loadDefaultPaths(LinkedList * pathList) {
	char * defaultPaths[8] = { "/usr/local/sbin", "/usr/local/bin", "/usr/sbin",
			"/usr/bin", "/sbin", "/bin", "/usr/games", "/usr/local/games" };
	Path * p;
	void * v;
	Node * n;

	int i;
	for (i = 0; i < 8; i++) {
		p = path();
		p->val = malloc(sizeof(char) * strlen(defaultPaths[i]) + 1);
		strcpy(p->val, defaultPaths[i]);
		v = p;
		n = buildNode_Type(v);
		addLast(pathList, n);
		n = NULL;
		p = NULL;
		v = NULL;
	}

	n = NULL;
	p = NULL;
	v = NULL;
}

void readMYSHRC(LinkedList * pathList) {
	int count = 1000; // default value
	int fileCount = 2000; // default value
	int res;
	FILE * fp;

	res = checkMYSHRC();
	if (res == 1) {
		fp = fopen("./myshrc/.myshrc", "r");
	} else if (res == 2) {
		fp = fopen("../.myshrc", "r");
	}
	if (res == 1 || res == 2) {
		char * buf = malloc(100 * sizeof(char));
		int temp = 0;
		char * token;

		// histCount
		fgets(buf, 100, fp);
		token = strtok(buf, "=");
		token = strtok(NULL, "=");
		sscanf(token, "%d", &temp);
		if (temp > -1) {
			count = temp;
		}

		// histFileCount
		temp = 0;
		fgets(buf, 100, fp);
		token = strtok(buf, "=");
		token = strtok(NULL, "=");
		sscanf(token, "%d", &temp);
		if (temp > -1) {
			fileCount = temp;
		}

		// path stuff from .myshrc
		Path * p;
		void * v;
		Node * n;

		fgets(buf, 100, fp); // reads 3rd line which is empty

		while (!feof(fp)) {
			fgets(buf, 100, fp);
			if (buf[0] != '\n') {
				buf[strlen(buf) - 1] = '\0';
				token = NULL;
				token = strtok(buf, ":");
				if (strcmp(token, "PATH=$PATH") == 0) {
					token = strtok(NULL, ":");

					p = path();
					p->val = malloc(sizeof(char) * strlen(token) + 1);
					strcpy(p->val, token);
					v = p;
					n = buildNode_Type(v);
					addLast(pathList, n);

					n = NULL;
					p = NULL;
					v = NULL;
				}
			}
		}

		fclose(fp);
		free(buf);
		buf = NULL;
		n = NULL;
		p = NULL;
		v = NULL;
	}

	histCount = count;
	histFileCount = fileCount;
}

int checkMYSHRC() {
	if (access("./myshrc/.myshrc", F_OK) != -1) {
		return 1; // exists
	} else if (access("../.myshrc", F_OK) != -1) {
		return 2; // exists in main folder containing our main.c file
	} else {
		return 0; // does not exist
	}
}

void addPath(LinkedList * pathList, char ** argv) {
	char * token;
	Path * p;
	void * vPtrPath;
	Node * node;

	token = strtok(argv[0], ":");
	token = strtok(NULL, ":");

	p = path();
	p->val = malloc(sizeof(char) * strlen(token) + 1);
	strcpy(p->val, token);

	vPtrPath = p;
	node = buildNode_Type(vPtrPath);

	addLast(pathList, node);

	node = NULL;
	p = NULL;
	vPtrPath = NULL;
}

void printPaths(LinkedList * pathList) {
	printf("%s", "mysh: ");
	printList(pathList, printTypeP);
	printf("\n");
}

void readHistFile(LinkedList * histList) {
	FILE * fin;
	int r;

	r = checkHistFile();
	if (r == 1) {
		fin = fopen("./myshrc/.mysh_history", "r");
	} else if (r == 2) {
		fin = fopen("../.mysh_history", "r");
	}

	if (r == 1 || r == 2) { // exists, load the .mysh_history file
		int total = 0;
		total = readTotal(fin);
		buildListH(histList, total, fin, buildTypeH);
		fclose(fin);
	} else { // does not exist, create the .mysh_history file
		FILE * fp = fopen("./myshrc/.mysh_history", "w");
		fclose(fp);
	}
}

int checkHistFile() {
	if (access("./myshrc/.mysh_history", F_OK) != -1) {
		return 1; // exists
	} else if(access("../.mysh_history", F_OK) != -1) {
		return 2; // exists in main folder containing our main.c file
	} else {
		return 0; // does not exist
	}
}

void addHistory(LinkedList * historyList, char * s) {
	History * h = history();
	h->num = (historyList->size + 1);
	h->command = malloc(sizeof(char) * strlen(s) + 1);
	strcpy(h->command, s);

	void * v = h;

	Node * n = buildNode_Type(v);
	addLast(historyList, n);

	n = NULL;
	h = NULL;
	v = NULL;
}

void printHistory(LinkedList * historyList) {
	if (historyList == NULL || historyList->size == 0) {
		printf("%s\n", "No history to display");
	} else if (historyList->size > histCount) { // above limit
		int diff = historyList->size - histCount;
		Node * cur = historyList->head;
		int i;
		for (i = 1; i <= diff; i++) {
			cur = cur->next;
		}
		if (diff < historyList->size) {
			diff = diff + 1;
			for (i = diff; i <= historyList->size; i++) {
				cur = cur->next;
				printTypeH(cur->data);
			}
		}
	} else { // under limit
		Node * cur = historyList->head;
		int i;
		for (i = 1; i <= historyList->size; i++) {
			cur = cur->next;
			printTypeH(cur->data);
		}
	}
}

void saveHistFile(LinkedList * historyList) {
	remove("./myshrc/.mysh_history");
	FILE * fp = fopen("./myshrc/.mysh_history", "w");

	if (historyList->size > histFileCount) { // above limit
		int diff = historyList->size - histFileCount;
		Node * cur = historyList->head;
		int i;
		for (i = 1; i <= diff; i++) {
			cur = cur->next;
		}
		if (diff < historyList->size) {
			diff = diff + 1;
			for (i = diff; i <= historyList->size; i++) {
				cur = cur->next;
				fprintf(fp, "%d %s", ((History *) cur->data)->num,
						((History *) cur->data)->command);
			}
		}
	} else { // under limit
		Node * cur = historyList->head;
		int i;
		for (i = 1; i <= historyList->size; i++) {
			cur = cur->next;
			fprintf(fp, "%d %s", ((History *) cur->data)->num,
					((History *) cur->data)->command);
		}
	}

	fclose(fp);
}
