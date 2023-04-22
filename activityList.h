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
#ifndef CS162CLASSES_ACTIVITYLIST_H
#define CS162CLASSES_ACTIVITYLIST_H
#include "activity.h"

using namespace std;

const int CAP = 30;

class ActivityList {
private:
    Activity list[CAP];
    int size;
public:
    ActivityList();
    ActivityList(char []);
    ~ActivityList();

    void addActivity(const Activity &activity);
    int getNumActivities();
    void showActivities();
    void searchActivitiesByLocation();
    void searchActivitiesByType();
    void searchActivitiesByName();
    void loadData(ifstream &inFile);
    void removeActivity();
    void writeData(char fileName[]);

    int getInsertionPoint(char *tempName, char *insertName);
};
#endif //CS162CLASSES_ACTIVITYLIST_H
