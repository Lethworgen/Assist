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

    SinglyLinkedList<Major> *majors;

    unsigned long generateHashCode(string text);

    unsigned long hashcode;

public:

    University();

    University(string name, string code, SinglyLinkedList<Major> *majors);

    string getName() const;

    string getNameCode();

    unsigned long getHashCode() const;

    void setName(string name);

    void setCode(string code);

    void setMajors(SinglyLinkedList<Major> *majors);

    SinglyLinkedList<Major> *getMajors();

    ~University();

    friend ostream &operator<<(ostream &os, const University *u);

    friend ostream &operator<<(ostream &os, const University &u);

    bool operator<(const University &b);

    bool operator>(const University &b);

    bool operator==(const University &b);

    bool operator!=(const University &b);

    friend const University
    operator%(const University &left,
              const University &right);
};


#endif //ASSIST_UNIVERSITY_H
