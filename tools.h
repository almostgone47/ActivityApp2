//
// Created by Jeremiah Barro on 16/4/2023.
//

#ifndef CS162CLASSES_TOOLS_H
#define CS162CLASSES_TOOLS_H
#include "iostream";

// function prototypes
void displayActivityMenu();
char getUserInput();
void executeCmd(char userInput, ActivityList &activityList);
void openFile(char fileName[], std::ifstream &inFile);
void openFile(char fileName[], std::ofstream &outFile);
void addActivity(Activity);


#endif //CS162CLASSES_TOOLS_H
