
#include <iostream>
#include <algorithm>
#include "AVL.h"

using namespace std;

Student* crearNodo(
    int id,
    string nombre,
    string carrera,
    int semestre,
    float gpa,
    int skills
) {

    Student* nuevo = new Student();

    nuevo->student_id = id;
    nuevo->full_name = nombre;
    nuevo->carrera = carrera;
    nuevo->semester = semestre;
    nuevo->gpa = gpa;
    nuevo->skill_score = skills;

    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;

    nuevo->altura = 1;

    return nuevo;
}

int obtenerAltura(Student *nodo) {

    if (nodo == NULL) {
        return 0;
    }

    return nodo->altura;
}

int obtenerBalance(Student *nodo) {

    if (nodo == NULL) {
        return 0;
    }

    return obtenerAltura(nodo->izquierda)
           -
           obtenerAltura(nodo->derecha);
}

Student *rotarDerecha(Student *y) {

    Student* x = y->izquierda;

    Student* temp = x->derecha;

    x->derecha = y;

    y->izquierda = temp;

    y->altura =
        max(
            obtenerAltura(y->izquierda),
            obtenerAltura(y->derecha)
        ) + 1;

    x->altura =
        max(
            obtenerAltura(x->izquierda),
            obtenerAltura(x->derecha)
        ) + 1;

    return x;
}

Student *rotarIzquierda(Student *x) {

    Student* y = x->derecha;

    Student* temp = y->izquierda;

    y->izquierda = x;

    x->derecha = temp;

    x->altura =
        max(
            obtenerAltura(x->izquierda),
            obtenerAltura(x->derecha)
        ) + 1;

    y->altura =
        max(
            obtenerAltura(y->izquierda),
            obtenerAltura(y->derecha)
        ) + 1;

    return y;
}

Student* insertar(
    Student *nodo,
    int id,
    string nombre,
    string carrera,
    int semestre,
    float gpa,
    int skills
) {

    if (nodo == NULL) {

        return crearNodo(
            id,
            nombre,
            carrera,
            semestre,
            gpa,
            skills
        );
    }

    if (
        skills < nodo->skill_score
        ||
        (
            skills == nodo->skill_score
            &&
            id < nodo->student_id
        )
    ) {

        nodo->izquierda = insertar(
            nodo->izquierda,
            id,
            nombre,
            carrera,
            semestre,
            gpa,
            skills
        );
    }

    else if (
        skills > nodo->skill_score
        ||
        (
            skills == nodo->skill_score
            &&
            id > nodo->student_id
        )
    ) {

        nodo->derecha = insertar(
            nodo->derecha,
            id,
            nombre,
            carrera,
            semestre,
            gpa,
            skills
        );
    }

    else {

        return nodo;
    }

    nodo->altura =
        1 +
        max(
            obtenerAltura(nodo->izquierda),
            obtenerAltura(nodo->derecha)
        );

    int balance =
        obtenerBalance(nodo);

    if (
        balance > 1
        &&
        (
            skills < nodo->izquierda->skill_score
            ||
            (
                skills == nodo->izquierda->skill_score
                &&
                id < nodo->izquierda->student_id
            )
        )
    ) {

        return rotarDerecha(nodo);
    }

    if (
        balance < -1
        &&
        (
            skills > nodo->derecha->skill_score
            ||
            (
                skills == nodo->derecha->skill_score
                &&
                id > nodo->derecha->student_id
            )
        )
    ) {

        return rotarIzquierda(nodo);
    }

    if (
        balance > 1
        &&
        (
            skills > nodo->izquierda->skill_score
            ||
            (
                skills == nodo->izquierda->skill_score
                &&
                id > nodo->izquierda->student_id
            )
        )
    ) {

        nodo->izquierda =
            rotarIzquierda(
                nodo->izquierda
            );

        return rotarDerecha(nodo);
    }

    if (
        balance < -1
        &&
        (
            skills < nodo->derecha->skill_score
            ||
            (
                skills == nodo->derecha->skill_score
                &&
                id < nodo->derecha->student_id
            )
        )
    ) {

        nodo->derecha =
            rotarDerecha(
                nodo->derecha
            );

        return rotarIzquierda(nodo);
    }

    return nodo;
}

void inOrder(Student* raiz) {

    if (raiz != NULL) {

        inOrder(raiz->izquierda);

        cout << raiz->full_name
             << " -- Score: "
             << raiz->skill_score
             << endl;

        inOrder(raiz->derecha);
    }
}

