#include <iostream>
#include <cstdlib>
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
	int seleccion;
	
	while(opcion == 's'){
		cout<< "\n Esteban Javier Antonio Alarcon Herrera \n";
		cout<< "\n MENU DE PROGRAMA \n";
        cout<<"1. Insertar elemento a la pila."<<endl;
        cout<<"2. Eliminar el elemento del tope."<<endl;
	    cout<<"3. Mostrar el elemento del tope."<<endl;
	    cout<<"4. Mostrar todos los elementos de la pila."<<endl;
		cout<<"5. Contar cuantos elementos hay en la pila"<<endl;
		cout<<"6. Buscar un valor dentro de la pila."<<endl;
		cout<<"7. Vaciar completamente la pila."<<endl;
		cout<<"8. Salir."<<endl<<endl;
		cin>>seleccion;
		if (seleccion == 1){
			cout<< "Ingrese un numero: ";
		    cin >> valor;
		
		    Nodo* nuevo = new Nodo;
            nuevo->dato = valor;
            nuevo->siguiente = head;
            head = nuevo;
            
		} else if (seleccion == 2){
			if(head == NULL){
				cout<<"La pila esta vacia."<<endl<<endl;
			} else{
				Nodo*temp=head;
				head = head->siguiente;
				delete temp;
				cout<<"El ultimo elemento fue eliminado."<<endl<<endl;
			}
		} else if (seleccion ==3){
			if(head == NULL){
				cout<<"La pila esta vacia."<<endl<<endl;
			} else{
				cout<<"El elemento tope de la lista es: "<<head->dato<<endl<<endl;
			}
		} else if (seleccion == 4){
			Nodo*actual = head;
			while(actual != NULL){
				cout<<actual->dato<<" --> ";
				actual = actual->siguiente;
			}
			cout<<"NULL"<<endl<<endl;
		} else if (seleccion == 5){
			int cantidad = 0;
			Nodo*actual = head;
			
			while (actual != NULL){
				cantidad++;
				actual = actual->siguiente;
			}
			cout<<"La cantidad de elementos que hay es: "<<cantidad<<endl<<endl;
		} else if (seleccion == 6){
			cout << "Ingrese el valor que desea buscar: ";
			cin>>valor;
			Nodo*actual = head;
			bool encontrado = false;
			while (actual != NULL){
				if(actual->dato == valor){
					encontrado = true;
					break;
				}
				actual = actual->siguiente;
			}
			if(encontrado){
				cout<<"Elemento encontrado"<<endl<<endl;
			} else {
				cout<<"El elemento no esta en la pila"<<endl<<endl;
			}
		} else if (seleccion == 7){
			while(head != NULL){
				Nodo*temp = head;
				head = head->siguiente;
				delete temp;
			}
			cout<<"Se vacio la pila."<<endl;
		} else if (seleccion == 8){
			cout << "Desea seguir trabajando en el programa? (s/n): ";
	        cin >> opcion;
		}
		
	
}
system("cls");
return 0;
}