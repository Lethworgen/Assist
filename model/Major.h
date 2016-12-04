//
// Created by DoYonghoon on 12/3/16.
//

#ifndef ASSIST_MAJOR_H
#define ASSIST_MAJOR_H

#include <iostream>
#include <string>
#include "../data_structure/SinglyLinkedList.h"
#include "Course.h"

using namespace std;

class Major {
private:
    string name;
    SinglyLinkedList<Course *> *courses;
public:
    Major();

    Major(string name, SinglyLinkedList<Course *> *courses);

    string getName();

    void setName(string name);

    void setCourses(SinglyLinkedList<Course *> *courses);

    SinglyLinkedList<Course *> *getCourses();

    ~Major();

    void clear();
};


#endif //ASSIST_MAJOR_H
