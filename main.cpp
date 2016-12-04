
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

int main() {
    SinglyLinkedList<Course> *input = new SinglyLinkedList<Course>();
    Course *tmpCourse1 = new Course("HIST 17B");
    Course *tmpCourse2 = new Course("HIST 17A");
    Course *tmpCourse3 = new Course("HIST 17C");
    Course *tmpCourse4 = new Course("PHYS 4D");
    input->addLast(*tmpCourse1);
    input->addLast(*tmpCourse2);
    input->addLast(*tmpCourse3);
    input->addLast(*tmpCourse4);

    SinglyLinkedList<University> *keyList = new SinglyLinkedList<University>();
    HashMap<University, BST<Major>> *map = new HashMap<University, BST<Major>>();
    Parser *parser = new Parser();
    SinglyLinkedList<University> *universities = parser->getUniversities("data.json");

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

    // missing courses
    SinglyLinkedList<Course> missing;
    Major missingCourseMajor = keyList->peek(0).getMajors()->peek(0);
    BST<Course> *mss = missingCourseMajor.getCourses();
    for (int i = 0; i < missingCourseMajor.getCourses()->getNumberOfItems(); i++) {
        for (int j = 0; j < input->getNumberOfNodes(); j++) {
            Course c = input->peek(j);
            missingCourseMajor.getCourses()->remove(c);
        }
    }
    mss->breadthfirst()->display();

    delete parser;
    input->clear();
    delete input;
    return 0;
}