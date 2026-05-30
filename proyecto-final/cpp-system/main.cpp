#include "Menu.h"
#include "Graph.h"
#include "Cola.h"

int main() {

    Student* raiz = NULL;

    TablaHash tabla;

    Graph grafo;

    Cola cola;

    mostrarMenu(
        raiz,
        tabla,
        grafo,
        cola
    );

    return 0;
}