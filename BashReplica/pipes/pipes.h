#ifndef PIPES_H
#define PIPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "../tokenize/makeArgs.h"


/**
 * @brief Counts the number of pipes in a String.
 *
 * Walks through the passed in String, counting the number of pipes.
 *
 * @param s - String in which to look for pipes.
 *
 * @return int - Number of pipes.
 */
int countPipes(char *s);

/**
 * @brief Executes a statement which contains one pipe.
 *
 * @param prePipe - Arguments before the pipe.
 * @param postPipe - Arguments after the pipe.
 */
void pipeIt(char ** prePipe, char ** postPipe);

/**
 * @brief Parses the String before a pipe, and creates arguments based on it.
 *
 * Grabs the String before a pipe and tokenizes it for arguments. The PreCount
 * pointer is also used in order to give back the number of arguments before
 * the pipe as well.
 *
 * @param s - String to parse.
 * @param preCount - An int* to give the number of arguments to.
 *
 * @return char** - Arguments from the String preceding a pipe.
 */
char ** parsePrePipe(char *s, int * preCount);

/**
 * @brief Parses the String after a pipe, and creates arguments based on it.
 *
 * Grabs the String after a pipe and tokenizes it for arguments. The PostCount
 * pointer is also used in order to give back the number of arguments after
 * the pipe as well.
 *
 * @param s - String to parse.
 * @param postCount - An int* to give the number of arguments to.
 *
 * @return char** - Arguments from the String after a pipe.
 */
char ** parsePostPipe(char *s, int * postCount);

/**
 * @brief Executes a statement which contains two pipe.
 *
 * @param args - Arguments to be executed.
 */
void doublePipeIt(char *** args);

/**
 * @brief Parses String with two pipes, creating arguments for each individual command.
 *
 * Receives a String with two pipes, tokenizes each of the three individual commands,
 * creates arguments for each of those commands, sets int*'s to indicate the number
 * of arguments in each, and then returns the list of all arguments.
 *
 * @param s - String to parse.
 * @param cmd1 - An int* to give back the number of arguments in the first command.
 * @param cmd2 - An int* to give back the number of arguments in the second command.
 * @param cmd3 - An int* to give back the number of arguments in the third command.
 *
 * @return char*** - Arguments for each of the three commands contained in the
 * command with two pipes.
 */
char *** parseDoublePipe(char * s, int * cmd1, int * cmd2, int * cmd3);

#endif
