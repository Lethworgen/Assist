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
    string name;
    int hashcode;
public:
    Course(string name, int hashcode);

    ~Course();

    string getName();

    int getHashCode();

    bool operator==(const Course &other);
};


#endif //ASSIST_COURSE_H
