#ifndef HISTORY_H_
#define HISTORY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct history {
	int num;
	char * command;
};
typedef struct history History;

/**
 * @brief Constructor for the History struct.
 *
 * Returns a new History object, with num=0 and a NULL command field.
 *
 * @return History - The new History object.
 */
History * history();

/**
 * @brief Prints the History entry.
 *
 * @param passedIn - A void* which needs to be a History object.
 *
 * @warning - The passed in void* is checked, exit(-99) if NULL.
 */
void printTypeH(void * passedIn);

/**
 * @brief Builds a new History object from the contents of a file and passed in number.
 *
 * @param fin - File* to read the new history entry from.
 * @param num - The number in the historyList that it is.
 *
 * @return void* - The new History object, as a void*.
 */
void * buildTypeH(FILE * fin, int n);

/**
 * @brief Builds a new History object from user's input after being prompted.
 *
 * @param in - File* to take user input.
 *
 * @return void* - The new History object, as a void*.
 */
void * buildType_PromptH(FILE * in);

/**
 * @brief Compares the two passed in History objects.
 *
 * @param ptr1 - Pointer to a History object.
 * @param ptr2 - Pointer to a History object.
 *
 * @return int - Returns result of ptr1's entry number minus ptr2's entry number.
 */
int compareH(const void * ptr1, const void * ptr2);

/**
 * @brief Free's memory allocated to the History object, and sets to NULL.
 *
 * @param ptr - Pointer to a History object.
 *
 * @warning - The passed in pointer is checked - exit(-99) if NULL.
 */
void cleanTypeH(void * ptr);

#endif
