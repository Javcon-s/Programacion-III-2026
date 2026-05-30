#ifndef PROJECTS_H
#define PROJECTS_H

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

void agregarProyecto(
    Student* estudiante,
    int id,
    string titulo,
    string descripcion,
    int anio
);

void mostrarProyectos(Student* estudiante);

NodoProyecto* buscarProyecto(
    Student* estudiante,
    int project_id
);

bool eliminarProyecto(
    Student* estudiante,
    int project_id
);

int contarProyectos(Student* raiz);

#endif