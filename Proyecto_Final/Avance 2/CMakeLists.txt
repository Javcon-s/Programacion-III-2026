cmake_minimum_required(VERSION 4.1)
project(Proyecto_Final)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Final main.cpp
        Student.h
        AVL.cpp
        AVL.h
        NodoHash.h
        TablaHash.h
        TablaHash.cpp
        CargadorCSV.h
        CargadorCSV.cpp
        Menu.h
        Menu.cpp)
