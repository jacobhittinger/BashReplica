#ifndef PATH_H_
#define PATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct path {
	char * val;
};
typedef struct path Path;

/**
 * @brief Constructor for the Path struct.
 *
 * Returns a new Path object, with a NULL val field.
 *
 * @return Path - The new Path object.
 */
Path * path();

/**
 * @brief Prints the path value, followed by a ':'.
 *
 * @param passedIn - A void* which needs to be a Path object.
 *
 * @warning - The passed in void* is checked, exit(-99) if NULL.
 */
void printTypeP(void * passedIn);

/**
 * @brief Builds a new Path object from the contents of a file.
 *
 * @param fin - File* to read the new path from.
 *
 * @return void* - The new Path object, as a void*.
 */
void * buildTypeP(FILE * fin);

/**
 * @brief Builds a new Path object from user's input after being prompted.
 *
 * @param in - File* to take user input.
 *
 * @return void* - The new Path object, as a void*.
 */
void * buildType_PromptP(FILE * in);

/**
 * @brief Compares the two passed in Paths.
 *
 * @param ptr1 - Pointer to a Path object.
 * @param ptr2 - Pointer to a Path object.
 *
 * @note There is currently no need for this method, it will return 0 every time.
 *
 * @return int - Returns result. Which as of now is 0 every time.
 */
int compareP(const void * ptr1, const void * ptr2);

/**
 * @brief Free's memory allocated to the Path object, and sets to NULL.
 *
 * @param ptr - Pointer to a Path object.
 *
 * @warning - The passed in pointer is checked - exit(-99) if NULL.
 */
void cleanTypeP(void * ptr);

#endif
