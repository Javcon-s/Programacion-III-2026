#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include "Student.h"

using namespace std;

struct Proyecto {

    int project_id;
    string titulo;
    string descripcion;
    int anio;
};

struct NodoProyecto {

    Proyecto proyecto;
    NodoProyecto* siguiente;
};

int contarProyectos(Student* raiz);

#endif