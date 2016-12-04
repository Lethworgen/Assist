//
// Created by DoYonghoon on 12/3/16.
//

#include "Major.h"

Major::Major(string name, SinglyLinkedList<Course *> *courses) {
    setName(name);
    setCourses(courses);
}

void Major::setName(string name) {
    this->name = name;
}

void Major::setCourses(SinglyLinkedList<Course *> *courses) {
    this->courses = courses;
}

SinglyLinkedList<Course *> *Major::getCourses() {
    return courses;
}

Major::Major() {

}

Major::~Major() {

}

void Major::clear() {

}

string Major::getName() {
    return name;
}
