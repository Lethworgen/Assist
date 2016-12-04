//
// Created by DoYonghoon on 12/3/16.
//

#include "University.h"

University::University(string name, string code, SinglyLinkedList<Major *> *majors) {
    this->name = name;
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
}

void University::setCode(string code) {
    this->code = code;
}

void University::setMajors(SinglyLinkedList<Major *> *majors) {
    this->majors = majors;
}

string University::getName() {
    return name;
}

string University::getNameCode() {
    return code;
}

SinglyLinkedList<Major *> *University::getMajors() {
    return majors;
}
