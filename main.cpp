
#include <iostream>
#include "Parser.h"

using namespace std;

int hashCode(string text) {
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

int main() {
    Parser *parser = new Parser();
    SinglyLinkedList<University *> *universities = parser->getUniversities("data.json");
    for (int i = 0; i < universities->getNumberOfNodes(); i++) {
        University *u = universities->peek(i);
        string name = u->getName();
        cout << "universities: " << name << endl;
        SinglyLinkedList<Major *> *majors = u->getMajors();
        for (int j = 0; j < majors->getNumberOfNodes(); j++) {
            Major *m = majors->peek(j);
            string majorName = m->getName();
            cout << "major: " << majorName << endl;
            SinglyLinkedList<Course *> *courses = m->getCourses();
            for (int k = 0; k < courses->getNumberOfNodes(); k++) {
                cout << "course: " << courses->peek(k)->getName() << endl;
            }
        }
    }
    delete parser;
    return 0;
}