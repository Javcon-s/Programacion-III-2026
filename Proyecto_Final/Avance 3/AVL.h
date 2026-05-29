//
// Created by javie on 10/05/2026.
//

#ifndef AVL_H
#define AVL_H

#include "Student.h"

using namespace std;

Student* crearNodo(
    int id,
    string nombre,
    string carrera,
    int semestre,
    float gpa,
    int skills
);

int obtenerAltura(Student* nodo);

int obtenerBalance(Student* nodo);

Student* rotarDerecha(Student* y);

Student* rotarIzquierda(Student* x);

Student* insertar(
    Student* nodo,
    int id,
    string nombre,
    string carrera,
    int semestre,
    float gpa,
    int skills
);

void inOrder(Student* raiz);

void preOrder(Student* raiz);

void postOrder(Student* raiz);

Student* buscarPorSkill(
    Student* raiz,
    int skill
);

Student* buscarPorIDAVL(
    Student* raiz,
    int id
);

Student* nodoMinimo(
    Student* nodo
);

Student* eliminarStudent(
    Student* raiz,
    int skill,
    int id
);

int contarNodos(Student* raiz);

#endif //SRC_AVL_H