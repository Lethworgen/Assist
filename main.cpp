
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

    int menuNumber = 1;
    for (int i = 0; i < keyList->getNumberOfNodes(); i++) {
        string univName = keyList->peek(i).getName();
        BST<Major> foundMajors;
        map->get(keyList->peek(i), foundMajors);
        Queue<Major> *majors = foundMajors.inorder();

        for (int j = 0; j < majors->getNumberOfNodes(); j++) {
            Major m = majors->peekFront();
            majors->dequeue();
            cout << (menuNumber) << ". " << m.getName() << " (" << univName << ")" << endl;
            menuNumber++;
        }
    }
    cout << endl;
}

Major getMajor(int menu,
               SinglyLinkedList<University> *universities,
               SinglyLinkedList<University> *keyList,
               HashMap<University, BST<Major>> *map) {
    for (int i = 0; i < keyList->getNumberOfNodes(); i++) {
        string univName = keyList->peek(i).getName();
        BST<Major> foundMajors;
        map->get(keyList->peek(i), foundMajors);
        Queue<Major> *majors = foundMajors.inorder();

        for (int j = 0; j < majors->getNumberOfNodes(); j++) {
            Major m = majors->peekFront();
            majors->dequeue();
            menu--;
            if (menu == 0) {
                return m;
            }
        }
    }
    Major tmp;
    return tmp;
}

//void createDummyInput(SinglyLinkedList<Course> *input) {
//    Course *tmpCourse1 = new Course("HIST 17C");
//    Course *tmpCourse2 = new Course("HIST 17A");
//    Course *tmpCourse3 = new Course("HIST 17B");
//    Course *tmpCourse4 = new Course("PHYS 4D");
//    input->addLast(*tmpCourse1);
//    input->addLast(*tmpCourse2);
//    input->addLast(*tmpCourse3);
//    input->addLast(*tmpCourse4);
//}

void createDummyInput(SinglyLinkedList<Course> *input) {
    ifstream fs("taken_courses.txt");
    if (fs.is_open()) {
        string s;
        while (!fs.eof()) {
            getline(fs, s);
            Course course(s);
            input->addLast(course);
        }
    } else {
        cout << "file is not open." << endl;
    }
    if (fs.is_open()) {
        fs.close();
    }
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

    // missing courses
//    Major missingCourseMajor = keyList->peek(0).getMajors()->peek(0);
//    showMissingCourses(input, missingCourseMajor.getCourses());
//    writeMissingCourses(missingCourseMajor.getName(), missingCourseMajor.getCourses());

    cout << "Enter \"stop\" to end the program." << endl;
    string line = "";
    while (true) {
        showBestMathcedMajors(parser, input, universities, keyList, map);
        cout << "Choose the major to see missing courses: ";
        cin >> line;
        if (line == "stop") {
            break;
        }
        int m = stoi(line);
        Major major = getMajor(m, universities, keyList, map);
        showMissingCourses(input, major.getCourses());
        writeMissingCourses(major.getName(), major.getCourses());
    }

    input->clear();
    keyList->clear();
    universities->clear();
    delete map;
    delete parser;
    delete input;
    return 0;
}