package com.benchmark;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class ResultWriter {

    public static void escribir(
            String ruta,
            List<BenchmarkService.BenchmarkResult> resultados
    ) throws IOException {

        BufferedWriter bw = new BufferedWriter(
                new FileWriter(ruta)
        );


        bw.write("language,operation,structure,records,time_ms");
        bw.newLine();

        for (BenchmarkService.BenchmarkResult r : resultados) {
            String linea = String.format(
                    "%s,%s,%s,%d,%.2f",
                    r.language,
                    r.operation,
                    r.structure,
                    r.records,
                    r.timeMs
            );
            bw.write(linea);
            bw.newLine();
        }

        bw.close();
    }
}