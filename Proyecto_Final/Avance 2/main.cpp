#include "Menu.h"
#include "CargadorCSV.h"

int main() {

    Student* raiz = NULL;

    TablaHash tabla;

    cargarCSV(raiz, tabla);

    mostrarMenu(raiz, tabla);

    return 0;
}