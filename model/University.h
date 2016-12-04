//
// Created by DoYonghoon on 12/3/16.
//

#ifndef ASSIST_UNIVERSITY_H
#define ASSIST_UNIVERSITY_H

#include <iostream>
#include <string>
#include "../data_structure/SinglyLinkedList.h"
#include "Major.h"

using namespace std;

class University {
private:
    string name;
    string code;
    SinglyLinkedList<Major *> *majors;
public:
    University();

    University(string name, string code, SinglyLinkedList<Major *> *majors);

    string getName();

    string getNameCode();

    void setName(string name);

    void setCode(string code);

    void setMajors(SinglyLinkedList<Major *> *majors);

    SinglyLinkedList<Major *> *getMajors();

    ~University();
};


#endif //ASSIST_UNIVERSITY_H
