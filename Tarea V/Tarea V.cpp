#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

int main(){

    Nodo* head = NULL;
    int seleccion;
    char opcion = 's';
    while(opcion == 's'){
        cout<< "\n Esteban Javier Antonio Alarcon Herrera \n"; 
        cout<< "\n MENU DE PROGRAMA \n";
        cout << "1. Insertar estudiante al inicio" << endl;
        cout << "2. Insertar estudiante al final" << endl;
        cout << "3. Mostrar estudiantes" << endl;
        cout << "4. Buscar estudiante" << endl;
        cout << "5. Eliminar estudiante" << endl;
        cout << "6. Salir" << endl << endl;
        cin >> seleccion;
        cin.ignore();

        if(seleccion == 1){
            Nodo* nuevo = new Nodo;
            cout << "Ingrese carne: ";
            cin >> nuevo->carne;
            cin.ignore();
            cout << "Ingrese nombre: ";
            getline(cin, nuevo->nombre);
            cout << "Ingrese apellido: ";
            getline(cin, nuevo->apellido);
            cout << "Ingrese carrera: ";
            getline(cin, nuevo->carrera);
            nuevo->siguiente = head;
            head = nuevo;
            cout << "Estudiante agregado al inicio." << endl;
        }

        else if(seleccion == 2){
            Nodo* nuevo = new Nodo;
            cout << "Ingrese carne: ";
            cin >> nuevo->carne;
            cin.ignore();
            cout << "Ingrese nombre: ";
            getline(cin, nuevo->nombre);
            cout << "Ingrese apellido: ";
            getline(cin, nuevo->apellido);
            cout << "Ingrese carrera: ";
            getline(cin, nuevo->carrera);
            nuevo->siguiente = NULL;
            if(head == NULL){
                head = nuevo;
            } else{
                Nodo* actual = head;
                while(actual->siguiente != NULL){
                    actual = actual->siguiente;
                }
                actual->siguiente = nuevo;
            }

            cout << "Estudiante agregado al final." << endl;
        }

        else if(seleccion == 3){
            if(head == NULL){
                cout << "Lista vacia." << endl;
            } else{
                Nodo* actual = head;
                while(actual != NULL){
                    cout << endl;
                    cout << "Carne: " << actual->carne << endl;
                    cout << "Nombre: " << actual->nombre << endl;
                    cout << "Apellido: " << actual->apellido << endl;
                    cout << "Carrera: " << actual->carrera << endl;
                    cout << "-------------------------" << endl;

                    actual = actual->siguiente;
                }
            }
        }else if(seleccion == 4){
            int buscado;
            cout << "Ingrese carne a buscar: ";
            cin >> buscado;
            Nodo* actual = head;
            bool encontrado = false;
            while(actual != NULL){
                if(actual->carne == buscado){
                    cout << endl << "Estudiante encontrado:" << endl;
                    cout << "Nombre: " << actual->nombre << endl;
                    cout << "Apellido: " << actual->apellido << endl;
                    cout << "Carrera: " << actual->carrera << endl;
                    encontrado = true;
                    break;
                }
                actual = actual->siguiente;
            }

            if(!encontrado){
                cout << "Estudiante no encontrado." << endl;
            }
        } else if(seleccion == 5){
            int buscado;
            cout << "Ingrese carne a eliminar: ";
            cin >> buscado;

            Nodo* actual = head;
            Nodo* anterior = NULL;

            while(actual != NULL && actual->carne != buscado){
                anterior = actual;
                actual = actual->siguiente;
            }

            if(actual == NULL){
                cout << "Estudiante no encontrado." << endl;
            } else{
                if(anterior == NULL){
                    head = actual->siguiente;
                } else{
                    anterior->siguiente = actual->siguiente;
                }

                delete actual;
                cout << "Estudiante eliminado." << endl;
            }
        }  else if(seleccion == 6){
            cout << "Desea continuar? (s/n): ";
            cin >> opcion;
        }
    }

    while(head != NULL){
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
    return 0;
}