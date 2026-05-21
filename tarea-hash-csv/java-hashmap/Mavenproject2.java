package com.mycompany.mavenproject2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Mavenproject2 {

public static void main(String[] args) {

        System.out.println("---------- Esteban Alarcon ---------------");
        System.out.println("---------- 9941-16-13183 -----------------");
        System.out.println("---------- HashMap en Java ---------------");

        HashMap<Integer, Estudiante> estudiantes = new HashMap<>();

        String archivo = "estudiantes.csv";

        try {

            BufferedReader br = new BufferedReader(new FileReader(archivo));

            String linea;

            br.readLine();

            int cargados = 0;

            while ((linea = br.readLine()) != null) {

                String[] datos = linea.split(",");

                int studentId = Integer.parseInt(datos[0]);
                String fullName = datos[1];
                String career = datos[2];
                int semester = Integer.parseInt(datos[3]);
                double gpa = Double.parseDouble(datos[4]);
                int skillScore = Integer.parseInt(datos[5]);

                if (!estudiantes.containsKey(studentId)) {

                    Estudiante estudiante = new Estudiante(
                            studentId,
                            fullName,
                            career,
                            semester,
                            gpa,
                            skillScore
                    );

                    estudiantes.put(studentId, estudiante);

                    cargados++;
                }
            }

            br.close();

            System.out.println("\nCSV cargado correctamente.");
            System.out.println("Total de estudiantes cargados: " + cargados);

        } catch (IOException e) {

            System.out.println("Error al leer el archivo.");
        }

        Scanner sc = new Scanner(System.in);

        int opcion;

        do {

            System.out.println("\n---------- MENU ----------");
            System.out.println("1. Buscar estudiante");
            System.out.println("2. Eliminar estudiante");
            System.out.println("3. Mostrar estudiantes");
            System.out.println("4. Mostrar estadisticas");
            System.out.println("5. Salir");

            System.out.print("Seleccione una opcion: ");
            opcion = sc.nextInt();

            if (opcion == 1) {

                System.out.print("Ingrese ID del estudiante: ");
                int buscarId = sc.nextInt();

                if (estudiantes.containsKey(buscarId)) {

                    Estudiante estudiante = estudiantes.get(buscarId);

                    System.out.println("\n=== ESTUDIANTE ENCONTRADO ===");
                    System.out.println(estudiante);

                } else {

                    System.out.println("No existe estudiante.");
                }
            }

            else if (opcion == 2) {

                System.out.print("Ingrese ID a eliminar: ");
                int eliminarId = sc.nextInt();

                if (estudiantes.containsKey(eliminarId)) {

                    estudiantes.remove(eliminarId);

                    System.out.println("Estudiante eliminado.");

                } else {

                    System.out.println("No existe estudiante para eliminar.");
                }
            }

            else if (opcion == 3) {

                System.out.println("\n=== ESTUDIANTES ACTUALES ===");

                for (Integer key : estudiantes.keySet()) {

                    System.out.println("-------------------");
                    System.out.println(estudiantes.get(key));
                }
            }

            else if (opcion == 4) {

                System.out.println("\n=== ESTADISTICAS ===");
                System.out.println("Total estudiantes: " + estudiantes.size());
                System.out.println("Estructura utilizada: HashMap<Integer, Estudiante>");
            }

            else if (opcion == 5) {

                System.out.println("Saliendo del programa...");
            }

            else {

                System.out.println("Opcion no valida.");
            }

        } while (opcion != 5);

        sc.close();
    }
}
