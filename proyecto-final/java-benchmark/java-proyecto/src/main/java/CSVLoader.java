package com.benchmark;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CSVLoader {

    public static List<Student> cargar(String rutaArchivo)
            throws IOException {

        List<Student> estudiantes = new ArrayList<>();

        BufferedReader br = new BufferedReader(
                new FileReader(rutaArchivo)
        );

        String linea;
        boolean primeraLinea = true;

        while ((linea = br.readLine()) != null) {


            if (primeraLinea) {
                primeraLinea = false;
                continue;
            }

            linea = linea.trim();
            if (linea.isEmpty()) continue;

            String[] partes = linea.split(",");

            if (partes.length < 6) continue;

            try {
                int    studentId  = Integer.parseInt(partes[0].trim());
                String fullName   = partes[1].trim();
                String career     = partes[2].trim();
                int    semester   = Integer.parseInt(partes[3].trim());
                double gpa        = Double.parseDouble(partes[4].trim());
                int    skillScore = Integer.parseInt(partes[5].trim());

                estudiantes.add(new Student(
                        studentId,
                        fullName,
                        career,
                        semester,
                        gpa,
                        skillScore
                ));

            } catch (NumberFormatException e) {

                System.err.println("Línea omitida: " + linea);
            }
        }

        br.close();
        return estudiantes;
    }
}