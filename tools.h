/******************************************************************************
# Author:           Jeremiah Barro
# Assignment:       Assignment 1, Classes Assignment
# Date:             April 16th, 2023
# Description:      This is a console app that allows users to create, read
                    and destroy Activities which are read and stored to a local
                    file.
# Input:            String input through console and a file input for storage.
# Output:           Outputs results to screen and writes to local file.
# Sources:          N/A
#*****************************************************************************/
#ifndef CS162CLASSES_TOOLS_H
#define CS162CLASSES_TOOLS_H
#include <iostream>

using namespace std;

// function prototypes
void displayActivityMenu();
char getUserInput();
void executeCmd(char userInput, ActivityList &activityList);
void openFile(char fileName[], ifstream &inFile);
Activity::Type readType(char num);
void openFile(char fileName[], ofstream &outFile);
void addActivity(Activity &activity);

#endif //CS162CLASSES_TOOLS_H
