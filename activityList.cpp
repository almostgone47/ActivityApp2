//
// Created by Jeremiah Barro on 16/4/2023.
//
#include <iostream>
#include <fstream>
#include "activityList.h"
#include "activity.h"
#include "tools.h"

using namespace std;

ActivityList::ActivityList() {
    size = 0;
}

ActivityList::ActivityList(char fileName[]) {
    size = 0;
    ifstream inFile;
    openFile(fileName, inFile);
    loadData(inFile);
}

//destructor
ActivityList::~ActivityList()
{
//nothing to do
}

int ActivityList::getNumActivities() {
    return size;
}

//void ActivityList::incNumActivities() {
//    size = size + 1;
//}

//Name:   addActivity()
//Desc:   Adds ref to newly created activity to array of all activities in memory.
//input:  array holding all activities currently in memory, number of activities in memory,
//        ref to activity being created.
//output: none
//return: none
void ActivityList::addActivity(const Activity &activity) {
    list[size++] = activity;
}

//Name:   showActivities()
//Desc:   Displays all activities currently in memory.
//input:  all activities currently in memory, the number of all activities
//output: Displays all activities with a number at the start of each line.
//return: none
void ActivityList::showActivities() {
    for(int i = 0; i < size; i++)
    {
        Activity activity = list[i];
        cout << i+1 << ".";
        activity.printActivity();
    }
    cout << endl;
};

//Name:   searchActivitiesByLocation()
//Desc:   Asks user for location of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void ActivityList::searchActivitiesByLocation() {
    char searchLocation[MAXCHAR];
    char tempLocation[MAXCHAR];
    cout << "Enter location name: ";
    cin.get(searchLocation, MAXCHAR, '\n');
    cout << endl;

    for(int i = 0; i < size; i++)
    {
        list[i].getLocation(tempLocation);
        if(strstr(searchLocation, tempLocation) != NULL)
        {
            list[i].printActivity();
        }
    }
}

//Name:   writeData()
//Desc:   Uses ofstream to write data from local file.
//input:  outFile to write to, all current activities in memory, number of activities
//output: A small response showing user has saved data.
//return: none
//void ActivityList::writeData(ofstream &outFile) {
//    for(int i = 0; i < size; i++)
//    {
//        outFile << list[i].printActivity() << endl;
//    }
//    outFile.close();
//    cout << "Activities written to file! Thank you for using my program!! " << endl;
//}

//Name:   loadData()
//Desc:   Uses ifstream to read data from local file.
//input:  inFile to read from, all current activities in memory, number of activities
//output: none
//return: none
void ActivityList::loadData(ifstream &inFile)
{
    Activity activity;
    char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR];
    int tempRating;
    Activity::Type tempType;
    char tempType2[51];

    inFile.get(tempName, MAXCHAR, ';');
    while(inFile)
    {
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempLocation, MAXCHAR, ';');
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempLevel, MAXCHAR, ';');
        inFile.ignore(MAXCHAR, ';');
        inFile >> tempRating;
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempType2, 2, ';');
        // showing int char in tempType, not a string, need to change the comparison
        if(strcmp(tempType2, "0") == 0)
        {
            tempType = Activity::athletic;
        }
        else if(strcmp(tempType2, "1") == 0)
        {
            tempType = Activity::food;
        }
        else if(strcmp(tempType2, "2") == 0)
        {
            tempType = Activity::arts;
        }
        else if(strcmp(tempType2, "3") == 0)
        {
            tempType = Activity::games;
        }
        else
        {
            tempType = Activity::other;
        }
        inFile.ignore(100, '\n');
        activity.setName(tempName);
        activity.setLocation(tempLocation);
        activity.setLevel(tempLevel);
        activity.setRating(tempRating);
        activity.setType(tempType);
        addActivity(activity);
        inFile.get(tempName, MAXCHAR, ';');
    }
    inFile.close();
}