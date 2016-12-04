//
// Created by DoYonghoon on 12/3/16.
//

#include "Major.h"

Major::Major(string name, BST<Course> *courses) {
    setName(name);
    setCourses(courses);
}

void Major::setName(string name) {
    this->name = name;
    hashcode = generateHashCode(name);
}

void Major::setCourses(BST<Course> *courses) {
    this->courses = courses;
}

BST<Course> *Major::getCourses() {
    return courses;
}

Major::Major() {
    name = "";
    hashcode = 0;
}

Major::~Major() {

}

void Major::clear() {

}

string Major::getName() {
    return name;
}

ostream &operator<<(ostream &os, const Major *m) {
    os << m->name;
    return os;
}

ostream &operator<<(ostream &os, const Major &m) {
    os << m.name;
    return os;
}

bool Major::operator<(const Major &b) {
    return hashcode < b.hashcode;
}

bool Major::operator>(const Major &b) {
    return hashcode > b.hashcode;
}

bool Major::operator==(const Major &other) {
    return hashcode == other.hashcode;
}

int Major::generateHashCode(string text) {
    int hash = 0;
    size_t strlen = text.length(), i;
    char character;
    if (strlen == 0) {
        return hash;
    }
    for (i = 0; i < strlen; i++) {
        character = text.at(i);
        hash = (31 * hash) + (character);
    }
    return hash;
}
