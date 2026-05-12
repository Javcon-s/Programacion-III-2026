//
// Created by javie on 11/05/2026.
//

#ifndef PROYECTO_FINAL_TABLAHASH_H
#define PROYECTO_FINAL_TABLAHASH_H

#include "NodoHash.h"

class TablaHash {

    private:
    static const int SIZE = 250;
    HashNode* tabla[SIZE];

    int totalElementos, totalColisiones;
    int funcionHash(int id);

public:
    int obtenerColisiones();
    TablaHash();
    bool insertar(Student* estudiante);
    Student* buscar(int id);
    bool eliminar(int id);
    void mostrarTabla();
    void mostrarEstadisticas();
    float factorCarga();

};

#endif //PROYECTO_FINAL_TABLAHASH_H