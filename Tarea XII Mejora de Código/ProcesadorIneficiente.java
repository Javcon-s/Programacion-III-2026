package com.mycompany.main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class ProcesadorIneficiente {

    public static void procesarArchivo(String ruta) {

        List<String> tipos = new ArrayList<>();
        List<Integer> conteos = new ArrayList<>();

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

                int index = tipos.indexOf(tipo);

                if (index == -1) {
                    tipos.add(tipo);
                    conteos.add(1);
                } else {
                    conteos.set(index, conteos.get(index) + 1);
                }
            }

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        long fin = System.currentTimeMillis();

        System.out.println("\nINEFICIENTE:");
        for (int i = 0; i < tipos.size(); i++) {
            System.out.println(tipos.get(i) + ": " + conteos.get(i));
        }

        System.out.println("Tiempo: " + (fin - inicio) + " ms");
    }
}