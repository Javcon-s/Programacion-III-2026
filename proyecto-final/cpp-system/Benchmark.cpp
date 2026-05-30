

#include "Benchmark.h"

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void generarBenchmark(
    Student* raiz,
    TablaHash& tabla,
    Graph& grafo
) {

    ofstream archivo("cpp_results.csv");

    archivo
        << "language,operation,structure,records,time_ms"
        << endl;

    int totalRegistros =
        contarNodos(raiz);


    auto inicioHash =
        high_resolution_clock::now();

    tabla.buscar(1001);

    auto finHash =
        high_resolution_clock::now();

    double tiempoHash =
        duration<double, milli>(
            finHash - inicioHash
        ).count();

    archivo
        << "C++,search,HashTable,"
        << totalRegistros
        << ","
        << tiempoHash
        << endl;

    auto inicioAVL =
        high_resolution_clock::now();

    buscarPorSkill(raiz, 120);

    auto finAVL =
        high_resolution_clock::now();

    double tiempoAVL =
        duration<double, milli>(
            finAVL - inicioAVL
        ).count();

    archivo
        << "C++,search,AVL,"
        << totalRegistros
        << ","
        << tiempoAVL
        << endl;

    auto inicioTraversal =
        high_resolution_clock::now();

    inOrder(raiz);

    auto finTraversal =
        high_resolution_clock::now();

    double tiempoTraversal =
        duration<double, milli>(
            finTraversal - inicioTraversal
        ).count();

    archivo
        << "C++,traversal,AVL,"
        << totalRegistros
        << ","
        << tiempoTraversal
        << endl;



    auto inicioBFS =
        high_resolution_clock::now();

    grafo.BFS(1001);

    auto finBFS =
        high_resolution_clock::now();

    double tiempoBFS =
        duration<double, milli>(
            finBFS - inicioBFS
        ).count();

    archivo
        << "C++,bfs,Graph,"
        << totalRegistros
        << ","
        << tiempoBFS
        << endl;


    auto inicioDFS =
        high_resolution_clock::now();

    grafo.DFS(1001);

    auto finDFS =
        high_resolution_clock::now();

    double tiempoDFS =
        duration<double, milli>(
            finDFS - inicioDFS
        ).count();

    archivo
        << "C++,dfs,Graph,"
        << totalRegistros
        << ","
        << tiempoDFS
        << endl;

    archivo.close();

    cout << endl;
    cout << "Benchmark generado correctamente."
         << endl;

    cout << "Archivo creado: cpp_results.csv"
         << endl;
}