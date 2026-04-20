#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

//correcion aca por "Nodos"
void insertarInicio(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

//correcion de que queremos igualar "=" no decir si es igual a "=="
    if (head != NULL) {
        head->anterior = nuevo;
    } else {
//Si la lista esta vacia, tail tambien sera el nuevo nodo
        tail = nuevo;
    }

    head = nuevo;
}

void insertarFinal(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = tail;

//aca la correcion es al contrario, queremos decir si es igual, no igualar a NULL
    if (head == NULL) {
        head = nuevo;
        tail = nuevo;
        return;
    }

//Ya no recorremos toda la lista, usamos tail directamente
    tail->siguiente = nuevo;

//Al hacer que temp se convierta en el nuevo, debemos igualarlo aca
    tail = nuevo;
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

void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "Lista vacia\n";
        return;
    }

//Ahora iniciamos desde tail directamente
    Nodo* temp = tail;

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

void eliminar(Nodo*& head, Nodo*& tail, int valor) {
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

//Si solo existe un nodo
    if (head == tail && actual == head) {
        head = NULL;
        tail = NULL;
        delete actual;
        cout << "Nodo eliminado correctamente.\n";
        return;
    }

    if (actual == head) {
        head = head->siguiente;

//Se agrega una verificacion extra si es el primero
        if (head != NULL) {
            head->anterior = NULL;
        }

        delete actual;
        cout << "Nodo eliminado correctamente.\n";
        return;
    }

//Si se elimina el ultimo nodo
    if (actual == tail) {
        tail = tail->anterior;
        tail->siguiente = NULL;
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

//contador debe inicializarse en 0
    int contador = 0;
    Nodo* temp = head;

    while (temp != NULL) {
        contador++;
        temp = temp->siguiente;
    }

    return contador;
}

void liberarLista(Nodo*& head, Nodo*& tail) {

//punto y coma
    Nodo* temp = head;

    while (temp != NULL) {
        Nodo* aux = temp;

//Debe ir a siguiente, no anterior
        temp = temp->siguiente;
        delete aux;
    }

//Ambos punteros quedan vacios
    head = NULL;
    tail = NULL;
}

int main() {

//Lo iniciamos en NULL, otra correcion de igualacion
    Nodo* head = NULL;
    Nodo* tail = NULL;

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
                insertarInicio(head, tail, valor);
                cout << "Dato insertado al inicio.\n";
                break;

            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarFinal(head, tail, valor);
                cout << "Dato insertado al final.\n";
                break;

            case 3:
                mostrarAdelante(head);
                break;

            case 4:
                mostrarAtras(tail);
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
                eliminar(head, tail, valor);
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

    liberarLista(head, tail);

    return 0;
}