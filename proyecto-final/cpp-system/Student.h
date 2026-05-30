//
// Created by javie on 11/05/2026.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct NodoProyecto;

struct Student {

    int student_id;
    string full_name;
    string carrera;
    int semester;
    float gpa;
    int skill_score;

    NodoProyecto* listaProyectos;

    Student* izquierda;
    Student* derecha;

    int altura;
};

#endif