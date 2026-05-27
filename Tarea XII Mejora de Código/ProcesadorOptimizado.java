package com.mycompany.main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Map;

public class ProcesadorOptimizado {

    public static void procesarArchivo(String ruta) {

        Map<String, Integer> campanias = new HashMap<>();

        long inicio = System.currentTimeMillis();

        try (BufferedReader br = new BufferedReader(new FileReader(ruta))) {

            br.readLine();

            String linea;

            while ((linea = br.readLine()) != null) {

                String[] p = linea.split(",", 8);

                Cliente c = new Cliente(
                        Integer.parseInt(p[0]),
                        p[1],
                        Double.parseDouble(p[2]),
                        p[3],
                        p[4],
                        Integer.parseInt(p[5]),
                        Double.parseDouble(p[6]),
                        p[7]
                );

                String tipo = c.getSegmento() + "_" + c.getRegion();

                campanias.put(tipo, campanias.getOrDefault(tipo, 0) + 1);
            }

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        long fin = System.currentTimeMillis();

        System.out.println("\nOPTIMIZADO:");
        for (Map.Entry<String, Integer> e : campanias.entrySet()) {
            System.out.println(e.getKey() + ": " + e.getValue());
        }

        System.out.println("Tiempo: " + (fin - inicio) + " ms");
    }
}