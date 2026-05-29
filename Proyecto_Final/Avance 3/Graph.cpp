#include "Graph.h"

Graph::Graph() {

    listaVertices = NULL;
}

Graph::~Graph() {

    Vertice* actualVertice = listaVertices;

    while (actualVertice != NULL) {

        Conexion* actualConexion =
            actualVertice->listaConexiones;

        while (actualConexion != NULL) {

            Conexion* tempConexion =
                actualConexion;

            actualConexion =
                actualConexion->siguiente;

            delete tempConexion;
        }

        Vertice* tempVertice =
            actualVertice;

        actualVertice =
            actualVertice->siguiente;

        delete tempVertice;
    }
}

Vertice* Graph::buscarVertice(int id) {

    Vertice* actual = listaVertices;

    while (actual != NULL) {

        if (actual->student_id == id) {
            return actual;
        }

        actual = actual->siguiente;
    }

    return NULL;
}

void Graph::agregarEstudiante(int id) {

    if (buscarVertice(id) != NULL) {

        return;
    }

    Vertice* nuevo = new Vertice();

    nuevo->student_id = id;

    nuevo->listaConexiones = NULL;

    nuevo->siguiente = listaVertices;

    listaVertices = nuevo;
}

void Graph::conectarEstudiantes(
    int id1,
    int id2
) {

    if (id1 == id2) {

        cout << "No se puede conectar un estudiante consigo mismo."
             << endl;

        return;
    }

    Vertice* v1 = buscarVertice(id1);

    Vertice* v2 = buscarVertice(id2);

    if (v1 == NULL || v2 == NULL) {

        cout << "Uno de los estudiantes no existe."
             << endl;

        return;
    }

    Conexion* temp = v1->listaConexiones;

    while (temp != NULL) {

        if (temp->student_id == id2) {

            cout << "Conexion duplicada."
                 << endl;

            return;
        }

        temp = temp->siguiente;
    }

    Conexion* nueva1 = new Conexion();

    nueva1->student_id = id2;

    nueva1->siguiente =
        v1->listaConexiones;

    v1->listaConexiones = nueva1;

    Conexion* nueva2 = new Conexion();

    nueva2->student_id = id1;

    nueva2->siguiente =
        v2->listaConexiones;

    v2->listaConexiones = nueva2;

    cout << "Conexion creada correctamente."
         << endl;
}

void Graph::mostrarConexiones(int id) {

    Vertice* vertice =
        buscarVertice(id);

    if (vertice == NULL) {

        cout << "Estudiante no encontrado."
             << endl;

        return;
    }

    cout << "Conexiones de "
         << id
         << ":"
         << endl;

    Conexion* actual =
        vertice->listaConexiones;

    if (actual == NULL) {

        cout << "No tiene conexiones."
             << endl;

        return;
    }

    while (actual != NULL) {

        cout << actual->student_id
             << endl;

        actual = actual->siguiente;
    }
}

bool Graph::estanConectados(
    int id1,
    int id2
) {

    Vertice* vertice =
        buscarVertice(id1);

    if (vertice == NULL) {

        return false;
    }

    Conexion* actual =
        vertice->listaConexiones;

    while (actual != NULL) {

        if (actual->student_id == id2) {

            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}

void Graph::DFSRecursivo(
    int id,
    int visitados[],
    int& cantidad
) {

    cout << id << " ";

    visitados[cantidad++] = id;

    Vertice* vertice =
        buscarVertice(id);

    if (vertice == NULL) {

        return;
    }

    Conexion* actual =
        vertice->listaConexiones;

    while (actual != NULL) {

        bool yaVisitado = false;

        for (int i = 0; i < cantidad; i++) {

            if (visitados[i]
                == actual->student_id) {

                yaVisitado = true;
            }
        }

        if (!yaVisitado) {

            DFSRecursivo(
                actual->student_id,
                visitados,
                cantidad
            );
        }

        actual = actual->siguiente;
    }
}

void Graph::DFS(int inicio) {

    if (buscarVertice(inicio) == NULL) {

        cout << "Estudiante no encontrado."
             << endl;

        return;
    }

    int visitados[1000];

    int cantidad = 0;

    cout << "DFS: ";

    DFSRecursivo(
        inicio,
        visitados,
        cantidad
    );

    cout << endl;
}

void Graph::BFS(int inicio) {

    if (buscarVertice(inicio) == NULL) {

        cout << "Estudiante no encontrado."
             << endl;

        return;
    }

    int visitados[1000];

    int cantidadVisitados = 0;

    int cola[1000];

    int frente = 0;

    int fin = 0;

    cola[fin++] = inicio;

    visitados[cantidadVisitados++] =
        inicio;

    cout << "BFS: ";

    while (frente < fin) {

        int actualID =
            cola[frente++];

        cout << actualID << " ";

        Vertice* vertice =
            buscarVertice(actualID);

        Conexion* actual =
            vertice->listaConexiones;

        while (actual != NULL) {

            bool yaVisitado = false;

            for (
                int i = 0;
                i < cantidadVisitados;
                i++
            ) {

                if (
                    visitados[i]
                    == actual->student_id
                ) {

                    yaVisitado = true;
                }
            }

            if (!yaVisitado) {

                visitados[
                    cantidadVisitados++
                ] = actual->student_id;

                cola[fin++] =
                    actual->student_id;
            }

            actual = actual->siguiente;
        }
    }

    cout << endl;
}

int Graph::contarConexiones() {

    int total = 0;

    Vertice* actualVertice =
        listaVertices;

    while (actualVertice != NULL) {

        Conexion* actualConexion =
            actualVertice->listaConexiones;

        while (actualConexion != NULL) {

            total++;

            actualConexion =
                actualConexion->siguiente;
        }

        actualVertice =
            actualVertice->siguiente;
    }

    return total / 2;
}
void Graph::eliminarEstudiante(int id) {

    Vertice* actual =
        listaVertices;

    Vertice* anterior =
        NULL;

    while (actual != NULL) {

        Conexion* conexion =
            actual->listaConexiones;

        Conexion* anteriorConexion =
            NULL;

        while (conexion != NULL) {

            if (
                conexion->student_id
                == id
            ) {

                if (
                    anteriorConexion
                    == NULL
                ) {

                    actual->listaConexiones =
                        conexion->siguiente;
                }
                else {

                    anteriorConexion->siguiente =
                        conexion->siguiente;
                }

                delete conexion;

                break;
            }

            anteriorConexion =
                conexion;

            conexion =
                conexion->siguiente;
        }

        actual =
            actual->siguiente;
    }

    actual = listaVertices;

    anterior = NULL;

    while (actual != NULL) {

        if (actual->student_id == id) {

            if (anterior == NULL) {

                listaVertices =
                    actual->siguiente;
            }
            else {

                anterior->siguiente =
                    actual->siguiente;
            }

            Conexion* conexion =
                actual->listaConexiones;

            while (conexion != NULL) {

                Conexion* temp =
                    conexion;

                conexion =
                    conexion->siguiente;

                delete temp;
            }

            delete actual;

            cout
                << "Estudiante eliminado del grafo."
                << endl;

            return;
        }

        anterior = actual;

        actual = actual->siguiente;
    }
}
