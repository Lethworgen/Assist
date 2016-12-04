//
// Created by DoYonghoon on 12/3/16.
//

#include "University.h"

University::University(string name, string code, SinglyLinkedList<Major> *majors) {
    setName(name);
    this->code = code;
    this->majors = majors;
}

University::~University() {

}

University::University() {
    majors = nullptr;
}

void University::setName(string name) {
    this->name = name;
    hashcode = generateHashCode(name);
}

void University::setCode(string code) {
    this->code = code;
}

void University::setMajors(SinglyLinkedList<Major> *majors) {
    this->majors = majors;
}

string University::getName() const {
    return name;
}

string University::getNameCode() {
    return code;
}

SinglyLinkedList<Major> *University::getMajors() {
    return majors;
}

ostream &operator<<(ostream &os, const University *u) {
    os << u->name;
    return os;
}

ostream &operator<<(ostream &os, const University &u) {
    os << u.name;
    return os;
}

unsigned long University::generateHashCode(string text) {
    unsigned long hash = 0;
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

bool University::operator<(const University &b) {
    return hashcode < b.hashcode;
}

bool University::operator>(const University &b) {
    return hashcode > b.hashcode;
}

bool University::operator==(const University &b) {
    return hashcode == b.hashcode;
}

unsigned long University::getHashCode() const {
    return hashcode;
}

bool University::operator!=(const University &b) {
    return hashcode != b.hashcode;
}
