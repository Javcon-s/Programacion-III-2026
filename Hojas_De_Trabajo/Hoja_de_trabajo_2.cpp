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

int main(){
	
	Nodo* primero = NULL;
	Nodo* segundo = NULL;
	Nodo* tercero = NULL;
	
	primero = new Nodo;
	segundo = new Nodo;
	tercero = new Nodo;
	
	primero -> data.codigo = 101;
	primero -> data.nombre= "Laptop";
	primero -> data.precio = 5500.50;
	
	
	segundo -> data.codigo = 102;
	segundo -> data.nombre= "Mouse";
	segundo -> data.precio = 150.75;
	
	
	tercero -> data.codigo = 103;
	tercero -> data.nombre= "Teclado";
	tercero -> data.precio = 300.00;
	
	primero->siguiente = segundo;
	segundo->siguiente = tercero;
	tercero->siguiente = NULL;
	
	Nodo* actual= primero;
	
	while(actual!= NULL){
		cout<<"Codigo: "<<actual->data.codigo<<endl;
		cout<<"Nombre: "<<actual->data.nombre<<endl;
		cout<<"Precio: "<<actual->data.precio<<endl;
		
		actual= actual->siguiente;
	}
	
	
	
	while(actual!= NULL){
		
		Nodo* temp= actual;
		actual= actual->siguiente;
		delete temp;
	}
	primero = NULL;

	return 0;
}