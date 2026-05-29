#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

struct Conexion {

    int student_id;

    Conexion* siguiente;
};

struct Vertice {

    int student_id;

    Conexion* listaConexiones;

    Vertice* siguiente;
};

class Graph {

private:

    Vertice* listaVertices;

    Vertice* buscarVertice(int id);

    void DFSRecursivo(
        int id,
        int visitados[],
        int& cantidad
    );

public:

    Graph();

    ~Graph();

    void agregarEstudiante(int id);

    void eliminarEstudiante(int id);

    void conectarEstudiantes(
        int id1,
        int id2
    );

    void mostrarConexiones(int id);

    bool estanConectados(
        int id1,
        int id2
    );

    void BFS(int inicio);

    void DFS(int inicio);

    int contarConexiones();
};
void eliminarEstudiante(int id);
#endif