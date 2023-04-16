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
//    void incNumActivities();
    int getNumActivities();
    void showActivities();
    void searchActivitiesByLocation();
    void loadData(std::ifstream &inFile);
//
//    void searchActivitiesByType(const Activity activities[], int numActivities);
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
