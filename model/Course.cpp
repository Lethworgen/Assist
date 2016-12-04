//
// Created by DoYonghoon on 12/3/16.
//

#include "Course.h"

Course::Course(string name) {
    this->name = name;
    this->hashcode = generateHashCode(name);
}

Course::Course(string name, int hashcode) {
    this->name = name;
    this->hashcode = hashcode;
}

Course::~Course() {

}

string Course::getName() {
    return name;
}

int Course::getHashCode() {
    return hashcode;
}

bool Course::operator==(const Course &other) {
    return hashcode == other.hashcode;
}

bool Course::operator<(const Course &b) {
    return hashcode < b.hashcode;
}

bool Course::operator>(const Course &b) {
    return hashcode > b.hashcode;
}

int Course::generateHashCode(string text) {
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

ostream &operator<<(ostream &os, const Course *b) {
    os << b->name;
    return os;
}

ostream &operator<<(ostream &os, const Course &b) {
    os << b.name;
    return os;
}

bool Course::operator==(const Course *other) {
    return hashcode == other->hashcode;
}

bool Course::operator<(const Course *b) {
    return hashcode == b->hashcode;
}

bool Course::operator>(const Course *b) {
    return hashcode == b->hashcode;
}

Course::Course() {
    name = "";
    hashcode = 0;
}
