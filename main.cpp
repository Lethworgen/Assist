
#include <iostream>
#include "Parser.h"
#include "data_structure/HashMap.h"

using namespace std;

void putBestMatched(HashMap<University, BST<Major>> *map,
                    SinglyLinkedList<University> *keyList,
                    University key, Major value) {
    BST<Major> majors;
    bool found = map->get(key, majors);
    if (found) {
        majors.insert(value);
    } else {
        majors.insert(value);
        keyList->addLast(key);
    }
    map->put(key, majors);
}

void showBestMathcedMajors(Parser *parser, SinglyLinkedList<Course> *input,
                           SinglyLinkedList<University> *universities,
                           SinglyLinkedList<University> *keyList,
                           HashMap<University, BST<Major>> *map) {
    for (int start = 0; start < input->getNumberOfNodes(); start++) {
        for (int i = 0; i < universities->getNumberOfNodes(); i++) {
            University u = universities->peek(i);
            string name = u.getName();
            SinglyLinkedList<Major> *majors = u.getMajors();
            for (int j = 0; j < majors->getNumberOfNodes(); j++) {
                Major m = majors->peek(j);
                string majorName = m.getName();
                BST<Course> *courses = m.getCourses();
                bool found = courses->search(input->peek(start));
                if (found) {
                    putBestMatched(map, keyList, u, m);
                }
            }
        }
    }

    for (int i = 0; i < keyList->getNumberOfNodes(); i++) {
        cout << "university: " << keyList->peek(i).getName() << endl;
        BST<Major> foundMajors;
        map->get(keyList->peek(i), foundMajors);
        foundMajors.breadthfirst()->display();
    }
}

void createDummyInput(SinglyLinkedList<Course> *input) {
    Course *tmpCourse1 = new Course("HIST 17C");
    Course *tmpCourse2 = new Course("HIST 17A");
    Course *tmpCourse3 = new Course("HIST 17B");
    Course *tmpCourse4 = new Course("PHYS 4D");
    input->addLast(*tmpCourse1);
    input->addLast(*tmpCourse2);
    input->addLast(*tmpCourse3);
    input->addLast(*tmpCourse4);
}

void showMissingCourses(SinglyLinkedList<Course> *input, BST<Course> *courses) {
    for (int i = 0; i < courses->getNumberOfItems(); i++) {
        for (int j = 0; j < input->getNumberOfNodes(); j++) {
            Course c = input->peek(j);
            courses->remove(c);
        }
    }
    courses->inorder()->display();
}

void writeMissingCourses(string majorName, BST<Course> *courses) {
    ofstream out("missing_courses.txt");
    out << "===================" << endl;
    out << majorName << endl;
    out << "===================" << endl;
    Queue<Course> *result = courses->inorder();
    while (!result->isEmpty()) {
        Course c = result->peekFront();
        result->dequeue();
        out << c << endl;
    }
    out.close();
}

int main() {
    SinglyLinkedList<Course> *input = new SinglyLinkedList<Course>();
    SinglyLinkedList<University> *keyList = new SinglyLinkedList<University>();
    HashMap<University, BST<Major>> *map = new HashMap<University, BST<Major>>();
    Parser *parser = new Parser();
    SinglyLinkedList<University> *universities = parser->getUniversities("data.json");

    createDummyInput(input);
    showBestMathcedMajors(parser, input, universities, keyList, map);

    // missing courses
    Major missingCourseMajor = keyList->peek(0).getMajors()->peek(0);
    showMissingCourses(input, missingCourseMajor.getCourses());
    writeMissingCourses(missingCourseMajor.getName(), missingCourseMajor.getCourses());

    input->clear();
    keyList->clear();
    universities->clear();
    delete map;
    delete parser;
    delete input;
    return 0;
}