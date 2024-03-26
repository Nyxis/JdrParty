package com.jux.jdrparty;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.Cursor;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.*;


public class HelloApplication extends Application {

    private String lastOutput = "";
    @FXML
    @Override
    public void start(Stage stage)  {

        VBox mainFrame = new VBox();

        mainFrame.setSpacing(50);
        mainFrame.setAlignment(Pos.CENTER);



        Button buttonArc = new Button("Tir à l'arc");
        Button buttonEpee = new Button("Coup d'épée");
        Button buttonPoing = new Button("Coup de poing");
        Button buttonFeu = new Button("Boule de feu");

        buttonArc.cursorProperty().set(Cursor.HAND);
        buttonEpee.cursorProperty().set(Cursor.HAND);
        buttonPoing.cursorProperty().set(Cursor.HAND);
        buttonFeu.cursorProperty().set(Cursor.HAND);




        buttonArc.setOnAction(e -> launchCPP("1.1", "1.45", "0.95", () -> {

            if (lastOutput.equals("Reussite critique")) {
                buttonArc.setStyle("-fx-background-color: MediumSeaGreen");
            } else {
                if (lastOutput.equals("Reussite")) {
                    buttonArc.setStyle("-fx-background-color: Orange");
                } else {
                    if (lastOutput.equals("Echec")) {
                        buttonArc.setStyle("-fx-background-color: Red");
                    } else {
                        buttonArc.setStyle("-fx-background-color: DarkRed");
                    }
                }
            }
        }));

        buttonEpee.setOnAction(e -> launchCPP("1.2","1.25", "0.85",  () -> {
            if (lastOutput.equals("Reussite Critique")) {
                buttonEpee.setStyle("-fx-background-color: MediumSeaGreen");
            } else {
                if (lastOutput.equals("Reussite")) {
                    buttonEpee.setStyle("-fx-background-color: Orange");
                } else {
                    if (lastOutput.equals("Echec")) {
                        buttonEpee.setStyle("-fx-background-color: Red");
                    } else {
                        buttonEpee.setStyle("-fx-background-color: DarkRed");
                    }
                }
            }
        }));

        buttonPoing.setOnAction(e -> launchCPP("1","1.6", "1", () -> {
            if (lastOutput.equals("Reussite Critique")) {
                buttonPoing.setStyle("-fx-background-color: MediumSeaGreen");
            } else {
                if (lastOutput.equals("Reussite")) {
                    buttonPoing.setStyle("-fx-background-color: Orange");
                } else {
                    if (lastOutput.equals("Echec")) {
                        buttonPoing.setStyle("-fx-background-color: Red");
                    } else {
                        buttonPoing.setStyle("-fx-background-color: DarkRed");
                    }
                }
            }
        }));



        buttonFeu.setOnAction(e -> launchCPP("1.5", "1", "0.5", () -> {
            if (lastOutput.equals("Reussite Critique")) {
                buttonFeu.setStyle("-fx-background-color: MediumSeaGreen");
            } else {
                if (lastOutput.equals("Reussite")) {
                    buttonFeu.setStyle("-fx-background-color: Orange");
                } else {
                    if (lastOutput.equals("Echec")) {
                        buttonFeu.setStyle("-fx-background-color: Red");
                    } else {
                        buttonFeu.setStyle("-fx-background-color: DarkRed");
                    }
                }
            }
        }));

        mainFrame.getChildren().addAll(buttonArc, buttonEpee, buttonPoing, buttonFeu);

        Scene scene = new Scene(mainFrame, 500, 500);

        stage.setTitle("Jeu De Role de gros Nerd");
        stage.setScene(scene);
        stage.show();
        stage.onHiddenProperty();

    }

    public static void main(String[] args) {
        launch();
    }

//    private void readStreamAndStoreLastLine(InputStream inputStream, Callback callback) {
//        new Thread(() -> {
//            try (BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {
//                String line;
//                while ((line = reader.readLine()) != null) {
//                    lastOutput = line;
//                    System.out.println(lastOutput);
//                }
//                javafx.application.Platform.runLater(callback::onProcessComplete);
//
//            } catch (IOException e) {
//                e.getCause();
//            }
//        }).start();
//    }

    void launchCPP(String arg1, String arg2, String arg3,  Callback callback){
        try {
            String command = "src/main/resources/CPP/JdrExo/cmake-build-debug/JdrExo";

            ProcessBuilder cpp = new ProcessBuilder(command, arg1, arg2, arg3);

            System.out.println();
            Process process = cpp.start();
            new Thread(() -> {
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        lastOutput = line;
                        System.out.println(lastOutput);
                    }
                    javafx.application.Platform.runLater(callback::onProcessComplete);
                } catch (IOException e) {
                    e.getCause();
                }
            }).start();

        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

}