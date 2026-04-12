#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

int main(){
	
    cout<< "\n Esteban Javier Antonio Alarcon Herrera \n"; 
    Nodo* pila = NULL;   
    Nodo* lista = NULL; 
    Nodo* frente = NULL; 
    Nodo* fin = NULL;

    int seleccion;
    int numero;
    char opcion = 's';

    while(opcion == 's'){
        cout<< "\n MENU DE PROGRAMA \n";
        cout<< "1. Ingresar numeros" << endl;
        cout<< "2. Mostrar pila (impares)" << endl;
        cout<< "3. Mostrar cola (pares)" << endl;
        cout<< "4. Mostrar lista (negativos)" << endl;
        cout<< "5. Eliminar de pila" << endl;
        cout<< "6. Eliminar de cola" << endl;
        cout<< "7. Salir" << endl << endl;

        cin>> seleccion;
        if(seleccion == 1){
            cout<< "Ingrese numero (-1 para terminar): ";
            cin>> numero;

            while(numero != -1){

                if(numero < 0){
                    Nodo* nuevo = new Nodo;
                    nuevo->dato = numero;
                    nuevo->siguiente = lista;
                    lista = nuevo;
                } else if(numero % 2 == 0){
                    Nodo* nuevo = new Nodo;
                    nuevo->dato = numero;
                    nuevo->siguiente = NULL;

                    if(frente == NULL){
                        frente = fin = nuevo;
                    } else{
                        fin->siguiente = nuevo;
                        fin = nuevo;
                    }
                } else{
                    Nodo* nuevo = new Nodo;
                    nuevo->dato = numero;
                    nuevo->siguiente = pila;
                    pila = nuevo;
                }

                cout<< "Ingrese numero (-1 para terminar): ";
                cin >> numero;
            }
        } else if(seleccion == 2){
            if(pila == NULL){
                cout << "Pila vacia." << endl;
            } else{
                Nodo* actual = pila;
                while(actual != NULL){
                    cout<< actual->dato << " -> ";
                    actual = actual->siguiente;
                }
                cout<< "NULL" << endl;
                cout<< "Tope: " << pila->dato << endl;
            }
        }else if(seleccion == 3){
            if(frente == NULL){
                cout<< "Cola vacia." << endl;
            } else{
                Nodo* actual = frente;
                while(actual != NULL){
                    cout<< actual->dato << " -> ";
                    actual = actual->siguiente;
                }
                cout<< "NULL" << endl;
                cout<< "Frente: " << frente->dato << endl;
            }
        }else if(seleccion == 4){
            if(lista == NULL){
                cout << "Lista vacia." << endl;
            } else{
                Nodo* actual = lista;
                while(actual != NULL){
                    cout<< actual->dato << " -> ";
                    actual = actual->siguiente;
                }
                cout<< "NULL" << endl;
            }
        } else if(seleccion == 5){
            if(pila == NULL){
                cout<< "Pila vacia." <<endl;
            } else{
                Nodo* temp = pila;
                pila = pila->siguiente;
                delete temp;
                cout<< "Elemento eliminado de la pila." <<endl;
            }
        } else if(seleccion == 6){
            if(frente == NULL){
                cout<< "Cola vacia." << endl;
            } else{
                Nodo* temp = frente;
                frente = frente->siguiente;
                if(frente == NULL){
                    fin = NULL;
                }
                delete temp;
                cout<< "Elemento eliminado de la cola." << endl;
            }
        } else if(seleccion == 7){
            cout<< "Desea continuar? (s/n): ";
            cin>> opcion;
        }
    }
    while(pila != NULL){
        Nodo* temp = pila;
        pila = pila->siguiente;
        delete temp;
    }
    while(lista != NULL){
        Nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
    while(frente != NULL){
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
    return 0;
}