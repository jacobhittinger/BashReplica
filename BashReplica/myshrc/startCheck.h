#ifndef STARTCHECK_H
#define STARTCHECK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

#include "../linkedlist/linkedList.h"
#include "../linkedlist/listUtils.h"
#include "../utils/myUtils.h"
#include "../history/history.h"
#include "../path/path.h"
#include "../linkedlist/requiredIncludes.h"


// Global variables.
extern int histCount; // Max number of history entries to print to terminal.
extern int histFileCount; // Max number of history entries to save to .mysh_history file.

/**
 * @brief Adds the default paths to pathList
 *
 * @param pathList - The LinkedList* to add the default paths to.
 */
void loadDefaultPaths(LinkedList * pathList);

/**
 * @brief Assigns values to histCount and histFileCount based off of the .myshrc file.
 *
 * Checks to see if the .myshrc file exists. If it does, we get our values, and add any
 * other paths in the file to our pathList, otherwise, default values of histCount=1000
 * and histFileCount=2000 are used.
 *
 * @param pathList - The LinkedList* to add the default paths to.
 */
void readMYSHRC(LinkedList * pathList);

/**
 * @brief Checks if the .myshrc file exists.
 *
 * @return int - If it exists in the myshrc folder, returns 1.
 * If it exists in the parent directory (where main.c is), returns 2.
 * Returns 0 if it doesn't exist.
 */
int checkMYSHRC();

/**
 * @brief Adds a new path the the path list.
 *
 * Tokenizes out the new path and adds is to the LinkedList
 * which is the list of paths.
 *
 * @param pathList - The list of paths.
 * @param argv - The new path to be added.
 */
void addPath(LinkedList * pathList, char ** argv);

/**
 * @brief Prints every entry in pathList.
 *
 * @param pathList - The LinkedList* of paths.
 */
void printPaths(LinkedList * pathList);

/**
 * @brief Loads the .mysh_history file.
 *
 * Checks to see if the .mysh_history file exists. If it does, it is loaded,
 * otherwise, it is created.
 *
 * @param histList - The LinkedList* to add the history entries to.
 */
void readHistFile();

/**
 * @brief Checks if the .mysh_history file exists.
 *
 * @return int - If it exists in the myshrc folder, returns 1.
 * If it exists in the parent directory (where main.c is), returns 2.
 * Returns 0 if it doesn't exist.
 */
int checkHistFile();

/**
 * @brief Adds a new history entry to the historyList.
 *
 * @note Called after every command is entered at the command line.
 *
 * @param historyList - The LinkedList* of history records.
 * @param s - The new command to add to historyList.
 */
void addHistory(LinkedList * historyList, char * s);

/**
 * @brief Prints up to histCount number of the most recent history entries.
 *
 * @param historyList - The LinkedList* of history records.
 */
void printHistory(LinkedList * historyList);

/**
 * @brief Saves up to histFileCount number of history entries to the .mysh_history file.
 *
 * @param historyList - The LinkedList* of history records.
 */
void saveHistFile(LinkedList * historyList);

#endif
