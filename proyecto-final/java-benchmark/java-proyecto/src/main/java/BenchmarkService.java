package com.benchmark;

import java.util.HashMap;
import java.util.List;
import java.util.TreeMap;
import java.util.ArrayList;

public class BenchmarkService {

    public static class BenchmarkResult {
        public String language;
        public String operation;
        public String structure;
        public int    records;
        public double timeMs;

        public BenchmarkResult(
                String language,
                String operation,
                String structure,
                int    records,
                double timeMs
        ) {
            this.language  = language;
            this.operation = operation;
            this.structure = structure;
            this.records   = records;
            this.timeMs    = timeMs;
        }
    }

    public static List<BenchmarkResult> ejecutar(
            List<Student> estudiantes
    ) {
        List<BenchmarkResult> resultados = new ArrayList<>();


        int N = 10000;
        List<Student> datos = prepararDatos(estudiantes, N);


        HashMap<Integer, Student> hashMap = new HashMap<>();

        long inicio = System.nanoTime();
        for (Student s : datos) {
            hashMap.put(s.getStudentId(), s);
        }
        long fin = System.nanoTime();
        double tiempoHashInsert = (fin - inicio) / 1_000_000.0;

        resultados.add(new BenchmarkResult(
                "Java", "insert", "HashMap", N, tiempoHashInsert
        ));


        inicio = System.nanoTime();
        for (Student s : datos) {
            hashMap.get(s.getStudentId());
        }
        fin = System.nanoTime();
        double tiempoHashSearch = (fin - inicio) / 1_000_000.0;

        resultados.add(new BenchmarkResult(
                "Java", "search", "HashMap", N, tiempoHashSearch
        ));


        TreeMap<Integer, Student> treeMap = new TreeMap<>();

        inicio = System.nanoTime();
        for (Student s : datos) {
            treeMap.put(s.getSkillScore(), s);
        }
        fin = System.nanoTime();
        double tiempoTreeInsert = (fin - inicio) / 1_000_000.0;

        resultados.add(new BenchmarkResult(
                "Java", "insert", "TreeMap", N, tiempoTreeInsert
        ));


        inicio = System.nanoTime();
        for (var entry : treeMap.entrySet()) {

            @SuppressWarnings("unused")
            Student s = entry.getValue();
        }
        fin = System.nanoTime();
        double tiempoTreeTraversal = (fin - inicio) / 1_000_000.0;

        resultados.add(new BenchmarkResult(
                "Java", "traversal", "TreeMap", N, tiempoTreeTraversal
        ));

        return resultados;
    }


    private static List<Student> prepararDatos(
            List<Student> base,
            int N
    ) {
        List<Student> datos = new ArrayList<>(base);

        int idSintetico = 900000;

        while (datos.size() < N) {
            datos.add(new Student(
                    idSintetico++,
                    "Estudiante Sintetico " + idSintetico,
                    "Ingenieria",
                    (idSintetico % 10) + 1,
                    70.0 + (idSintetico % 30),
                    idSintetico % 500
            ));
        }


        if (datos.size() > N) {
            datos = datos.subList(0, N);
        }

        return datos;
    }
}