//
// Created by DoYonghoon on 12/3/16.
//

#include "Course.h"

string Course::getName() {
    return name;
}

Course::Course(string name, int hashcode) {
    this->name = name;
    this->hashcode = hashcode;
}

Course::~Course() {

}

int Course::getHashCode() {
    return hashcode;
}

bool Course::operator==(const Course &other) {
    return (this->getHashCode() == other.hashcode);
}
