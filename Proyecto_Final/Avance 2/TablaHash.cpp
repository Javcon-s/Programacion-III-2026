//
// Created by javie on 11/05/2026.
//
#include <iostream>
#include "TablaHash.h"
#include "Student.h"
#include "NodoHash.h"
int TablaHash::obtenerColisiones() {
    return totalColisiones;
}

float TablaHash::factorCarga() {
    return (float) totalElementos / SIZE;
}

int TablaHash::funcionHash(int id) {
    return id % SIZE;
}

TablaHash::TablaHash() {

    for (int i = 0; i < SIZE; i++) {
        tabla[i] = NULL;

    }
    totalElementos = 0;
    totalColisiones = 0;
}

bool TablaHash::insertar(Student* estudiante) {

    int indice = funcionHash(estudiante->student_id);

    if (buscar(estudiante->student_id) != NULL) {
        return false;
    }

    HashNode* nuevo = new HashNode();

    nuevo->estudiante = estudiante;
    nuevo->siguiente = NULL;

    if (tabla[indice] != NULL) {
        totalColisiones++;
    }

    nuevo->siguiente = tabla[indice];

    tabla[indice] = nuevo;

    totalElementos++;
    return true;
}

Student* TablaHash::buscar(int id) {
    int indice = funcionHash(id);

    HashNode* actual = tabla[indice];

    while (actual != NULL) {

        if (actual->estudiante->student_id == id) {
            return actual->estudiante;
        }
        actual = actual->siguiente;
    }
    return NULL;
}
