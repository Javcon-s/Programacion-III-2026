package com.mycompany.main;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class GeneradorClientes {

    public static void generarArchivo(String ruta, int cantidad) {

        Random random = new Random();

        String[] segmentos = {"PREPAGO", "POSTPAGO", "RESIDENCIAL", "PYME", "CORPORATIVO"};
        String[] regiones = {"NORTE", "SUR", "ORIENTE", "OCCIDENTE", "CENTRO"};

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ruta))) {

            writer.write("id,nombre,ingreso,segmento,region,score,deuda,jsonData");
            writer.newLine();

            for (int i = 1; i <= cantidad; i++) {

                double ingreso = 5000 + random.nextInt(25000);
                String segmento = segmentos[random.nextInt(segmentos.length)];
                String region = regiones[random.nextInt(regiones.length)];
                int score = random.nextInt(1000);
                double deuda = random.nextInt(10000);

                String jsonData = generarJson(random);

                writer.write(i + "," +
                        "Cliente_" + i + "," +
                        ingreso + "," +
                        segmento + "," +
                        region + "," +
                        score + "," +
                        deuda + "," +
                        "\"" + jsonData.replace("\"", "'") + "\"");

                writer.newLine();
            }

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static String generarJson(Random random) {

        StringBuilder sb = new StringBuilder();
        sb.append("{");

        for (int i = 0; i < 20; i++) {
            sb.append("\"c").append(i).append("\":\"");
            for (int j = 0; j < 20; j++) {
                sb.append((char) ('a' + random.nextInt(26)));
            }
            sb.append("\",");
        }

        sb.append("\"historial\":[]}");
        return sb.toString();
    }
}