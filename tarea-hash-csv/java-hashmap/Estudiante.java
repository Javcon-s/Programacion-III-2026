/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject2;

/**
 *
 * @author javie
 */
public class Estudiante {
    
    int studentId;
    String fullName;
    String career;
    int semester;
    double gpa;
    int skillScore;

    public Estudiante(int studentId,
                       String fullName,
                       String career,
                       int semester,
                       double gpa,
                       int skillScore) {

        this.studentId = studentId;
        this.fullName = fullName;
        this.career = career;
        this.semester = semester;
        this.gpa = gpa;
        this.skillScore = skillScore;
    }

    @Override
    public String toString() {

        return "ID: " + studentId +
                "\nNombre: " + fullName +
                "\nCarrera: " + career +
                "\nSemestre: " + semester +
                "\nGPA: " + gpa +
                "\nSkill Score: " + skillScore;
    }
    
}
