/******************************************************************************
# Author:           Jeremiah Barro
# Assignment:       Assignment 1, Structs Review Assignment
# Date:             April 16th, 2023
# Description:      This is a console app that allows users to create, read
                    and destroy Activities which are read and stored to a local
                    file.
# Input:            String input through console and a file input for storage.
# Output:           Outputs results to screen and writes to local file.
# Sources:          N/A
#*****************************************************************************/
#include <iostream>
#include <fstream>
#include "activityList.h"
#include "activity.h"
#include "tools.h"
#include "main.h"

//Name:   main()
//Desc:   This the entry point to the application.
//input:  None
//output: prompt
//return: int 0 for program finished
int main() {
    char fileName[MAXCHAR] = "activities.txt";
    ActivityList activityList(fileName);
    char userInput;

    do
    {
        displayActivityMenu();

        userInput = getUserInput();

        executeCmd(userInput, activityList);

    } while (tolower(userInput != 'q'));

    activityList.writeData(fileName);

    return 0;
}
