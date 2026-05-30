//
// Created by javie on 11/05/2026.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "CargadorCSV.h"
#include <chrono>
using namespace std;
using namespace chrono;

double tiempoCargaCSV = 0;
void cargarCSV(
    Student*& raiz,
    TablaHash& tabla,
    Graph& grafo
) {

    ifstream archivo("estudiantes.csv");

    if (!archivo.is_open()) {

        cout << "Error al abrir el CSV." << endl;
        return;
    }

    string linea;

    getline(archivo, linea);
    auto inicioCarga =
    high_resolution_clock::now();

    while (getline(archivo, linea)) {

        auto finCarga =
    high_resolution_clock::now();

        tiempoCargaCSV =
            duration<double, milli>(
                finCarga - inicioCarga
            ).count();

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

        Student* estudianteHash = new Student();

        estudianteHash->student_id = id;
        estudianteHash->full_name = nombre;
        estudianteHash->carrera = carrera;
        estudianteHash->semester = semestre;
        estudianteHash->gpa = gpa;
        estudianteHash->skill_score = skill;

        estudianteHash->listaProyectos = NULL;

        estudianteHash->izquierda = NULL;
        estudianteHash->derecha = NULL;

        estudianteHash->altura = 1;

        tabla.insertar(estudianteHash);

        grafo.agregarEstudiante(id);
    }

    archivo.close();

    cout << "CSV cargado correctamente." << endl;
}