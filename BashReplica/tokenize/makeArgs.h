#ifndef MAKEARGS_H
#define MAKEARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/myUtils.h"

#define MAX 100


/**
 * @brief Tokenizes the passed in String into a String array of arguments.
 *
 * Walks through the passed in String, counting the number of arguments
 * based on found ' ' values. Memory is then allocated for the array
 * and it is filled with the arguments.
 *
 * @param s - String to tokenize.
 * @param argv - String array to fill with arguments.
 *
 * @return int - Number of args.
 *
 * @warning - The passed in String is checked - returns -1 if length <= 0.
 */
int makeargs(char *s, char *** argv);

/**
 * @brief Prints the list of passed in arguments.
 *
 * Walks through the String array of arguments, printing each one.
 *
 * @param argc - Number of arguments.
 * @param argv - Array of arguments.
 */
void printargs(int argc, char **argv);

/**
 * @brief Free's the memory of the arguments and sets them to NULL.
 *
 * Walks through the String array of arguments, freeing each
 * one's allocated memory, and giving them NULL values. Then the
 * same is done to the array itself.
 *
 * @param argc - Number of arguments.
 * @param argv - Array of arguments.
 */
void clean(int argc, char **argv);

#endif
