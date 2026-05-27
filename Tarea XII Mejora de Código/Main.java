package com.mycompany.main;

public class Main {

    public static void main(String[] args) {

        String archivo = "clientes.csv";
        int cantidad = 2000000;

        System.out.println("LABORATORIO PROCESAMIENTO MASIVO");

        long t1 = System.currentTimeMillis();
        GeneradorClientes.generarArchivo(archivo, cantidad);
        long t2 = System.currentTimeMillis();

        System.out.println("Generacion: " + (t2 - t1) + " ms");

        mostrarMemoria();

        System.out.println("\nINEFICIENTE");
        ProcesadorIneficiente.procesarArchivo(archivo);

        mostrarMemoria();

        System.out.println("\nOPTIMIZADO");
        ProcesadorOptimizado.procesarArchivo(archivo);

        mostrarMemoria();
    }

    private static void mostrarMemoria() {

        Runtime r = Runtime.getRuntime();

        long used = r.totalMemory() - r.freeMemory();

        System.out.println("\nMemoria usada: " + (used / 1024 / 1024) + " MB");
    }
}