#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct NodoDoble {
    int dato;
    string tipo;
    int orden;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};


void push(Nodo*& pila, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = pila;
    pila = nuevo;
}

void mostrarPila(Nodo* pila) {
    if (!pila) {
        cout << "Pila vacia" << endl;
        return;
    }
    while (pila) {
        cout << pila->dato << " -> ";
        pila = pila->siguiente;
    }
    cout << "NULL" << endl;
}

void enqueue(Nodo*& frente, Nodo*& fin, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (!frente) {
        frente = fin = nuevo;
        return;
    }

    fin->siguiente = nuevo;
    fin = nuevo;
}

void mostrarCola(Nodo* frente) {
    if (!frente) {
        cout << "Cola vacia" << endl;
        return;
    }
    while (frente) {
        cout << frente->dato << " -> ";
        frente = frente->siguiente;
    }
    cout << "NULL" << endl;
}

void insertarLista(Nodo*& head, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = head;
    head = nuevo;
}

void mostrarLista(Nodo* head) {
    if (!head) {
        cout << "Lista vacia" << endl;
        return;
    }
    while (head) {
        cout << head->dato << " -> ";
        head = head->siguiente;
    }
    cout << "NULL" << endl;
}

int eliminarMenores10(Nodo*& head) {
    int eliminados = 0;

    while (head && (head->dato > -10 && head->dato < 10)) {
        Nodo* aux = head;
        head = head->siguiente;
        delete aux;
        eliminados++;
    }

    Nodo* temp = head;

    while (temp && temp->siguiente) {
        if (temp->siguiente->dato > -10 && temp->siguiente->dato < 10) {
            Nodo* aux = temp->siguiente;
            temp->siguiente = aux->siguiente;
            delete aux;
            eliminados++;
        } else {
            temp = temp->siguiente;
        }
    }

    return eliminados;
}

void insertarHistorial(NodoDoble*& head, NodoDoble*& tail, int valor, string tipo, int orden) {
    NodoDoble* nuevo = new NodoDoble();
    nuevo->dato = valor;
    nuevo->tipo = tipo;
    nuevo->orden = orden;
    nuevo->siguiente = NULL;
    nuevo->anterior = tail;

    if (!head) {
        head = tail = nuevo;
        return;
    }

    tail->siguiente = nuevo;
    tail = nuevo;
}

void mostrarHistorial(NodoDoble* head) {
    while (head) {
        cout << head->orden << ") " << head->dato << " -> " << head->tipo << endl;
        head = head->siguiente;
    }
}


