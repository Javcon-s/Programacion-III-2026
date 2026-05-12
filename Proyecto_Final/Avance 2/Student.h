//
// Created by javie on 10/05/2026.
//

#ifndef SRC_STUDENT_H
#define SRC_STUDENT_H

#include <string>
using namespace std;
struct Student {
    int student_id;
    string full_name;
    string carrera;
    int semester;
    float gpa;
    int skill_score;

    Student* izquierda;
    Student* derecha;
    int altura;
};

#endif //SRC_STUDENT_H