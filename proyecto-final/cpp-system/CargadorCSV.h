//
// Created by javie on 11/05/2026.
//

#ifndef PROYECTO_FINAL_CSVCARGADOR_H
#define PROYECTO_FINAL_CSVCARGADOR_H

#include "AVL.h"
#include "TablaHash.h"
#include "Graph.h"

void cargarCSV(
    Student*& raiz,
    TablaHash& tabla,
    Graph& grafo
);
extern double tiempoCargaCSV;
#endif