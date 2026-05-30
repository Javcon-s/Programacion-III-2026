#include "Cola.h"

Cola::Cola() {

    frente = NULL;
    final = NULL;
}

bool Cola::vacia() {

    return frente == NULL;
}

void Cola::encolar(int sender, int receiver) {

    NodoCola* nuevo = new NodoCola();

    nuevo->senderID = sender;
    nuevo->receiverID = receiver;

    nuevo->siguiente = NULL;

    if (vacia()) {

        frente = nuevo;
        final = nuevo;
    }
    else {

        final->siguiente = nuevo;

        final = nuevo;
    }

    cout << "Solicitud agregada a la cola." << endl;
}

void Cola::desencolar() {

    if (vacia()) {

        cout << "La cola esta vacia." << endl;
        return;
    }

    NodoCola* temp = frente;

    cout << "Procesando solicitud: "
         << frente->senderID
         << " -> "
         << frente->receiverID
         << endl;

    frente = frente->siguiente;

    delete temp;

    if (frente == NULL) {

        final = NULL;
    }
}

void Cola::mostrar() {

    if (vacia()) {

        cout << "No hay solicitudes pendientes." << endl;
        return;
    }

    NodoCola* actual = frente;

    cout << "----- COLA DE SOLICITUDES -----" << endl;

    while (actual != NULL) {

        cout << actual->senderID
             << " -> "
             << actual->receiverID
             << endl;

        actual = actual->siguiente;
    }
}
Cola::~Cola() {

    while (!vacia()) {

        desencolar();
    }
}