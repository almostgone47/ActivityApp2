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
#ifndef CS162CLASSES_ACTIVITY_H
#define CS162CLASSES_ACTIVITY_H

const int MAXCHAR = 51;

class Activity {
public:
    enum Type {athletic, food, arts, games, other};
    void setName(char *newName);
    void setLocation(char *newLocation);
    void setLevel(char *newLevel);
    void setRating(int newRating);
    void setType(Type newType);
    void getName(char *returnName) const;
    void getLocation(char *returnLocation);
    void getLevel(char *returnLevel);
    int getRating();
    Type getType();
    void printActivity();

private:
    char name[MAXCHAR];
    char location[MAXCHAR];
    char level[MAXCHAR];
    int rating;
    Type type;
};
#endif //CS162CLASSES_ACTIVITY_H
