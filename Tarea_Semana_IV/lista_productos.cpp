#include <iostream>
#include <string>

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto data;
    Nodo* siguiente;
};

int main() {

    cout << "Nombre: Esteban Javier Antonio Alarcón Herrera\n\n";

    Nodo* head= NULL;
    Nodo* anterior= NULL;

    for (int i = 1; i <= 4; i++) {

        Nodo* nuevo= new Nodo;
        nuevo->siguiente = NULL;

        cout<< "Ingrese datos del producto " << i << endl;

        cout<< "Codigo: ";
        cin>> nuevo->data.codigo;

        cout<< "Nombre: ";
        cin>> nuevo->data.nombre;  

        cout<< "Precio: ";
        cin>> nuevo->data.precio;

        cout<< endl;

        if (head == NULL) {
            head= nuevo;
        } else {
            anterior->siguiente = nuevo;
        }

        anterior= nuevo;
    }

    Nodo* actual= head;
    double total= 0;

    while (actual != NULL) {
        cout<< "Codigo: " << actual->data.codigo<< endl;
        cout<< "Nombre: " << actual->data.nombre<< endl;
        cout<< "Precio: " << actual->data.precio<< endl;
        cout<< "-----------------------------------------" <<endl;

        total += actual->data.precio;
        actual = actual->siguiente;
    }

    cout<< "Total acumulado: " << total << endl;

    actual= head;

    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    head= NULL;

    return 0;
}