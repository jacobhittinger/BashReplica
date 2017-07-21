#ifndef CD_H
#define CD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>


// Global variables.
extern char origPath[100];
extern char currPath[100];

/**
 * @brief Changes the current working directory.
 */
void cd(char * path);

#endif