void preOrder(Student* raiz) {

    if (raiz != NULL) {

        cout << raiz->full_name
             << " -- Score: "
             << raiz->skill_score
             << endl;

        preOrder(raiz->izquierda);

        preOrder(raiz->derecha);
    }
}

void postOrder(Student* raiz) {

    if (raiz != NULL) {

        postOrder(raiz->izquierda);

        postOrder(raiz->derecha);

        cout << raiz->full_name
             << " -- Score: "
             << raiz->skill_score
             << endl;
    }
}

Student* buscarPorSkill(
    Student* raiz,
    int skill
) {

    if (raiz == NULL) {
        return NULL;
    }

    if (skill == raiz->skill_score) {
        return raiz;
    }

    if (skill < raiz->skill_score) {

        return buscarPorSkill(
            raiz->izquierda,
            skill
        );
    }

    return buscarPorSkill(
        raiz->derecha,
        skill
    );
}

Student* buscarPorIDAVL(
    Student* raiz,
    int id
) {

    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->student_id == id) {
        return raiz;
    }

    Student* izquierda =
        buscarPorIDAVL(
            raiz->izquierda,
            id
        );

    if (izquierda != NULL) {
        return izquierda;
    }

    return buscarPorIDAVL(
        raiz->derecha,
        id
    );
}

Student* nodoMinimo(
    Student* nodo
) {

    Student* actual = nodo;

    while (
        actual != NULL
        &&
        actual->izquierda != NULL
    ) {

        actual = actual->izquierda;
    }

    return actual;
}

Student* eliminarStudent(
    Student* raiz,
    int skill,
    int id
) {

    if (raiz == NULL) {
        return raiz;
    }

    if (
        skill < raiz->skill_score
        ||
        (
            skill == raiz->skill_score
            &&
            id < raiz->student_id
        )
    ) {

        raiz->izquierda =
            eliminarStudent(
                raiz->izquierda,
                skill,
                id
            );
    }

    else if (
        skill > raiz->skill_score
        ||
        (
            skill == raiz->skill_score
            &&
            id > raiz->student_id
        )
    ) {

        raiz->derecha =
            eliminarStudent(
                raiz->derecha,
                skill,
                id
            );
    }

    else {

        if (
            raiz->izquierda == NULL
            ||
            raiz->derecha == NULL
        ) {

            Student* temp;

            if (raiz->izquierda != NULL) {
                temp = raiz->izquierda;
            }
            else {
                temp = raiz->derecha;
            }

            if (temp == NULL) {

                temp = raiz;
                raiz = NULL;
            }
            else {

                *raiz = *temp;
            }

            delete temp;
        }

        else {

            Student* temp =
                nodoMinimo(
                    raiz->derecha
                );

            raiz->student_id =
                temp->student_id;

            raiz->full_name =
                temp->full_name;

            raiz->carrera =
                temp->carrera;

            raiz->semester =
                temp->semester;

            raiz->gpa =
                temp->gpa;

            raiz->skill_score =
                temp->skill_score;

            raiz->derecha =
                eliminarStudent(
                    raiz->derecha,
                    temp->skill_score,
                    temp->student_id
                );
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura =
        1 +
        max(
            obtenerAltura(
                raiz->izquierda
            ),
            obtenerAltura(
                raiz->derecha
            )
        );

    int balance =
        obtenerBalance(raiz);

    if (
        balance > 1
        &&
        obtenerBalance(
            raiz->izquierda
        ) >= 0
    ) {

        return rotarDerecha(raiz);
    }

    if (
        balance > 1
        &&
        obtenerBalance(
            raiz->izquierda
        ) < 0
    ) {

        raiz->izquierda =
            rotarIzquierda(
                raiz->izquierda
            );

        return rotarDerecha(raiz);
    }

    if (
        balance < -1
        &&
        obtenerBalance(
            raiz->derecha
        ) <= 0
    ) {

        return rotarIzquierda(raiz);
    }

    if (
        balance < -1
        &&
        obtenerBalance(
            raiz->derecha
        ) > 0
    ) {

        raiz->derecha =
            rotarDerecha(
                raiz->derecha
            );

        return rotarIzquierda(raiz);
    }

    return raiz;
}

int contarNodos(Student* raiz) {

    if (raiz == NULL) {
        return 0;
    }

    return 1
           + contarNodos(raiz->izquierda)
           + contarNodos(raiz->derecha);
}