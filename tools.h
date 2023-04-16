//
// Created by Jeremiah Barro on 16/4/2023.
//

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
