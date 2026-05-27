package com.mycompany.main;

import java.io.*;
import java.util.*;

public class ProcesadorMalo {

    public static void procesarArchivo(String ruta) {

        List<String> tiposCampania = new ArrayList<>();
        List<List<Integer>> conteos = new ArrayList<>();

        long inicio = System.currentTimeMillis();

        try (BufferedReader br = new BufferedReader(new FileReader(ruta))) {

            String linea = br.readLine(); // header

            while ((linea = br.readLine()) != null) {

                String[] partes = linea.split(",", 8);

                Cliente cliente = new Cliente(
                        Integer.parseInt(partes[0]),
                        partes[1],
                        Double.parseDouble(partes[2]),
                        partes[3],
                        partes[4],
                        Integer.parseInt(partes[5]),
                        Double.parseDouble(partes[6]),
                        partes[7]
                );

                String tipo = determinarCampania(cliente);

                int index = -1;

                for (int i = 0; i < tiposCampania.size(); i++) {
                    if (tiposCampania.get(i).equals(tipo)) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    tiposCampania.add(tipo);
                    List<Integer> lista = new ArrayList<>();
                    lista.add(1);
                    conteos.add(lista);
                } else {
                    conteos.get(index).add(1);
                }
            }

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        long fin = System.currentTimeMillis();

        System.out.println("\nResumen ineficiente:");
        for (int i = 0; i < tiposCampania.size(); i++) {
            System.out.println(tiposCampania.get(i) + ": " + conteos.get(i).size());
        }

        System.out.println("Tiempo ineficiente: " + (fin - inicio) + " ms");
    }

    private static String determinarCampania(Cliente cliente) {

        return cliente.getSegmento() + "_" + cliente.getRegion();
    }
}