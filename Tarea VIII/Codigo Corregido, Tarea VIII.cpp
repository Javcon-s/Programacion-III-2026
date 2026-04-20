#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

//correcion aca por "Nodos"
void insertarInicio(Nodo* &head, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;
//correcion de que queremos igualar "=" no decir si es igual a "=="
    if (head != NULL) {
        head->anterior = nuevo;
    }

    head = nuevo;
}

void insertarFinal(Nodo*& head, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
//aca la correcion es al contrario, queremos decir si es igual, no igualar a NULL
    if (head == NULL) {
        head = nuevo;
        return;
    }

    Nodo* temp = head;

    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevo;
//Al hacer que temp se convierta en el nuevo, debemos igualarlo aca 
    nuevo->anterior = temp;
}

void mostrarAdelante(Nodo* head) {
//Otra vez debemos aclarar que si es igual y que no estamos igualando
    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* temp = head;

    cout << "\nLista hacia adelante: ";
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
//Estamos haciendo la funcion hacia delante, por lo que no es anterior, si no que siguiente
        temp = temp->siguiente;
    }

    cout << "NULL\n";
}

void mostrarAtras(Nodo* head) {
    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* temp = head;
//Se agrego la aclaracion que temp siguiente es el que debe ser distinto a NULL
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    cout << "\nLista hacia atras: ";
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->anterior;
    }

    cout << "NULL\n";
}

bool buscar(Nodo* head, int valor) {
    Nodo* temp = head;

    while (temp != NULL) {
//Otra vez correcion de igualacion
        if (temp->dato == valor) {
            return true;
        }
        temp = temp->siguiente;
    }

    return false;
}

void eliminar(Nodo*& head, int valor) {
    if (head == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }

    Nodo* actual = head;

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Dato no encontrado.\n";
        return;
    }

    if (actual == head) {
        head = head->siguiente;
//Se agrega una verificacion extra si es el primero
        if(head != NULL){
        	head->anterior = NULL;
        }
        delete actual;
        cout << "Nodo eliminado correctamente.\n";
        return;
    }

    if (actual->siguiente != NULL) {
//correcion para apuntar al nodo anterior
        actual->siguiente->anterior = actual->anterior;
    }

    if (actual->anterior != NULL) {
        actual->anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cout << "Nodo eliminado correctamente.\n";
}

int contarNodos(Nodo* head) {
//contador debe inicializarse en  0
    int contador = 0;
    Nodo* temp = head;

    while (temp != NULL) {
        contador++;
        temp = temp->siguiente;
    }

    return contador;
}

void liberarLista(Nodo* head) {
    Nodo* temp = head; //punto y coma

    while (temp != NULL) {
        Nodo* aux = temp;
//Debe ir a siguiente, no anterior
        temp = temp->siguiente;
        delete aux;
    }
}

int main() {
//Lo iniciamos en NULL, otra correcion de igualacion
    Nodo* head = NULL;
    int opcion, valor;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar hacia adelante\n";
        cout << "4. Mostrar hacia atras\n";
        cout << "5. Buscar dato\n";
        cout << "6. Eliminar dato\n";
        cout << "7. Contar nodos\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarInicio(head, valor);
                cout << "Dato insertado al inicio.\n";
                break;

            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarFinal(head, valor);
                cout << "Dato insertado al final.\n";
                break;

            case 3:
                mostrarAdelante(head);
                break;

            case 4:
                mostrarAtras(head);
                break;

            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
//Correcion de igualacion
                if (buscar(head, valor) == true) {
                    cout << "El valor SI existe en la lista.\n";
                } else {
                    cout << "El valor NO existe en la lista.\n";
                }
                break;

            case 6:
                cout << "Ingrese valor a eliminar: ";
                cin >> valor;
                eliminar(head, valor);
                break;

            case 7:
                cout << "Total de nodos: " << contarNodos(head) << endl;
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
//Correccion simple de que solo hay 8 casos, no 20
    } while (opcion != 8);

    liberarLista(head);

    return 0;
}