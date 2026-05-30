#include "Projects.h"

void agregarProyecto(
    Student* estudiante,
    int id,
    string titulo,
    string descripcion,
    int year
) {

    NodoProyecto* actual =
        estudiante->listaProyectos;

    while (actual != NULL) {

        if (actual->proyecto.project_id == id) {

            cout
                << "Ya existe un proyecto con ese ID."
                << endl;

            return;
        }

        actual = actual->siguiente;
    }

    NodoProyecto* nuevo =
        new NodoProyecto();

    nuevo->proyecto.project_id = id;

    nuevo->proyecto.titulo = titulo;

    nuevo->proyecto.descripcion =
        descripcion;

    nuevo->proyecto.anio = year;

    nuevo->siguiente =
        estudiante->listaProyectos;

    estudiante->listaProyectos =
        nuevo;

    cout
        << "Proyecto agregado correctamente."
        << endl;
}

void mostrarProyectos(Student* estudiante) {

    if (estudiante->listaProyectos == NULL) {

        cout
            << "El estudiante no tiene proyectos."
            << endl;

        return;
    }

    NodoProyecto* actual =
        estudiante->listaProyectos;

    cout
        << "----- PROYECTOS -----"
        << endl;

    while (actual != NULL) {

        cout
            << "ID: "
            << actual->proyecto.project_id
            << endl;

        cout
            << "Titulo: "
            << actual->proyecto.titulo
            << endl;

        cout
            << "Descripcion: "
            << actual->proyecto.descripcion
            << endl;

        cout
            << "Anio: "
            << actual->proyecto.anio
            << endl;

        cout
            << "---------------------"
            << endl;

        actual = actual->siguiente;
    }
}

NodoProyecto* buscarProyecto(
    Student* estudiante,
    int project_id
) {

    NodoProyecto* actual =
        estudiante->listaProyectos;

    while (actual != NULL) {

        if (
            actual->proyecto.project_id
            == project_id
        ) {

            return actual;
        }

        actual = actual->siguiente;
    }

    return NULL;
}

bool eliminarProyecto(
    Student* estudiante,
    int project_id
) {

    NodoProyecto* actual =
        estudiante->listaProyectos;

    NodoProyecto* anterior = NULL;

    while (actual != NULL) {

        if (
            actual->proyecto.project_id
            == project_id
        ) {

            if (anterior == NULL) {

                estudiante->listaProyectos =
                    actual->siguiente;
            }
            else {

                anterior->siguiente =
                    actual->siguiente;
            }

            delete actual;

            cout
                << "Proyecto eliminado."
                << endl;

            return true;
        }

        anterior = actual;

        actual = actual->siguiente;
    }

    cout
        << "Proyecto no encontrado."
        << endl;

    return false;
}

int contarProyectos(Student* raiz) {

    if (raiz == NULL) {

        return 0;
    }

    int total = 0;

    NodoProyecto* actual =
        raiz->listaProyectos;

    while (actual != NULL) {

        total++;

        actual = actual->siguiente;
    }

    return total
           + contarProyectos(raiz->izquierda)
           + contarProyectos(raiz->derecha);
}