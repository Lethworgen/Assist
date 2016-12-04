//
// Created by DoYonghoon on 12/3/16.
//

#ifndef ASSIST_COURSE_H
#define ASSIST_COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    string name = "";
    int hashcode;
public:
    Course();

    Course(string name, int hashcode);

    Course(string name);

    ~Course();

    int generateHashCode(string text);

    string getName();

    int getHashCode();

    bool operator==(const Course &other);

    bool operator==(const Course *other);

    friend ostream &operator<<(ostream &os, const Course *b);

    friend ostream &operator<<(ostream &os, const Course &b);

    bool operator<(const Course &b);

    bool operator<(const Course *b);

    bool operator>(const Course &b);

    bool operator>(const Course *b);
};


#endif //ASSIST_COURSE_H
