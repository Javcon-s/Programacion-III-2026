#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    string accion;
    Nodo* siguiente;
};

int main(){
    Nodo* acciones = NULL; 
    Nodo* rehacer = NULL; 
    string texto;
    char opcion = 's';
    int seleccion; 
    while(opcion == 's'){
        cout<< "\n Esteban Javier Antonio Alarcon Herrera \n"; 
		cout<< "\n MENU DE PROGRAMA \n";
        cout<<"1. Realizar accion"<<endl;
        cout<<"2. Deshacer ultima opcion (UNDO)"<<endl;
        cout<<"3. Rehacer accion (REDO)"<<endl;
        cout<<"4. Mostrar acciones actuales"<<endl;
        cout<<"5. Mostrar pila de rehacer"<<endl;
        cout<<"6. Salir"<<endl<<endl;
        cin>>seleccion;
        cin.ignore();
        if (seleccion == 1){
            cout<< "Ingrese accion: ";
            getline(cin, texto);
            Nodo* nuevo = new Nodo;
            nuevo->accion = texto;
            nuevo->siguiente = acciones;
            acciones = nuevo;
            while(rehacer != NULL){
                Nodo* temp = rehacer;
                rehacer = rehacer->siguiente;
                delete temp;
            }
            cout<<"Accion realizada."<<endl;
        } else if (seleccion == 2){
            if(acciones == NULL){
                cout<<"No hay acciones para deshacer."<<endl;
            } else{
                Nodo* temp = acciones;
                acciones = acciones->siguiente;
                temp->siguiente = rehacer;
                rehacer = temp;
                cout<<"Accion deshecha."<<endl;
            }
        } else if (seleccion == 3){
            if(rehacer == NULL){
                cout<<"No hay acciones para rehacer."<<endl;
            } else{
                Nodo* temp = rehacer;
                rehacer = rehacer->siguiente;

                temp->siguiente = acciones;
                acciones = temp;

                cout<<"Accion rehecha."<<endl;
            }
        } else if (seleccion == 4){
            if(acciones == NULL){
                cout<<"Pila vacia."<<endl;
            } else{
                Nodo* actual = acciones;
                while(actual != NULL){
                    cout<<actual->accion<<" --> ";
                    actual = actual->siguiente;
                }
                cout<<"NULL"<<endl;
            }
        } else if (seleccion == 5){
            if(rehacer == NULL){
                cout<<"Pila rehacer vacia."<<endl;
            } else{
                Nodo* actual = rehacer;
                while(actual != NULL){
                    cout<<actual->accion<<" --> ";
                    actual = actual->siguiente;
                }
                cout<<"NULL"<<endl;
            }
        } else if (seleccion == 6){
            cout << "Desea seguir trabajando? (s/n): ";
            cin >> opcion;
        }
    }
    while(acciones != NULL){
        Nodo* temp = acciones;
        acciones = acciones->siguiente;
        delete temp;
    }
    while(rehacer != NULL){
        Nodo* temp = rehacer;
        rehacer = rehacer->siguiente;
        delete temp;
    }
    return 0;
}