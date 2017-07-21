#ifndef PIPEARG_H_
#define PIPEARG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pipeArg
{
   char ** command;
};
typedef struct pipeArg PipeArg;

/**
 * @brief Constructor for the PipeArg struct.
 *
 * Returns a new PipeArg object, with a NULL command field.
 *
 * @return PipeArg - The new PipeArg object.
 */
PipeArg * pipeArg();

/**
 * @brief Free's memory allocated to the PipeArg object, and sets to NULL.
 *
 * @param ptr - Pointer to a PipeArg object.
 *
 * @warning - The passed in pointer is checked - exit(-99) if NULL.
 */
void cleanTypePA(void * ptr);

#endif
