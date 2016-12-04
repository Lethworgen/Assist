//
// Created by DoYonghoon on 12/3/16.
//

#ifndef ASSIST_PARSER_H
#define ASSIST_PARSER_H

#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "model/University.h"

using namespace rapidjson;
using namespace std;

class Parser {
private:
    SinglyLinkedList<Course *> *instantiatedCourses;

    const char *parseJsonFile(string path);

    Course *generateCourse(string name);

public:
    int generateHashCode(string text);

    Parser();

    ~Parser();

    SinglyLinkedList<University> *getUniversities(string path);
};

SinglyLinkedList<University> *Parser::getUniversities(string path) {
    SinglyLinkedList<University> *result = new SinglyLinkedList<University>();
    Document d;
    d.Parse(parseJsonFile(path));
    Value &data = d["data"];
    Value::Array universities = d["data"]["universities"].GetArray();
    for (int i = 0; i < universities.Capacity(); i++) {
        // visiting university object.
        University *u = new University();
        Value &univ = universities[i];
        string name = univ["name"].GetString();
        string nameCode = univ["name_code"].GetString();
        Value::Array majors = univ["majors"].GetArray();

        SinglyLinkedList<Major> *tmpMajors = new SinglyLinkedList<Major>();
        for (int j = 0; j < majors.Capacity(); j++) {
            // visiting major object.
            Major *m = new Major();
            Value &major = majors[j];
            string majorName = major["name"].GetString();
            Value::Array courses = major["courses"].GetArray();

            BST<Course> *tmpCourses = new BST<Course>();
            for (int k = 0; k < courses.Capacity(); k++) {
                // visiting course string.
                string coursename = courses[k].GetString();
                Course *course = generateCourse(coursename);
                tmpCourses->insert(*course);
            }

            m->setName(majorName);
            m->setCourses(tmpCourses);
            tmpMajors->addLast(*m);
        }

        u->setName(name);
        u->setCode(nameCode);
        u->setMajors(tmpMajors);

        result->addLast(*u);
    }
    return result;
}

const char *Parser::parseJsonFile(string path) {
    ifstream ifs(path);
    string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    ifs.close();
    return content.c_str();
}

Parser::Parser() {
    instantiatedCourses = new SinglyLinkedList<Course *>();
}

Parser::~Parser() {
    instantiatedCourses->clear();
}

int Parser::generateHashCode(string text) {
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

Course *Parser::generateCourse(string name) {
    int hashedCode = generateHashCode(name);
    for (int i = 0; i < instantiatedCourses->getNumberOfNodes(); i++) {
        Course *tmp = instantiatedCourses->peek(i);
        if (tmp->getHashCode() == hashedCode) {
            return tmp;
        }
    }
    Course *c = new Course(name, hashedCode);
    instantiatedCourses->addLast(c);
    return c;
}

#endif //ASSIST_PARSER_H
