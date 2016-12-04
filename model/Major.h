//
// Created by DoYonghoon on 12/3/16.
//

#ifndef ASSIST_MAJOR_H
#define ASSIST_MAJOR_H

#include <iostream>
#include <string>
#include "Course.h"
#include "../data_structure/BST.h"

using namespace std;

class Major {
private:
    string name;
    int hashcode;
    BST<Course> *courses;

    int generateHashCode(string text);

public:
    Major();

    Major(string name, BST<Course> *courses);

    string getName();

    void setName(string name);

    void setCourses(BST<Course> *courses);

    BST<Course> *getCourses();

    ~Major();

    void clear();

    friend ostream &operator<<(ostream &os, const Major *b);

    friend ostream &operator<<(ostream &os, const Major &b);

    bool operator<(const Major &b);

    bool operator>(const Major &b);

    bool operator==(const Major &other);
};


#endif //ASSIST_MAJOR_H
