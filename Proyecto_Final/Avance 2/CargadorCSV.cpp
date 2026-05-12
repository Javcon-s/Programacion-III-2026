//
// Created by javie on 11/05/2026.
//
#include <iostream>
#include <fstream>
#include <sstream>

#include "CargadorCSV.h"

using namespace std;

void cargarCSV(Student*& raiz, TablaHash& tabla) {

    ifstream archivo("estudiantes.csv");

    if (!archivo.is_open()) {
        cout << "Error al abrir el CSV." << endl;
        return;
    }

    string linea;

    getline(archivo, linea);

    while (getline(archivo, linea)) {

        stringstream ss(linea);

        string idStr;
        string nombre;
        string carrera;
        string semestreStr;
        string gpaStr;
        string scoreStr;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, carrera, ',');
        getline(ss, semestreStr, ',');
        getline(ss, gpaStr, ',');
        getline(ss, scoreStr, ',');

        int id = stoi(idStr);
        int semestre = stoi(semestreStr);
        float gpa = stof(gpaStr);
        int skill = stoi(scoreStr);

        raiz = insertar(
            raiz,
            id,
            nombre,
            carrera,
            semestre,
            gpa,
            skill
        );

        Student* estudianteInsertado =
            buscarPorSkill(raiz, skill);

        tabla.insertar(estudianteInsertado);
    }

    archivo.close();

    cout << "CSV cargado correctamente." << endl;
}