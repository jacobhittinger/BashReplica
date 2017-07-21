#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "../tokenize/makeArgs.h"
#include "../utils/myUtils.h"


/**
 * @brief Forks and executes a command based on the passed in arguments.
 *
 * After forking, if the resulting PID is < 0, an error has occurred, and
 * exit(-99) is called. If the last argument is '&' it will be sent to background.
 * Regardless of backgroung or not, the command is executed via execvp().
 *
 * @param argv - String array of arguments.
 */
void forkIt(char ** argv);

#endif
