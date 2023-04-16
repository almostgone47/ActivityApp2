//
// Created by Jeremiah Barro on 16/4/2023.
//
#include <cstring>
#include <iostream>
#include "activity.h"

using namespace std;

void Activity::setName(char *newName) {
    strcpy(name, newName);
};

void Activity::setLocation(char *newLocation) {
    strcpy(location, newLocation);
};

void Activity::setLevel(char *newLevel) {
    strcpy(level, newLevel);
};

void Activity::setRating(int newRating) {
    rating = newRating;
};

void Activity::setType(Type newType) {
    type = newType;
};

void Activity::getName(char *returnName) {
    strcpy(returnName, name);
};

void Activity::getLocation(char *returnLocation) {
    strcpy(returnLocation, location);
};

void Activity::getLevel(char *returnLevel) {
    strcpy(returnLevel, level);
};

int Activity::getRating() {
    return rating;
};

Activity::Type Activity::getType() {
    return type;
};

void Activity::printActivity() {
    cout << name << ";" << location << ";" << level << ";" << rating << ";" << type << endl;
}