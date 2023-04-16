//
// Created by Jeremiah Barro on 16/4/2023.
//

#ifndef CS162CLASSES_ACTIVITYLIST_H
#define CS162CLASSES_ACTIVITYLIST_H
#include "activity.h"

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
    void loadData(std::ifstream &inFile);
    void removeActivity();
//
//    void incNumActivities();
//    void searchActivitiesByName(const Activity activities[], int numActivities);
//    void removeActivity(Activity activities[], int &numActivities);
//    void addActivity(Activity activities[], int &numActivities, const Activity &activity);
//
//    void displayActivityMenu();
//    char getUserInput();
//    int readInt();
//    Activity::Type readType(char num);
//    void loadData(std::ifstream &inFile);
//    void writeData(std::ofstream &outFile);
};
#endif //CS162CLASSES_ACTIVITYLIST_H
