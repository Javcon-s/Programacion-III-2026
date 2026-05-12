
#include <iostream>
#include <algorithm>
#include "AVL.h"
using namespace std;

Student* crearNodo(
    int id,
    string nombre,
    string carrera,
    int semestre,
    float gpa,
    int skills
    ){

Student* nuevo = new Student();
nuevo->student_id = id;
nuevo->full_name = nombre;
nuevo->carrera = carrera;
nuevo->semester = semestre;
nuevo->gpa = gpa;
nuevo->skill_score = skills;

nuevo->izquierda = NULL;
nuevo->derecha = NULL;
nuevo->altura = 1;

return nuevo;
}

int obtenerAltura(Student *nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return nodo->altura;
}

int obtenerBalance(Student *nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

Student *rotarDerecha(Student *y) {
    Student* x = y->izquierda;
    Student* temp = x->derecha;
    x->derecha = y;
    y->izquierda = temp;

    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    return x;
}

Student *rotarIzquierda(Student *x) {
    Student* y = x->derecha;
    Student* temp = y->izquierda;

    y->izquierda = x;
    x->derecha = temp;

    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) +1;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) +1;
    return y;
}

Student* insertar(
    Student *nodo,
    int id,
    string nombre,
    string carrera,
    int semestre,
    float gpa,
    int skills
    ) {
    if (nodo == NULL) {
        return crearNodo(
            id,
            nombre,
            carrera,
            semestre,
            gpa,
            skills
            );
    }
    if (skills < nodo->skill_score) {
        nodo->izquierda = insertar(
            nodo->izquierda,
            id,
            nombre,
            carrera,
            semestre,
            gpa,
            skills
            );
    } else if (skills > nodo->skill_score) {
        nodo->derecha = insertar(
            nodo->derecha,
            id, nombre,
            carrera,
            semestre,
            gpa,
            skills
            );
    } else {
        return nodo;
      //  if (id < nodo->student_id) {
        //    nodo->izquierda = insertar(
          //      nodo->izquierda,
            //    id,
              //  nombre,
                //carrera,
                //semestre,
                //gpa,
                //skills
                //);
      //  } else {
        //    nodo->derecha = insertar(
          //      nodo->derecha,
            //    id,
              //  nombre,
               // carrera,
               // semestre,
                //gpa,
                //skills
                //);
        //}
    }
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda),obtenerAltura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && skills < nodo->izquierda->skill_score) {
        return rotarDerecha(nodo);

    }
    if (balance < -1 && skills > nodo->derecha->skill_score) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && skills > nodo->izquierda->skill_score ) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && skills < nodo->derecha->skill_score ) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }
    return nodo;
}

void inOrder(Student* raiz) {

    if (raiz != NULL) {

        inOrder(raiz->izquierda);

        cout << raiz->full_name
             << "-- Score: "
             << raiz->skill_score
             << endl;

        inOrder(raiz->derecha);
    }
}

void preOrder(Student* raiz) {

    if (raiz != NULL) {

        cout << raiz->full_name
             << "-- Score: "
             << raiz->skill_score
             << endl;

        preOrder(raiz->izquierda);
        preOrder(raiz->derecha);
    }
}

void postOrder(Student* raiz) {

    if (raiz != NULL) {

        postOrder(raiz->izquierda);
        postOrder(raiz->derecha);

        cout << raiz->full_name
             << "-- Score: "
             << raiz->skill_score
             << endl;
    }
}
Student* buscarPorSkill(Student* raiz, int skill) {

    if (raiz == NULL) {
        return NULL;
    }

    if (skill == raiz->skill_score) {
        return raiz;
    }

    if (skill < raiz->skill_score) {
        return buscarPorSkill(raiz->izquierda, skill);
    }

    return buscarPorSkill(raiz->derecha, skill);
}
int contarNodos(Student* raiz);

int contarNodos(Student* raiz) {

    if (raiz == NULL) {
        return 0;
    }

    return 1
           + contarNodos(raiz->izquierda)
           + contarNodos(raiz->derecha);
}

//
// Created by javie on 11/05/2026.
//