NodoArbol* crearNodo(int valor) {
    NodoArbol* nuevo = new NodoArbol();
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

NodoArbol* insertar(NodoArbol* raiz, int valor) {
    if (!raiz) return crearNodo(valor);

    if (valor < raiz->dato)
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else
        raiz->derecho = insertar(raiz->derecho, valor);

    return raiz;
}

void inOrden(NodoArbol* r) {
    if (r) {
        inOrden(r->izquierdo);
        cout << r->dato << " ";
        inOrden(r->derecho);
    }
}

void preOrden(NodoArbol* r) {
    if (r) {
        cout << r->dato << " ";
        preOrden(r->izquierdo);
        preOrden(r->derecho);
    }
}

void postOrden(NodoArbol* r) {
    if (r) {
        postOrden(r->izquierdo);
        postOrden(r->derecho);
        cout << r->dato << " ";
    }
}

bool buscarBST(NodoArbol* r, int val) {
    if (!r) return false;
    if (r->dato == val) return true;

    if (val < r->dato)
        return buscarBST(r->izquierdo, val);
    else
        return buscarBST(r->derecho, val);
}


void liberarLista(Nodo*& head) {
    while (head) {
        Nodo* aux = head;
        head = head->siguiente;
        delete aux;
    }
}

void liberarHistorial(NodoDoble*& head) {
    while (head) {
        NodoDoble* aux = head;
        head = head->siguiente;
        delete aux;
    }
}

void liberarBST(NodoArbol*& r) {
    if (r) {
        liberarBST(r->izquierdo);
        liberarBST(r->derecho);
        delete r;
    }
}




int main() {

    Nodo* pila = NULL;
    Nodo* colaF = NULL;
    Nodo* colaFin = NULL;
    Nodo* negativos = NULL;

    NodoDoble* histHead = NULL;
    NodoDoble* histTail = NULL;

    NodoArbol* bst = NULL;

    Nodo* aux1 = NULL;
    Nodo* aux2 = NULL;

    int orden = 1;
    int pares = 0, impares = 0, neg = 0, ceros = 0, total = 0;
    int mayor = -99999, menor = 99999;

    int op, n, val;

    do {
        cout << endl;
        cout << "\nEsteban Javier Antonio Alarcon Herrera\n";
        cout << "1.Ingresar" << endl;
        cout << "2.Pila" << endl;
        cout << "3.Cola" << endl;
        cout << "4.Negativos" << endl;
        cout << "5.Historial" << endl;
        cout << "6.BST" << endl;
        cout << "7.Eliminar negativos" << endl;
        cout << "8.Buscar BST" << endl;
        cout << "9.Stats" << endl;
        cout << "10.Reorganizar" << endl;
        cout << "0.Salir" << endl;

        cin >> op;

        switch (op) {

        case 1:
            cout << "Cantidad: ";
            cin >> n;

            if (n <= 0) {
                cout << "Cantidad invalida" << endl;
                break;
            }

            for (int i = 0; i < n; i++) {
                cin >> val;

                if (val == 0) {
                    ceros++;
                    continue;
                }

                total++;

                if (val > mayor) mayor = val;
                if (val < menor) menor = val;

                if (val > 0) {
                    if (val % 2 == 0) {
                        enqueue(colaF, colaFin, val);
                        pares++;
                        insertarHistorial(histHead, histTail, val, "COLA", orden++);
                    } else {
                        push(pila, val);
                        impares++;
                        insertarHistorial(histHead, histTail, val, "PILA", orden++);
                    }
                } else {
                    insertarLista(negativos, val);
                    neg++;
                    insertarHistorial(histHead, histTail, val, "LISTA", orden++);
                }
            }
            break;

        case 2: mostrarPila(pila); break;
        case 3: mostrarCola(colaF); break;
        case 4: mostrarLista(negativos); break;
        case 5: mostrarHistorial(histHead); break;

        case 6:
            liberarBST(bst);
            bst = NULL;

            for (NodoDoble* t = histHead; t; t = t->siguiente) {
                if (t->dato > 0)
                    bst = insertar(bst, t->dato);
            }

            cout << "InOrden: "; inOrden(bst); cout << endl;
            cout << "PreOrden: "; preOrden(bst); cout << endl;
            cout << "PostOrden: "; postOrden(bst); cout << endl;
            break;

        case 7:
            cout << "Lista original: ";
            mostrarLista(negativos);

            cout << "Eliminados: " << eliminarMenores10(negativos) << endl;

            cout << "Lista resultante: ";
            mostrarLista(negativos);
            break;

        case 8:
            cin >> val;
            if (!bst) {
                cout << "BST no construido" << endl;
            } else {
                cout << (buscarBST(bst, val) ? "Existe" : "No existe") << endl;
            }
            break;

        case 9:
            cout << "Pares: " << pares << endl;
            cout << "Impares: " << impares << endl;
            cout << "Negativos: " << neg << endl;
            cout << "Ceros: " << ceros << endl;
            cout << "Total validos: " << total << endl;
            cout << "Mayor: " << mayor << endl;
            cout << "Menor: " << menor << endl;
            break;

        case 10:
            while (pila) {
                insertarLista(aux1, pila->dato);
                Nodo* tmp = pila;
                pila = pila->siguiente;
                delete tmp;
            }

            while (colaF) {
                insertarLista(aux2, colaF->dato);
                Nodo* tmp = colaF;
                colaF = colaF->siguiente;
                delete tmp;
            }

            cout << "Lista desde pila: "; mostrarLista(aux1);
            cout << "Lista desde cola: "; mostrarLista(aux2);

            liberarBST(bst);
            bst = NULL;

            for (Nodo* t = aux1; t; t = t->siguiente)
                bst = insertar(bst, t->dato);

            for (Nodo* t = aux2; t; t = t->siguiente)
                bst = insertar(bst, t->dato);

            cout << "BST reconstruido (InOrden): ";
            inOrden(bst);
            cout << endl;
            break;

        }

    } while (op != 0);

    liberarLista(pila);
    liberarLista(colaF);
    liberarLista(negativos);
    liberarLista(aux1);
    liberarLista(aux2);
    liberarHistorial(histHead);
    liberarBST(bst);

    return 0;
}