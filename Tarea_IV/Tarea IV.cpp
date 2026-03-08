#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* siguiente;
};

int main(){
	
	Nodo* head = NULL;
	Nodo* actual = NULL;
	
	int valor;
	char opcion = 's';
	int cuantos= 0;
	int suma = 0;
	double promedio = 0;
	while(opcion == 's'){
		cout<< "Ingrese un numero: ";
		cin >> valor;
		
		Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
		
		if(head == NULL) {
            head = nuevo;
            actual = nuevo;
        } else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }
        cuantos= cuantos + 1;
        suma +=valor;
		
        cout << "Desea ingresar otro numero? (s/n): ";
		cin >> opcion;
	}
	cout << "\nEsteban Javier Antonio Alarcon Herrera\n";
	cout << "\nLista creada:\n";
    Nodo* temp = head;
    while(temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
        }
    promedio = suma/cuantos;
   	cout << "NULL"<<endl;
	cout <<"Total de nodos creados: "<< cuantos<<endl;	
	cout <<"Total de valores ingresados: "<< suma<<endl;
	cout <<"Promedio de los valores: "<< promedio <<endl;
	return 0;
}
//Preguntas
//1. El puntero actual cumple la funcion de señalar el ultimo puntero con valor asignado, o en otras palabras el puntero en el que nos encontramos actualmente, hasta antes de cerrar la lista con NULL.
//2. La lista nunva llega a señalar a NULL por lo que no tiene fin y entra en bucle.
//3. Segun entiendo se van conectando de la manera en que se van creando, iniciamos primero con un nodo y preguntamos al usuario si queire seguir creando nodos, en caso que si lo desee le decimos al programa que el ultimo nodo creado señale ahora el nuevo y se repite, asi hasta que el usuario nos diga que no quiere seguir creando nodos, le indicamos al programa que entonces señale a NULL y termine la lista.
