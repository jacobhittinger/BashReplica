/**
 * @file myUtils.h
 * @author Stu Steiner
 * @date 29 Dec 2015
 * @brief The basic myUtils.h that will be used during the quarter
 *
 * The myUtils.h defines the basic menu and strip functions that will be
 * required during the course of the quarter.
 */
#ifndef MYUTILS_H
#define MYUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../linkedlist/linkedList.h"
#include "../linkedlist/listUtils.h"

#define MAX 100


/**
 * @brief Prompts the user for a menu choice.
 *
 * Prompts the user for a menu choice and ensures the value
 * entered by the user is within range.
 *
 * @note The carriage return is removed from the input buffer
 *
 * @return int - Representing the menu choice
 */
int menu();

/**
 * @brief Strips the \r and \n from the string if they exist.
 *
 * Walks through the character array one character at a time
 * if a '\r' or '\n' are encountered it is changed to a '\0'
 * entered by the user is within range.
 *
 * @param The character array potentially containing a '\r' and/or '\n'
 *
 * @warning - The passed in pointer is checked - exit(-99) if NULL
 */
void strip(char *array);

/**
 * @brief Reads total number of lines in a file.
 *
 * Walks through the file one character at a time
 * if a '\n' is encountered, count is iterated by 1.
 *
 * @param The file in which lines need to be counted.
 *
 * @warning - The passed in file is checked - exit(-99) if NULL
 */
int readTotal(FILE * fin);

#endif
