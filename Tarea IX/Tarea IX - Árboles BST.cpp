#include <iostream>
using namespace std;

struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};

NodoArbol* crearNodo(int valor) {
    NodoArbol* nuevo = new NodoArbol();
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

NodoArbol* insertar(NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else {
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    return raiz;
}

void inOrden(NodoArbol* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inOrden(raiz->derecho);
    }
}

void preOrden(NodoArbol* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierdo);
        preOrden(raiz->derecho);
    }
}

void postOrden(NodoArbol* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izquierdo);
        postOrden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

int main() {

    NodoArbol* raiz = NULL;
    int opcion, valor;

    do {
        cout << endl;
        cout << "\nEsteban Javier Antonio Alarcon Herrera\n";
        cout << "\n_______MENU_______\n" << endl;
        cout << "1. Insertar valor" << endl;
        cout << "2. Mostrar InOrden" << endl;
        cout << "3. Mostrar PreOrden" << endl;
        cout << "4. Mostrar PostOrden" << endl;
        cout << "5. Mostrar todos los recorridos" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            cout << "Ingrese valor: ";
            cin >> valor;
            raiz = insertar(raiz, valor);
            break;

        case 2:
            if (!raiz) {
                cout << "Arbol vacio" << endl;
            } else {
                cout << "InOrden: ";
                inOrden(raiz);
                cout << endl;
            }
            break;

        case 3:
            if (!raiz) {
                cout << "Arbol vacio" << endl;
            } else {
                cout << "PreOrden: ";
                preOrden(raiz);
                cout << endl;
            }
            break;

        case 4:
            if (!raiz) {
                cout << "Arbol vacio" << endl;
            } else {
                cout << "PostOrden: ";
                postOrden(raiz);
                cout << endl;
            }
            break;

        case 5:
            if (!raiz) {
                cout << "Arbol vacio" << endl;
            } else {
                cout << "InOrden: ";
                inOrden(raiz);
                cout << endl;

                cout << "PreOrden: ";
                preOrden(raiz);
                cout << endl;

                cout << "PostOrden: ";
                postOrden(raiz);
                cout << endl;
            }
            break;

        case 6:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (opcion != 6);

    return 0;
}