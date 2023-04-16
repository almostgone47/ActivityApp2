//
// Created by Jeremiah Barro on 16/4/2023.
//

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
};
#endif //CS162CLASSES_ACTIVITYLIST_H
