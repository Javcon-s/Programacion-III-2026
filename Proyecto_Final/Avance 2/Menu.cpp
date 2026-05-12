//
// Created by javie on 11/05/2026.
//

//
// Created by javie on 11/05/2026.
//

#include <iostream>
#include "Menu.h"
#include "AVL.h"
#include "CargadorCSV.h"

using namespace std;

void mostrarMenu(Student*& raiz, TablaHash& tabla) {
    int opcion;

    do {

        cout << endl;
        cout << "---------- Esteban Alarcon ---------------" << endl;
        cout << "---------- RED SOCIAL ACADEMICA ----------" << endl<< endl;
        cout << "1. Cargar estudiantes desde CSV" << endl;
        cout << "2. Registrar estudiante manualmente" << endl;
        cout << "3. Buscar estudiante por ID" << endl;
        cout << "4. Eliminar estudiante" << endl;
        cout << "5. Agregar proyecto a estudiante" << endl;
        cout << "6. Mostrar proyectos de estudiante" << endl;
        cout << "7. Conectar estudiantes" << endl;
        cout << "8. Verificar si dos estudiantes estan conectados" << endl;
        cout << "9. Mostrar conexiones de estudiante" << endl;
        cout << "10. Recorrer red con BFS" << endl;
        cout << "11. Recorrer red con DFS" << endl;
        cout << "12. Mostrar ranking academico" << endl;
        cout << "13. Mostrar estadisticas de estructuras" << endl;
        cout << "14. Generar benchmark C++" << endl;
        cout << "15. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;


        switch(opcion) {

            case 1: {

                cargarCSV(raiz, tabla);

                break;
            }

            case 2: {

                int id;
                string nombre;
                string carrera;
                int semestre;
                float gpa;
                int skill;

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
                cin >> skill;

                raiz = insertar(
                    raiz,
                    id,
                    nombre,
                    carrera,
                    semestre,
                    gpa,
                    skill
                );

                Student* nuevo = buscarPorSkill(raiz, skill);

                tabla.insertar(nuevo);

                cout << "Estudiante agregado correctamente." << endl;

                break;
            }

            case 3: {

                int id;

                cout << "Ingrese ID a buscar: ";
                cin >> id;

                Student* encontrado = tabla.buscar(id);

                if (encontrado != NULL) {

                    cout << endl;
                    cout << "===== ESTUDIANTE ENCONTRADO =====" << endl;

                    cout << "ID: "
                         << encontrado->student_id
                         << endl;

                    cout << "Nombre: "
                         << encontrado->full_name
                         << endl;

                    cout << "Carrera: "
                         << encontrado->carrera
                         << endl;

                    cout << "Semestre: "
                         << encontrado->semester
                         << endl;

                    cout << "GPA: "
                         << encontrado->gpa
                         << endl;

                    cout << "Skill Score: "
                         << encontrado->skill_score
                         << endl;

                } else {

                    cout << "No se encontro estudiante." << endl;
                }

                break;
            }

            case 4: {

                cout << "Funcion eliminar estudiante aun no configurado." << endl;

                break;
            }

            case 5: {

                cout << "Modulo de proyectos aun no configurado." << endl;

                break;
            }

            case 6: {

                cout << "Modulo de proyectos aun no configurado." << endl;

                break;
            }

            case 7: {

                cout << "Modulo de grafo aun no configurado." << endl;

                break;
            }

            case 8: {

                cout << "Modulo de grafo aun no configurado." << endl;

                break;
            }

            case 9: {

                cout << "Modulo de grafo aun no configurado." << endl;

                break;
            }

            case 10: {

                cout << "BFS aun no configurado." << endl;

                break;
            }

            case 11: {

                cout << "DFS aun no configurado." << endl;

                break;
            }

            case 12: {

                cout << endl;
                cout << "===== RANKING ACADEMICO =====" << endl;

                inOrder(raiz);

                break;
            }

            case 13: {

                cout << endl;
                cout << "===== ESTADISTICAS =====" << endl;

                cout << "Total estudiantes: "
                     << contarNodos(raiz)
                     << endl;

                cout << "Altura AVL: "
                     << obtenerAltura(raiz)
                     << endl;

                cout << "Colisiones Hash: "
                     << tabla.obtenerColisiones()
                     << endl;

                cout << "Factor de carga: "
                     << tabla.factorCarga()
                     << endl;

                break;
            }

            case 14: {

                cout << "Benchmark aun no configurado." << endl;

                break;
            }

            case 15: {

                cout << "Saliendo..." << endl;

                break;
            }

            default: {

                cout << "Opcion invalida." << endl;
            }
        }

    } while(opcion != 15);
}