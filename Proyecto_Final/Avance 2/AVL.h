//
// Created by javie on 10/05/2026.
//

#ifndef SRC_AVL_H
#define SRC_AVL_H
#include <string>

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
    Student* node,
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
Student* buscarPorSkill(Student* raiz, int skill);
int contarNodos(Student* raiz);

#endif //SRC_AVL_H