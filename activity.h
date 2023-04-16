//
// Created by Jeremiah Barro on 16/4/2023.
//

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
    void getName(char *returnName);
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
