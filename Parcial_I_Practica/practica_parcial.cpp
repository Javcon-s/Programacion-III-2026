#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    
    Nodo* nodo1 = NULL;
    Nodo* nodo2 = NULL;
    Nodo* nodo3 = NULL;

    
    nodo1= new Nodo;
    nodo2= new Nodo;
    nodo3= new Nodo;

    cout << "Ingrese el valor 1: ";
    cin >> nodo1->dato;

    cout << "Ingrese el valor 2: ";
    cin >> nodo2->dato;

    cout << "Ingrese el valor 3: ";
    cin >> nodo3->dato;

    nodo1->siguiente= nodo2;
    nodo2->siguiente= nodo3;
    nodo3->siguiente= NULL;

    cout<<endl<<"Esteban Javier Antonio Aalarcon Herrera"<<endl;
    cout<<"----------------------------------------------------"<<endl;

    cout << "Valores almacenados:" << endl;
    cout << "Nodo 1: " << nodo1->dato << endl;
    cout << "Nodo 2: " << nodo2->dato << endl;
    cout << "Nodo 3: " << nodo3->dato << endl;

    delete nodo1;
    delete nodo2;
    delete nodo3;

    return 0;
}