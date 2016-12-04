cmake_minimum_required(VERSION 3.6)
project(Assist)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FILES

        main.cpp
        Parser.h

        rapidjson/document.h
        rapidjson/writer.h
        rapidjson/stringbuffer.h

        data_structure/SinglyLinkedList.h
        data_structure/Queue.h
        data_structure/BST.h

        model/University.h
        model/University.cpp
        model/Major.h
        model/Major.cpp
        model/Course.h
        model/Course.cpp
        model/HashObject.h)

add_executable(Assist ${SOURCE_FILES})