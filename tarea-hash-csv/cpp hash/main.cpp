#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Estudiante {
    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;
};

struct Nodo {
    Estudiante estudiante;
    Nodo* siguiente;
};

class HashTable {

private:

    static const int SIZE = 101;

    Nodo* tabla[SIZE];

    int totalElementos;
    int totalColisiones;

    int funcionHash(int id) {
        return id % SIZE;
    }

public:

    HashTable() {

        for (int i = 0; i < SIZE; i++) {
            tabla[i] = nullptr;
        }

        totalElementos = 0;
        totalColisiones = 0;
    }

    bool insertar(Estudiante estudiante) {

        int indice = funcionHash(estudiante.student_id);

        if (buscar(estudiante.student_id) != nullptr) {

            cout << "Error: estudiante duplicado con ID "
                 << estudiante.student_id << endl;

            return false;
        }

        Nodo* nuevo = new Nodo;

        nuevo->estudiante = estudiante;
        nuevo->siguiente = nullptr;

        if (tabla[indice] != nullptr) {
            totalColisiones++;
        }

        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;

        totalElementos++;

        return true;
    }

    Estudiante* buscar(int id) {

        int indice = funcionHash(id);

        Nodo* actual = tabla[indice];

        while (actual != nullptr) {

            if (actual->estudiante.student_id == id) {
                return &actual->estudiante;
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    bool eliminar(int id) {

        int indice = funcionHash(id);

        Nodo* actual = tabla[indice];
        Nodo* anterior = nullptr;

        while (actual != nullptr) {

            if (actual->estudiante.student_id == id) {

                if (anterior == nullptr) {
                    tabla[indice] = actual->siguiente;
                }
                else {
                    anterior->siguiente = actual->siguiente;
                }

                delete actual;

                totalElementos--;

                cout << "Estudiante eliminado.\n";

                return true;
            }

            anterior = actual;
            actual = actual->siguiente;
        }

        cout << "No se encontro estudiante con ese ID.\n";

        return false;
    }

    void cargarCSV(string nombreArchivo) {

        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {

            cout << "Error al abrir el archivo.\n";

            return;
        }

        string linea;

        getline(archivo, linea);

        int cargados = 0;

        while (getline(archivo, linea)) {

            stringstream ss(linea);

            Estudiante e;

            string temp;

            getline(ss, temp, ',');
            e.student_id = stoi(temp);

            getline(ss, e.full_name, ',');

            getline(ss, e.career, ',');

            getline(ss, temp, ',');
            e.semester = stoi(temp);

            getline(ss, temp, ',');
            e.gpa = stof(temp);

            getline(ss, temp, ',');
            e.skill_score = stoi(temp);

            if (insertar(e)) {
                cargados++;
            }
        }

        archivo.close();

        cout << "CSV cargado correctamente.\n";
        cout << "Se cargaron un total de " << cargados << " estudiantes." << endl;


    }

    void mostrarTabla() {

        cout << "\n------------ TABLA HASH -----------\n";

        for (int i = 0; i < SIZE; i++) {

            cout << "\nBucket [" << i << "] -> ";

            Nodo* actual = tabla[i];

            if (actual == nullptr) {
                cout << "VACIO";
            }

            while (actual != nullptr) {

                cout << "\n----------------------------------\n";

                cout << "ID: "
                     << actual->estudiante.student_id << endl;

                cout << "Nombre: "
                     << actual->estudiante.full_name << endl;

                cout << "Carrera: "
                     << actual->estudiante.career << endl;

                cout << "Semestre: "
                     << actual->estudiante.semester << endl;

                cout << "GPA: "
                     << actual->estudiante.gpa << endl;

                cout << "Skill Score: "
                     << actual->estudiante.skill_score << endl;

                actual = actual->siguiente;
            }

            cout << endl;
        }
    }

    void mostrarEstadisticas() {

        cout << "\n---------- ESTADISTICAS -----------\n";

        cout << "Total de estudiantes: "
             << totalElementos << endl;

        cout << "Total de buckets: "
             << SIZE << endl;

        cout << "Total de colisiones: "
             << totalColisiones << endl;

        cout << "Factor de carga: "
             << calcularFactorCarga() << endl;
    }

    float calcularFactorCarga() {

        return (float) totalElementos / SIZE;
    }

    ~HashTable() {

        for (int i = 0; i < SIZE; i++) {

            Nodo* actual = tabla[i];

            while (actual != nullptr) {

                Nodo* temp = actual;

                actual = actual->siguiente;

                delete temp;
            }
        }
    }
};

int main() {

    cout << "---------- Esteban Alarcon ---------------" << endl;
    cout << "---------- 9941-16-13183   ---------------" << endl;
    cout << "---------- Tarea Tablas Hash ---------------" << endl;

    HashTable hash;

    hash.cargarCSV("estudiantes.csv");

    int opcion;

    do {

        cout << "\n------- MENU -------\n";
        cout << "1. Buscar estudiante\n";
        cout << "2. Eliminar estudiante\n";
        cout << "3. Mostrar tabla hash\n";
        cout << "4. Mostrar estadisticas\n";
        cout << "5. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            int id;

            cout << "Ingrese ID del estudiante: ";
            cin >> id;

            Estudiante* encontrado = hash.buscar(id);

            if (encontrado != nullptr) {

                cout << "\n------- ESTUDIANTE ENCONTRADO ---------\n";

                cout << "ID: "
                     << encontrado->student_id << endl;

                cout << "Nombre: "
                     << encontrado->full_name << endl;

                cout << "Carrera: "
                     << encontrado->career << endl;

                cout << "Semestre: "
                     << encontrado->semester << endl;

                cout << "GPA: "
                     << encontrado->gpa << endl;

                cout << "Skill Score: "
                     << encontrado->skill_score << endl;
            }
            else {

                cout << "No se encontro el estudiante.\n";
            }
        }

        else if (opcion == 2) {

            int id;

            cout << "Ingrese el ID a eliminar: ";
            cin >> id;

            hash.eliminar(id);
        }

        else if (opcion == 3) {

            hash.mostrarTabla();
        }

        else if (opcion == 4) {

            hash.mostrarEstadisticas();
        }

        else if (opcion == 5) {

            cout << "Saliendo del programa\n";
        }

        else {

            cout << "Opcion no valida.\n";
        }

    } while (opcion != 5);

    return 0;
}