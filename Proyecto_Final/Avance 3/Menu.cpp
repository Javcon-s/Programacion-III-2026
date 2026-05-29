#include <iostream>
#include "Menu.h"
#include "AVL.h"
#include "CargadorCSV.h"
#include "Projects.h"
#include "Benchmark.h"

using namespace std;

void mostrarMenu(
    Student*& raiz,
    TablaHash& tabla,
    Graph& grafo,
    Cola& cola
) {

    int opcion;

    do {

        cout << endl;
        cout << "---------- Esteban Alarcon ---------------" << endl;
        cout << "---------- RED SOCIAL ACADEMICA ----------" << endl;
        cout << endl;

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
        cout << "14. Cola de solicitudes" << endl;
        cout << "15. Generar benchmark C++" << endl;
        cout << "16. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {

                cargarCSV(
                    raiz,
                    tabla,
                    grafo
                );

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

                Student* nuevo =
                    tabla.buscar(id);

                if (nuevo == NULL) {

                    nuevo =
                        buscarPorIDAVL(
                            raiz,
                            id
                        );

                    tabla.insertar(nuevo);

                    grafo.agregarEstudiante(id);
                }

                cout << "Estudiante agregado correctamente."
                     << endl;

                break;
            }

            case 3: {

                int id;

                cout << "Ingrese ID: ";
                cin >> id;

                Student* encontrado =
                    tabla.buscar(id);

                if (encontrado != NULL) {

                    cout << endl;

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
                }
                else {

                    cout << "No encontrado."
                         << endl;
                }

                break;
            }

            case 4: {

                int id;

                cout << "Ingrese ID a eliminar: ";
                cin >> id;

                Student* estudiante =
                    tabla.buscar(id);

                if (estudiante != NULL) {

                    raiz =
                        eliminarStudent(
                            raiz,
                            estudiante->skill_score,
                            estudiante->student_id
                        );

                    tabla.eliminar(id);

                    grafo.eliminarEstudiante(id);

                    cout << "Estudiante eliminado."
                         << endl;
                }
                else {

                    cout << "No encontrado."
                         << endl;
                }

                break;
            }

            case 5: {

                int id;
                int project_id;
                int year;

                string titulo;
                string descripcion;

                cout << "ID estudiante: ";
                cin >> id;

                Student* estudiante =
                    tabla.buscar(id);

                if (estudiante == NULL) {

                    cout << "Estudiante no encontrado."
                         << endl;

                    break;
                }

                cout << "Project ID: ";
                cin >> project_id;

                cin.ignore();

                cout << "Titulo: ";
                getline(cin, titulo);

                cout << "Descripcion: ";
                getline(cin, descripcion);

                cout << "Anio: ";
                cin >> year;

                agregarProyecto(
                    estudiante,
                    project_id,
                    titulo,
                    descripcion,
                    year
                );

                break;
            }

            case 6: {

                int id;

                cout << "ID estudiante: ";
                cin >> id;

                Student* estudiante =
                    tabla.buscar(id);

                if (estudiante == NULL) {

                    cout << "No encontrado."
                         << endl;

                    break;
                }

                mostrarProyectos(estudiante);

                break;
            }

            case 7: {

                int id1;
                int id2;

                cout << "Primer ID: ";
                cin >> id1;

                cout << "Segundo ID: ";
                cin >> id2;

                cola.encolar(id1, id2);

                grafo.conectarEstudiantes(
                    id1,
                    id2
                );

                break;
            }

            case 8: {

                int id1;
                int id2;

                cout << "Primer ID: ";
                cin >> id1;

                cout << "Segundo ID: ";
                cin >> id2;

                if (
                    grafo.estanConectados(
                        id1,
                        id2
                    )
                ) {

                    cout << "SI estan conectados."
                         << endl;
                }
                else {

                    cout << "NO estan conectados."
                         << endl;
                }

                break;
            }

            case 9: {

                int id;

                cout << "Ingrese ID: ";
                cin >> id;

                grafo.mostrarConexiones(id);

                break;
            }

            case 10: {

                int id;

                cout << "Ingrese ID inicial: ";
                cin >> id;

                grafo.BFS(id);

                break;
            }

            case 11: {

                int id;

                cout << "Ingrese ID inicial: ";
                cin >> id;

                grafo.DFS(id);

                break;
            }

            case 12: {

                cout << endl;

                cout << "===== RANKING ====="
                     << endl;

                inOrder(raiz);

                break;
            }

            case 13: {

                cout << endl;

                cout << "===== ESTADISTICAS ====="
                     << endl;

                cout << "Total estudiantes: "
                     << contarNodos(raiz)
                     << endl;

                cout << "Total conexiones: "
                     << grafo.contarConexiones()
                     << endl;

                cout << "Total proyectos: "
                     << contarProyectos(raiz)
                     << endl;

                cout << "Colisiones Hash: "
                     << tabla.obtenerColisiones()
                     << endl;

                cout << "Factor carga Hash: "
                     << tabla.factorCarga()
                     << endl;

                cout << "Altura AVL: "
                     << obtenerAltura(raiz)
                     << endl;

                break;
            }

            case 14: {

                cola.mostrar();

                break;
            }

            case 15: {

                generarBenchmark(
                    raiz,
                    tabla,
                    grafo

                    );

                break;
            }

            case 16: {

                cout << "Saliendo..."
                     << endl;

                break;
            }

            default: {

                cout << "Opcion invalida."
                     << endl;
            }
        }

    } while(opcion != 16);
}