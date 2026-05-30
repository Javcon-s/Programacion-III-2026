package com.benchmark;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.FileChooser;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class MainController {


    @FXML private TextField  txtRutaCSV;
    @FXML private Label      lblEstadoCSV;
    @FXML private TableView<Student>          tablaEstudiantes;
    @FXML private TableColumn<Student, Integer> colId;
    @FXML private TableColumn<Student, String>  colNombre;
    @FXML private TableColumn<Student, String>  colCarrera;
    @FXML private TableColumn<Student, Integer> colSemestre;
    @FXML private TableColumn<Student, Double>  colGpa;
    @FXML private TableColumn<Student, Integer> colSkill;


    @FXML private Button      btnEjecutar;
    @FXML private Button      btnGuardarCSV;
    @FXML private Label       lblEstadoBenchmark;
    @FXML private Label       lblGuardado;
    @FXML private ProgressBar progressBenchmark;
    @FXML private TableView<BenchmarkService.BenchmarkResult> tablaResultados;
    @FXML private TableColumn<BenchmarkService.BenchmarkResult, String>  colLang;
    @FXML private TableColumn<BenchmarkService.BenchmarkResult, String>  colOp;
    @FXML private TableColumn<BenchmarkService.BenchmarkResult, String>  colStruct;
    @FXML private TableColumn<BenchmarkService.BenchmarkResult, Integer> colRecords;
    @FXML private TableColumn<BenchmarkService.BenchmarkResult, Double>  colTime;


    @FXML private TextField   txtRutaCpp;
    @FXML private Label       lblEstadoGrafica;
    @FXML private BarChart<String, Number>    barChart;
    @FXML private CategoryAxis ejeX;
    @FXML private NumberAxis   ejeY;


    private List<Student>                              estudiantesCargados = new ArrayList<>();
    private List<BenchmarkService.BenchmarkResult>     resultadosBenchmark = new ArrayList<>();


    @FXML
    public void initialize() {
        configurarTablaEstudiantes();
        configurarTablaResultados();
    }

    private void configurarTablaEstudiantes() {
        colId      .setCellValueFactory(new PropertyValueFactory<>("studentId"));
        colNombre  .setCellValueFactory(new PropertyValueFactory<>("fullName"));
        colCarrera .setCellValueFactory(new PropertyValueFactory<>("career"));
        colSemestre.setCellValueFactory(new PropertyValueFactory<>("semester"));
        colGpa     .setCellValueFactory(new PropertyValueFactory<>("gpa"));
        colSkill   .setCellValueFactory(new PropertyValueFactory<>("skillScore"));


        tablaEstudiantes.setStyle(
                "-fx-background-color: #313244;" +
                        "-fx-text-fill: #cdd6f4;"
        );
    }

    private void configurarTablaResultados() {
        colLang   .setCellValueFactory(new PropertyValueFactory<>("language"));
        colOp     .setCellValueFactory(new PropertyValueFactory<>("operation"));
        colStruct .setCellValueFactory(new PropertyValueFactory<>("structure"));
        colRecords.setCellValueFactory(new PropertyValueFactory<>("records"));
        colTime   .setCellValueFactory(new PropertyValueFactory<>("timeMs"));
    }


    @FXML
    private void onBuscarCSV() {
        FileChooser fc = new FileChooser();
        fc.setTitle("Seleccionar estudiantes.csv");
        fc.getExtensionFilters().add(
                new FileChooser.ExtensionFilter("CSV Files", "*.csv")
        );
        File archivo = fc.showOpenDialog(null);
        if (archivo != null) {
            txtRutaCSV.setText(archivo.getAbsolutePath());
        }
    }

    @FXML
    private void onCargarCSV() {
        String ruta = txtRutaCSV.getText().trim();
        if (ruta.isEmpty()) {
            lblEstadoCSV.setText("⚠ Selecciona un archivo primero.");
            lblEstadoCSV.setStyle("-fx-text-fill: #f38ba8;");
            return;
        }

        try {
            estudiantesCargados = CSVLoader.cargar(ruta);

            ObservableList<Student> datos =
                    FXCollections.observableArrayList(estudiantesCargados);

            tablaEstudiantes.setItems(datos);

            lblEstadoCSV.setText(
                    "✅ Cargados " + estudiantesCargados.size() +
                            " estudiantes correctamente."
            );
            lblEstadoCSV.setStyle("-fx-text-fill: #a6e3a1;");

        } catch (Exception e) {
            lblEstadoCSV.setText("❌ Error al cargar: " + e.getMessage());
            lblEstadoCSV.setStyle("-fx-text-fill: #f38ba8;");
        }
    }


    @FXML
    private void onEjecutarBenchmark() {

        btnEjecutar.setDisable(true);
        lblEstadoBenchmark.setText("Ejecutando benchmark...");
        lblEstadoBenchmark.setStyle("-fx-text-fill: #89b4fa;");
        progressBenchmark.setProgress(-1); // indeterminado


        Task<List<BenchmarkService.BenchmarkResult>> tarea = new Task<>() {
            @Override
            protected List<BenchmarkService.BenchmarkResult> call() {
                return BenchmarkService.ejecutar(estudiantesCargados);
            }
        };

        tarea.setOnSucceeded(e -> {
            resultadosBenchmark = tarea.getValue();

            ObservableList<BenchmarkService.BenchmarkResult> datos =
                    FXCollections.observableArrayList(resultadosBenchmark);

            tablaResultados.setItems(datos);

            progressBenchmark.setProgress(1.0);
            lblEstadoBenchmark.setText("✅ Benchmark completado.");
            lblEstadoBenchmark.setStyle("-fx-text-fill: #a6e3a1;");
            btnEjecutar.setDisable(false);
            btnGuardarCSV.setDisable(false);
        });

        tarea.setOnFailed(e -> {
            progressBenchmark.setProgress(0);
            lblEstadoBenchmark.setText(
                    "❌ Error: " + tarea.getException().getMessage()
            );
            lblEstadoBenchmark.setStyle("-fx-text-fill: #f38ba8;");
            btnEjecutar.setDisable(false);
        });

        new Thread(tarea).start();
    }

    @FXML
    private void onGuardarResultados() {
        FileChooser fc = new FileChooser();
        fc.setTitle("Guardar java_results.csv");
        fc.setInitialFileName("java_results.csv");
        fc.getExtensionFilters().add(
                new FileChooser.ExtensionFilter("CSV Files", "*.csv")
        );
        File archivo = fc.showSaveDialog(null);

        if (archivo != null) {
            try {
                ResultWriter.escribir(
                        archivo.getAbsolutePath(),
                        resultadosBenchmark
                );
                lblGuardado.setText("✅ Guardado en: " + archivo.getName());
                lblGuardado.setStyle("-fx-text-fill: #a6e3a1;");
            } catch (Exception e) {
                lblGuardado.setText("❌ Error al guardar: " + e.getMessage());
                lblGuardado.setStyle("-fx-text-fill: #f38ba8;");
            }
        }
    }


    @FXML
    private void onBuscarCpp() {
        FileChooser fc = new FileChooser();
        fc.setTitle("Seleccionar cpp_results.csv");
        fc.getExtensionFilters().add(
                new FileChooser.ExtensionFilter("CSV Files", "*.csv")
        );
        File archivo = fc.showOpenDialog(null);
        if (archivo != null) {
            txtRutaCpp.setText(archivo.getAbsolutePath());
        }
    }

    @FXML
    private void onGenerarGrafica() {

        String rutaCpp  = txtRutaCpp.getText().trim();
        String rutaJava = ""; // usa resultados en memoria si existen

        if (rutaCpp.isEmpty() && resultadosBenchmark.isEmpty()) {
            lblEstadoGrafica.setText(
                    "⚠ Necesitas cargar cpp_results.csv y ejecutar el benchmark Java."
            );
            lblEstadoGrafica.setStyle("-fx-text-fill: #f38ba8;");
            return;
        }

        try {

            XYChart.Series<String, Number> serieCpp =
                    new XYChart.Series<>();
            serieCpp.setName("C++");

            if (!rutaCpp.isEmpty()) {
                List<String[]> cppData = leerCSVResultados(rutaCpp);
                for (String[] row : cppData) {
                    String etiqueta = row[1] + " " + row[2]; // op + struct
                    double tiempo   = Double.parseDouble(row[4]);
                    serieCpp.getData().add(
                            new XYChart.Data<>(etiqueta, tiempo)
                    );
                }
            }


            XYChart.Series<String, Number> serieJava =
                    new XYChart.Series<>();
            serieJava.setName("Java");

            for (BenchmarkService.BenchmarkResult r : resultadosBenchmark) {
                String etiqueta = r.operation + " " + r.structure;
                serieJava.getData().add(
                        new XYChart.Data<>(etiqueta, r.timeMs)
                );
            }

            barChart.getData().clear();

            if (!serieCpp.getData().isEmpty()) {
                barChart.getData().add(serieCpp);
            }
            if (!serieJava.getData().isEmpty()) {
                barChart.getData().add(serieJava);
            }

            barChart.setTitle("C++ vs Java — Tiempos (ms)");
            ejeX.setLabel("Operación");
            ejeY.setLabel("Tiempo (ms)");

            lblEstadoGrafica.setText("✅ Gráfica generada correctamente.");
            lblEstadoGrafica.setStyle("-fx-text-fill: #a6e3a1;");

        } catch (Exception e) {
            lblEstadoGrafica.setText("Error: " + e.getMessage());
            lblEstadoGrafica.setStyle("-fx-text-fill: #f38ba8;");
        }
    }


    private List<String[]> leerCSVResultados(String ruta) throws Exception {
        List<String[]> filas = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(ruta));
        String linea;
        boolean primera = true;
        while ((linea = br.readLine()) != null) {
            if (primera) { primera = false; continue; }
            linea = linea.trim();
            if (!linea.isEmpty()) {
                filas.add(linea.split(","));
            }
        }
        br.close();
        return filas;
    }
}