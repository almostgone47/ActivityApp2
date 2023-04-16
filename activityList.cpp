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
}

int ActivityList::getNumActivities() {
    return size;
}

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

    bool activityFound = false;
    for(int i = 0; i < size; i++)
    {
        list[i].getLocation(tempLocation);
        if(strstr(searchLocation, tempLocation) != NULL)
        {
            activityFound = true;
            list[i].printActivity();
        }
    }

    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   searchActivitiesByType()
//Desc:   Asks user for type of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void ActivityList::searchActivitiesByType() {
    char letter;
    Activity::Type tempType;
    cout << "Enter Type number(0-Athletic, 1-Food, 2-Arts, 3-Games, 4-Other): ";
    cin >> letter;

    bool activityFound = false;
    tempType = readType(letter);
    for(int i = 0; i < size; i++)
    {
        Activity::Type type = list[i].getType();
        if(type == tempType)
        {
            activityFound = true;
            list[i].printActivity();
        }
    }

    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   searchActivitiesByName()
//Desc:   Asks user for name of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void ActivityList::searchActivitiesByName() {
    char searchName[MAXCHAR];
    char activityName[MAXCHAR];
    cout << "Enter the activity name (50 characters or less): ";
    cin.get(searchName, MAXCHAR, '\n');
    cout << endl;

    bool activityFound = false;
    for(int i = 0; i < size; i++)
    {
        list[i].getName(activityName);
        if(strstr(searchName, activityName) != NULL)
        {
            activityFound = true;
            list[i].printActivity();
        }
    }

    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   removeActivity()
//Desc:   Removes activity from all activities in array stored in memory.
//input:  array holding all activities currently in memory, number of activities in memory
//output: none
//return: none
void ActivityList::removeActivity() {
    int index;
    cout << "Pick the index to remove: ";
    cin >> index;
    cin.ignore(100, '\n');
    cout << endl;

    if(index < size && index > -1)
    {
        for(int i = index; i < size; i++)
        {
            list[i-1] = list[i];
        }
    }
    size--;
    cout << "Activity removed! " << endl;
}

//Name:   writeData()
//Desc:   Uses ofstream to write data from local file.
//input:  outFile to write to, all current activities in memory, number of activities
//output: A small response showing user has saved data.
//return: none
void ActivityList::writeData(char fileName[]) {
    ofstream outFile;
    openFile(fileName, outFile);
    char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR];
    int tempRating;
    Activity::Type tempType;

    for(int i = 0; i < size; i++)
    {
        list[i].getName(tempName);
        list[i].getLocation(tempLocation);
        list[i].getLevel(tempLevel);
        tempRating = list[i].getRating();
        tempType = list[i].getType();
        outFile << tempName << ";" << tempLocation << ";" << tempLevel << ";" << tempRating << ";" << tempType << endl;
    }
    outFile.close();
    cout << "Activities written to file! Thank you for using my program!! " << endl;
}

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