#include <iostream>
#include "AVL.h"
using namespace std;

int main() {
    Student* raiz = NULL;
    raiz = insertar(
        raiz,
        1001,
        "Juan Perez",
        "Ingenieria en Sistemas",
        5,
        85.50,
        120
        );
    raiz = insertar(
        raiz,
        1002,
        "Ana Lopez",
        "Ingenieria Industrial",
        7,
        91.20,
        200
        );
    raiz = insertar(
        raiz,
        1003,
        "Carlos Ruiz",
        "Ingenieria Civil",
        3,
        78.30, 95
        );

    int opcion;

    do {
        cout << "Esteban Javier Antonio Alarcon Herrera" << endl;
        cout << "1. Insertar estudiante" << endl;
        cout << "2. Mostrar ranking" << endl;
        cout << "3. Buscar por skill_score" << endl;
        cout << "4. Mostrar estadisticas AVL" << endl;
        cout << "5. Salir" << endl;

        cin >> opcion;

        switch(opcion) {

            case 1: {
                int id;
                string nombre;
                string carrera;
                int semestre;
                float gpa;
                int skills;

                cout << "ID: ";
                cin >> id;

                cin.ignore();

                cout << "Nombre completo: ";
                getline(cin, nombre);

                cout << "Carrera: ";
                getline(cin, carrera);

                cout << "Semestre: ";
                cin >> semestre;

                cout << "GPA: ";
                cin >> gpa;

                cout << "Skill score: ";
                cin >> skills;

                raiz = insertar(
                    raiz,
                    id,
                    nombre,
                    carrera,
                    semestre,
                    gpa,
                    skills
                );

                cout << "Estudiante agregado" << endl;
                cout  << endl;
                break;
            }
            case 2:
                cout << "---- RANKING ACADEMICO ----" << endl;
                inOrder(raiz);
                cout << endl;
                break;

            case 3: {
                int skill;

                cout << "Ingrese skill_score a buscar: ";
                cin >> skill;

                Student* encontrado = buscarPorSkill(raiz, skill);

                if (encontrado != NULL) {
                    cout << "---- ESTUDIANTE ENCONTRADO ----" << endl;
                    cout << "ID: " << encontrado->student_id << endl;
                    cout << "Nombre: " << encontrado->full_name << endl;
                    cout << "Carrera: " << encontrado->carrera << endl;
                    cout << "Semestre: " << encontrado->semester << endl;
                    cout << "GPA: " << encontrado->gpa << endl;
                    cout << "Skill score: " << encontrado->skill_score << endl;
                    cout << endl;
                } else {
                    cout << "No se encontro ningun estudiante con ese skill_score." << endl;
                    cout << endl;
                }

                break;
            }

            case 4:
                cout << "Altura AVL: "
                     << obtenerAltura(raiz) << endl;
                cout << endl;
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Esa no es una opcion valida." << endl;
        }

    } while(opcion != 5);


    return 0;
}