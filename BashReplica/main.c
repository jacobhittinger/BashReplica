/**
 * @file main.c
 * @author Jacob Hittinger
 * @date April 2016
 * @brief This is the main file for mysh
 *
 * Eastern Washington University
 * CSCD 340 - Operating Systems
 * Term Project - Bash Replica (mysh)
 */
#include "./cd/cd.h"
#include "./history/history.h"
#include "./linkedlist/linkedList.h"
#include "./linkedlist/listUtils.h"
#include "./linkedlist/requiredIncludes.h"
#include "./myshrc/startCheck.h"
#include "./path/path.h"
#include "./pipes/pipes.h"
#include "./process/process.h"
#include "./tokenize/makeArgs.h"
#include "./utils/myUtils.h"


// Global variables.
LinkedList * pathList;
LinkedList * historyList;
int histCount = 0; //from startCheck.h
int histFileCount = 0; //from startCheck.h
char origPath[100]; //from cd.h
char currPath[100]; //from cd.h

void setup() {
	// myshrc
	pathList = linkedList();
	loadDefaultPaths(pathList);
	readMYSHRC(pathList);

	// mysh_history
	historyList = linkedList();
	readHistFile(historyList);

	// directory
	getcwd(origPath, sizeof(origPath));
	getcwd(currPath, sizeof(currPath));
}

void cleanUp() {
	// directory
	cd(origPath);

	// mysh_history
	saveHistFile(historyList);
	clearList(historyList, cleanTypeH);
	free(historyList);
	historyList = NULL;

	// myshrc
	clearList(pathList, cleanTypeP);
	free(pathList);
	pathList = NULL;
}

void singlePipe(char * s) {
	char **prePipe = NULL, **postPipe = NULL;
	int preCount = 0, postCount = 0;

	prePipe = parsePrePipe(s, &preCount);
	postPipe = parsePostPipe(s, &postCount);
	pipeIt(prePipe, postPipe);
	clean(preCount, prePipe);
	clean(postCount, postPipe);
}

void doublePipe(char * s) {
	int cmd1 = 0, cmd2 = 0, cmd3 = 0;
	char *** args = NULL;

	args = parseDoublePipe(s, &cmd1, &cmd2, &cmd3);
	doublePipeIt(args);

	clean(cmd1, args[0]);
	clean(cmd2, args[1]);
	clean(cmd3, args[2]);

	free(args);
	args = NULL;
}

void noPipes(char * s) {
	int argc;
	char **argv = NULL;

	argc = makeargs(s, &argv);
	if (argc != -1) {
		if (strcmp(argv[0], "cd") == 0) {
			cd(argv[1]);
			getcwd(currPath, sizeof(currPath));
		} else if (strcmp(argv[0], "history") == 0) {
			printHistory(historyList);
		} else if (strcmp(argv[0], "$PATH") == 0) {
			printPaths(pathList);
		} else if (strstr(argv[0], "PATH=$PATH") != NULL) {
			addPath(pathList, argv);
		} else {
			forkIt(argv);
		}
	}
	clean(argc, argv);
	argv = NULL;
}

int main() {
	int pipeCount;
	char s[MAX];

	setup();

	// Main loop.
	do {
		printf("command?: %s$ ", currPath);
		fgets(s, MAX, stdin);
		addHistory(historyList, s);
		strip(s);

		if(strcmp(s, "exit") != 0) {
			pipeCount = countPipes(s);
			if (pipeCount == 1) {
				singlePipe(s);
			} else if (pipeCount == 2) {
				doublePipe(s);
			} else {
				noPipes(s);
			}
		}
	} while(strcmp(s, "exit") != 0);

	cleanUp();

	return 0;
}






