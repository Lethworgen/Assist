#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace rapidjson;

const char *parseJsonFile(string path) {
    ifstream ifs(path);
    string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    ifs.close();
    return content.c_str();
}

int main() {
    Document d;
    d.Parse(parseJsonFile("uc.json"));
    for (int i = 0; i < d.GetArray().Capacity(); i++) {
        Value &obj = d.GetArray()[i]["name"];
        cout << "name[" << (i + 1) << "]: " << obj.GetString() << endl;
    }

    return 0;
}